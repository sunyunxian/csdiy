#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  id;
    char name[30];
} Player;

void update_list(Player **players, int *current_size, int new_size, Player new_player);
void print_list(Player *players, int size);

int main(int argc, char const *argv[]) {
    // 这里其实是定义了一个 Player 的数组！而不是一个结构体的指针
    // Player *players[30] 这样子声明就确定了大小了，无法动态的存储
    Player *players = NULL;
    int     current_size = 0;    // 当前玩家数量
    // 模拟玩家进入
    Player player1 = {1, "player1"};

    update_list(&players, &current_size, current_size + 1, player1);
    print_list(players, current_size);
    Player player2 = {2, "player2"};
    update_list(&players, &current_size, current_size + 1, player2);
    print_list(players, current_size);
    Player player3 = {3, "player3"};
    update_list(&players, &current_size, current_size + 1, player3);
    print_list(players, current_size);

    free(players);

    return 0;
}

void update_list(Player **players, int *current_size, int new_size, Player new_player) {
    Player *temp = realloc(*players, new_size * sizeof(Player));

    if (!temp) {
        perror("realloc fail\n");
        exit(EXIT_FAILURE);
    }

    *players = temp;
    if (new_size > *current_size) {
        (*players)[*current_size] = new_player;    // 更新新玩家
        *current_size = new_size;                  // 更新当前大小
    }
}

void print_list(Player *players, int size) {
    printf("Current Players\n");
    for (int i = 0; i < size; ++i) {
        printf("id = %d\t name = %s\n", players[i].id, players[i].name);
    }
}
