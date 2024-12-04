#include "game_functions.h"
#include <stdio.h>
#include <string.h>

void creat_player(Player* player, const char* name, CharacterClass char_class) {
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0';

    player->char_class = char_class;
    player->level = 1;
    player->health = 100;

    switch (char_class) {
        case Warrior:
            player->ability.strength = 10;
            break;
        case Mage:
            player->ability.mana = 50;
            break;
        case Rogue:
            player->ability.stealth = 20;
            break;
    }
}
Enemy generateEnemy(EnemyType type, int32_t level) {
    Enemy enemy;
    enemy.type = type;
    enemy.level = level;
    enemy.health = level * 2;

    return enemy;
}

void battle(Player* player, Enemy* enemy) { printf("Start battle"); }

void print_player_info(const Player* player) { printf("name = %s\n", player->name); }

void print_enemy_info(const Enemy* enemy) { printf("name = %u\n", enemy->type); }
