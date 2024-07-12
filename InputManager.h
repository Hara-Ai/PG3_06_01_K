#pragma once
#include <Novice.h>
#include <cstring>

class InputManager
{
public:
    static InputManager* GetInstance();  
    void Update();
    bool IsKeyPressed(int key) const;
    bool IsKeyReleased(int key) const;

private:
    InputManager(); 
    char keys[256];
    char preKeys[256];
};