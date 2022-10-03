#include "Game.h"

void Game::getupdates(int date, std::string verson, int lastsupport)
{
    time_t now = time(0);
    time_t lastsupported = lastsupport;
    char* lastsupports = ctime(&lastsupported);

    if (now > date) {
        std::cout << "You are running Verson " << verson << std::endl << "This verson is most likely out of date" << std::endl << "It will no longer be supported on: " << lastsupports << "Get the latest update at: " << Game::latestupdatelink << std::endl << std::endl;
    }
}

void States::homescreen()
{
    int userinput;
Menu:
    std::cout << "Welcome to war! \n Press 1 to play \n Press 2 for info \n";
    std::cin >> userinput;
    switch (userinput) {
    case 1:
        break;
    case 2:
        std::cout << "Created by Brady Delgadillo \n Version 0.0.3 \n \n";
        goto Menu;
    default:
        std::cout << "Invalid Input \n \n";
        goto Menu;

    }
}
