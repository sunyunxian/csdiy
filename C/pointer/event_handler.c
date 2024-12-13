#include <stdio.h>
#include <stdlib.h>

/*
1. 定义事件类型和事件处理函数签名：首先定义游戏中可能发生的事件类型，并且处理这些函数的签名
2. 实现事件注册和分发机制：实现一个机制，允许为不同类型的事件注册处理函数，并且在相应的事件发生时，调用对应的函数
3. 定义事件处理函数：为游戏每一个事件类型定义具体的事件处理函数
4. 在游戏中使用事件处理系统：在 main 函数中注册事件处理函数，并且模拟事件的发生来演示系统的工作流程
*/

// 定义事件类型
typedef enum {
    PLAYER_ATTACK,
    PLAYER_MOVE,
    EVENT_COUNT,    // 记录事件的总数
    // PLAYER_ATTACK,
    // PLAYER_ATTACK,
} GameEvent;

// 事件处理函数签名
typedef void (*EventHandler)(const char *player_name);

/*
事件处理函数的数组
主要目的
1. 用来储存注册事件处理函数
2. 注册后会被分发事件函数调用
*/
EventHandler eventHandlers[EVENT_COUNT];

// 注册事件处理函数
void registerEventHandler(GameEvent eventType, EventHandler handler);

// 分发事件处理函数
void dispatchEvent(GameEvent eventType, const char *player_name);

// 具体的事件处理函数
void handlePlayerAttack(const char *player_name);
void handlePlayerMove(const char *player_name);

int main(int argc, char const *argv[]) {
    // 开始注册函数
    registerEventHandler(PLAYER_ATTACK, handlePlayerAttack);
    registerEventHandler(PLAYER_MOVE, handlePlayerMove);

    // 触发分发函数
    dispatchEvent(PLAYER_ATTACK, "Hero");
    dispatchEvent(PLAYER_MOVE, "Hero");

    return 0;
}

void registerEventHandler(GameEvent eventType, EventHandler handler) {
    if (eventType < EVENT_COUNT) {
        eventHandlers[eventType] = handler;
    }
}

void dispatchEvent(GameEvent eventType, const char *player_name) {
    if (eventHandlers[eventType] != NULL) {
        eventHandlers[eventType](player_name);
    }
}

void handlePlayerAttack(const char *player_name) { printf("%s attacks\n", player_name); }
void handlePlayerMove(const char *player_name) { printf("%s move\n", player_name); }
