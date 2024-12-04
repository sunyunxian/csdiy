#include <stdio.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct {
    char county[50];
    char city[50];
} address;

typedef struct {
    char    name[50];
    int     age;
    address address;
} person;

int main(int argc, char const *argv[]) {
    // 两种访问形式

    // 结构体使用 . 访问成员
    point p = {1, 2};
    printf("p.x = %d, p.y = %d\n", p.x, p.y);

    // 结构体指针使用 -> 访问成员
    point *ptr = &p;
    printf("ptr->x = %d, ptr->y = %d\n", ptr->x, ptr->y);

    // 嵌套结构体

    // . 访问
    person foo = {"foo", 18, {"Three-body", "Shanghai"}};
    printf("foo: name = %s, age = %d, country = %s, city = %s\n", foo.name, foo.age, foo.address.county,
           foo.address.city);

    // -> 访问
    person *foo_ptr = &foo;
    printf("foo: name = %s, age = %d, country = %s, city = %s\n", foo_ptr->name, foo_ptr->age, foo_ptr->address.county,
           foo_ptr->address.city);
    return 0;
}
