#ifndef GAME_ABILITIES_H
#define GAME_ABILITIES_H

#include <stdint.h>

typedef union {
    int32_t strength;    // 战士的力量
    float   mana;        // 魔法师的魔力值
    int32_t stealth;     // 流氓的隐藏力量
} Ability;

#endif    // GAME_ABILITIES_H
