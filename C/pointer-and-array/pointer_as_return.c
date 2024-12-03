#include <stdio.h>
#include <stdlib.h>

int *creat_int(int value);
void update_score(int *score, int points);
int *compare_score(int *player1, int *player2);

int main(int argc, char const *argv[]) {
    // create int
    int *my_int = creat_int(10);

    if (my_int != NULL) {
        printf("Value = %d\n", *my_int);
        free(my_int);
    }

    // update score
    int player1_score = 100, player2_score = 150;
    update_score(&player1_score, 100);
    printf("player1 score = %d\n", player1_score);

    // compare score
    int *higher_score = compare_score(&player1_score, &player2_score);
    printf("higher_score = %d\n", *higher_score);

    return 0;
}

int *creat_int(int value) {
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    *p = value;
    return p;
}
void update_score(int *score, int points) { *score += points; }
int *compare_score(int *player1, int *player2) {
    // 最好是直接返回就好了，避免重新申请内存
    return (*player1 > *player2) ? player1 : player2;
}
