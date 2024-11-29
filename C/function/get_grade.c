#include <stdint.h>
#include <stdio.h>

#define GRADE_COUNT 11

char get_grade(u_int8_t score);

int main(int argc, char const *argv[]) {
    uint8_t score;

    printf("请输入成绩：\n");
    scanf("%d", &score);
    char grade = get_grade(score);
    printf("等级是 %c\n", grade);

    return 0;
}

char get_grade(u_int8_t score) {
    if (score < 0) return 'x';

    const char GRADE[GRADE_COUNT] = {'F', 'F', 'F', 'F', 'F', 'E', 'D', 'C ', 'B', 'A', 'A'};

    return GRADE[score / 10];
}
