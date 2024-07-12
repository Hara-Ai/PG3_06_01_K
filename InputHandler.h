#pragma once
#include <map>
#include "ICommand.h"

class InputHandler
{
public:
    void Initialize();
    void HandleInput(Player* player);
    void BindCommand(int key, ICommand* command);

private:
    std::map<int, ICommand*> commandMap;

    // キー入力結果を受け取る箱
    char Inputeys[256] = { 0 };
    char preKeys[256] = { 0 };
};
