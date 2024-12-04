#include <stdio.h>
#define NAME_LEN 100

struct {
    int  number;
    char name[NAME_LEN + 1];
    int  on_hand;
} part1 = {528, "Disk drive", 10}, part2 = {914, "Printer cable", 5};

int main(int argc, char const *argv[]) {
    // 结构取值
    printf("Part1 number: %d\n", part1.number);
    // 结构成员是左值
    part1.number++;
    printf("Part1 number: %d\n", part1.number);

    // 赋值运算
    printf("Part2 number: %d\n", part2.number);
    part1 = part2;
    printf("Part1 number: %d\n", part1.number);
    printf("Part2 number: %d\n", part2.number);
    return 0;
}
