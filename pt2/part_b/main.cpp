#include <iostream>
#include "Game.h"

int main()
{
    mtm::Game game(5, 5);
    auto a = mtm::Game::makeCharacter(mtm::SOLDIER, mtm::POWERLIFTERS, 100, 5, 15, 20);
    game.addCharacter(mtm::GridPoint(0,0), a);
    game.move(mtm::GridPoint(0,0), mtm::GridPoint(1,1));
    game.attack(mtm::GridPoint(1,1), mtm::GridPoint(1,0));
    game.reload(mtm::GridPoint(1,1));
    mtm::Team winningTeam;
    if (game.isOver(&winningTeam))
    {
        std::cout << "Victory to "
            << ((winningTeam == mtm::Team::CROSSFITTERS) ? "CROSSFITTERS" : "POWERLIFTERS") << "!\n";
    }

    return 0;
}