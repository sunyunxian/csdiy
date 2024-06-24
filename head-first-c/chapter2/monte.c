#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 如果使用指针声明一个字符串，那么这个字符串就是不能被修改的，也就是不可变的
    // char *cards = "JQK";
    char cards[] = "JQK";
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);
    return 0;
}
