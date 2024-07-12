#pragma once
#include "ICommand.h"

// Playerクラスの前方宣言
class Player;

class MoveLeftCommand : public ICommand 
{
public:
    void Execute(Player* player) override;
};
