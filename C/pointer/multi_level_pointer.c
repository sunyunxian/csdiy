#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int         id;
    float       price;
    const char *name;
} Product;

Product *create_product(int id, float price, const char *name);
void     print_product(Product *product);
void     free_product(Product *product);
void     get_product_name(Product **product);

int main(int argc, char const *argv[]) {
    int   i = 1;
    int  *ptr = &i;
    int **pptr = &ptr;
    printf("**pptr = %d\n", **pptr);
    printf("&ptr = %p\n", &ptr);
    printf("pptr = %p\n", pptr);

    Product *product1 = create_product(1, 2.5, "MacBook");
    print_product(product1);
    get_product_name(&product1);

    free(product1);

    return 0;
}

Product *create_product(int id, float price, const char *name) {
    // 这种写法是错误的
    // 分配到栈上了，是一个局部变量，并且没有初始化，所以是一个随机的值
    // 如果对这个未初始化的指针进行解引用会导致未定义的行为
    // 如果以上都没有错误，那么也会导致本函数调用完成后，该指针变量会被销毁
    // 这就是：悬空指针
    // main 函数其实是拿到了一个被销毁的地址，这也是一个未被定义的行为了
    // Product *product; 这是错误的定义方式，一个没有初始化的指针是一定不能被使用的！
    // 解决方法
    // 按照下面的方式，在堆里申请内存
    Product *product = (Product *)malloc(sizeof(Product));
    if (!product) {
        printf("malloc product fail\n");
        exit(EXIT_FAILURE);
    }
    char *product_name = (char *)malloc(sizeof(name));
    if (!product_name) {
        printf("malloc name fail\n");
        free(product);
        exit(EXIT_FAILURE);
    }
    strncpy(product_name, name, sizeof(name));
    product->id = id;
    product->price = price;
    product->name = product_name;

    printf("product address = %p\n", (void *)product);

    return product;
}

void print_product(Product *product) {
    printf("id = %d\t price = %.2f\t name = %s\n", product->id, product->price, product->name);
}

void free_product(Product *product) {
    printf("free\n");
    if (!product) {
        free(product->name);
        free(product);
    }
}

void get_product_name(Product **product) {
    // (*product) 解引用，也就是把 **product 转换成了 *product 一级指针，后面的操作就是正常了
    printf("%s\n", (*product)->name);
    // (**product) 2 层解引用，也就是把 **product 转成了 product 使用，也就是不是指针了！
    printf("%s\n", (**product).name);
}
