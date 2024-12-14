#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEMS       100

typedef struct item {
    int   id;
    char  name[MAX_NAME_LENGTH];
    int   quantity;
    float price;
} Item;

void print_inventory(const Item inventory[], const int item_count);
int  add_item(Item inventory[], int *item_count, int id, const char *name, int quantity, float price);
int  update_quantity(Item inventory[], int item_count, int id, int new_quantity);

int main(int argc, char const *argv[]) {
    Item inventory[MAX_ITEMS];
    int  item_count = 0;
    print_inventory(inventory, item_count);
    // 添加 3 个数据
    add_item(inventory, &item_count, 1, "a", 10, 1.0);
    add_item(inventory, &item_count, 2, "b", 20, 2.0);
    add_item(inventory, &item_count, 3, "c", 30, 3.0);
    print_inventory(inventory, item_count);
    // 更新一个存在的数据
    update_quantity(inventory, item_count, 2, 1000);
    print_inventory(inventory, item_count);
    // 插入一个不存在的数据
    update_quantity(inventory, item_count, 20, 1000);
    print_inventory(inventory, item_count);

    return 0;
}

void print_inventory(const Item inventory[], const int item_count) {
    if (item_count == 0) {
        printf("Empty inventory\n");
    }
    for (size_t i = 0; i < item_count; i++) {
        printf("inventory[%zu]: id = %d name = %s quantity = %d price = %.2f\n", i, inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

int add_item(Item inventory[], int *item_count, int id, const char *name, int quantity, float price) {
    inventory[*item_count].id = id;
    strncpy(inventory[*item_count].name, name,
            MAX_NAME_LENGTH - 1);    // 最多复制 sizeof(arr1) - 1 个字符，留 1 个位置给字符串结束符
    inventory[*item_count].quantity = quantity;
    inventory[*item_count].price = price;
    // 增加计数器
    *item_count += 1;

    return 0;
}

int update_quantity(Item inventory[], int item_count, int id, int new_quantity) {
    for (size_t i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity = new_quantity;
            return 0;
        }
    }

    printf("Not found %d\n", id);
    return 1;
}
