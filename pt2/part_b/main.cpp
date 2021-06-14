#include <iostream>
#include "Game.h"

int main()
{
    mtm::Game game(5, 5);
    std::cout << game << std::endl;
    auto a = mtm::Game::makeCharacter(mtm::SOLDIER, mtm::POWERLIFTERS, 100, 5, 15, 20);
    game.addCharacter(mtm::GridPoint(0,0), a);
    std::cout << game << std::endl;
    game.move(mtm::GridPoint(0,0), mtm::GridPoint(1,1));
    std::cout << game << std::endl;
    game.attack(mtm::GridPoint(1,1), mtm::GridPoint(1,0));
    std::cout << game << std::endl;
    game.reload(mtm::GridPoint(1,1));
    std::cout << game << std::endl;
    mtm::Team winningTeam;
    if (game.isOver(&winningTeam))
    {
        std::cout << "Victory to "
            << ((winningTeam == mtm::Team::CROSSFITTERS) ? "CROSSFITTERS" : "POWERLIFTERS") << "!\n";
    }

    return 0;
}