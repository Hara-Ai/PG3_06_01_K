#include "Player.h"
#include "Novice.h"

Player::Player() : x(640), y(600), speed(5.0f) {}

Player::~Player()
{

}

void Player::MoveLeft() 
{
    x -= speed;
}

void Player::MoveRight()
{
    x += speed;
}

void Player::Update() 
{
   
}

void Player::Draw() 
{
    Novice::DrawBox((int)x, (int)y, 50, 50, 0.0f, WHITE,kFillModeSolid);
}

