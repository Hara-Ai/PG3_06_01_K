#include "MoveRightCommand.h"
#include "Player.h"

void MoveRightCommand::Execute(Player* player) 
{
    player->MoveRight();
}
