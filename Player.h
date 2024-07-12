#pragma once

class Player 
{
public:
    Player();
    ~Player();
    void MoveLeft();
    void MoveRight();
    void Update();
    void Draw();

private:
    float x;
    float y;
    float speed;
};
