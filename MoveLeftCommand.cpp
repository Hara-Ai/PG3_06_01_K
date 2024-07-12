#include "MoveLeftCommand.h"
#include "Player.h"

void MoveLeftCommand::Execute(Player* player) 
{
    player->MoveLeft();
}
