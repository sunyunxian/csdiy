#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // char* name[100];
    char* name;
    int   level;
    int   hp;
} Character;

Character* create_character(const char* name, int level, int hp);
void       free_character(Character* character);

int main(int argc, char const* argv[]) {
    const char* name = "foobar";
    printf("%p\n", name);
    Character* character = create_character(name, 10, 100);

    printf("%s\n", character->name);
    printf("%p\n", character->name);
    free(character);

    return 0;
}

Character* create_character(const char* name, int level, int hp) {
    Character* new_character = (Character*)malloc(sizeof(Character));

    if (!new_character) {
        printf("Fail malloc apply\n");
        // 这里的返回值是空指针，给调用方进行处理，而不是直接退出，或者在这个函数内处理
        return NULL;
    }
    // 如果结构体声明的是 char* name[100]，就不需要动态申请了，直接 copy 字符串即可
    // 但是因为是声明了一个指针，所以是不知道大小的，这个时候一定要动态申请！！！
    new_character->name = (char*)malloc(strlen(name + 1));
    // 这个是不可以的，这不是字符串赋值的方式，这里是赋值了 name 指针的地址
    // new_character->name = name;
    if (!new_character->name) {
        printf("fail malloc apply\n");
        free(new_character);
        return NULL;
    }
    // 这里可以这样使用，但是如果是数组方式的就不能这么使用了，需要检查最后一位是 '\0'
    strncpy(new_character->name, name, sizeof(name));
    new_character->level = level;
    new_character->hp = hp;

    return new_character;
}

void free_character(Character* character) {
    if (character) {
        free(character->name);
        free(character);
    }
}
