#include "InputHandler.h"
#include "InputManager.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include <dinput.h>

void InputHandler::Initialize() 
{
    // 初期化時のキーとコマンド
    BindCommand(DIK_LEFT, new MoveLeftCommand());
    BindCommand(DIK_RIGHT, new MoveRightCommand());
}

void InputHandler::HandleInput(Player* player)
{
    InputManager::GetInstance()->Update();
    for (auto& it : commandMap) 
    {
        if (InputManager::GetInstance()->IsKeyPressed(it.first))
        {
            it.second->Execute(player);
        }
    }
}

void InputHandler::BindCommand(int key, ICommand* command) 
{
    commandMap[key] = command;
}
