#include "game_functions.h"
#include "game_structs.h"

#include <stdio.h>

int main(int argc, char const *argv[]) {
    Player player;
    creat_player(&player, "tester", Warrior);
    print_player_info(&player);

    return 0;
}
