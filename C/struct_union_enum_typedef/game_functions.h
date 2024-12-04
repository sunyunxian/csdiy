#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H
#include "game_structs.h"

void creat_player(Player* player, const char* name, CharacterClass char_class);

Enemy generateEnemy(EnemyType enemy, int32_t level);

void battle(Player* player, Enemy* enemy);

void print_player_info(const Player* player);

void print_enemy_info(const Enemy* enemy);

#endif    // GAME_FUNCTIONS_H
