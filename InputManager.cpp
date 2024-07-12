#include "InputManager.h"

InputManager* InputManager::GetInstance() 
{
    static InputManager instance;  
    return &instance;
}

InputManager::InputManager() 
{
    memset(keys, 0, sizeof(keys));
    memset(preKeys, 0, sizeof(preKeys));
}

void InputManager::Update() 
{
    memcpy(preKeys, keys, sizeof(keys));
    Novice::GetHitKeyStateAll(keys);
}

bool InputManager::IsKeyPressed(int key) const 
{
    return keys[key] != 0;
}

bool InputManager::IsKeyReleased(int key) const 
{
    return preKeys[key] != 0 && keys[key] == 0;
}