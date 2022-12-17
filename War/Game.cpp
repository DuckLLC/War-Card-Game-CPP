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

void Game::homescreen()
{
    int userinput;
Menu:
    std::cout << "Welcome to war! \n\n Press 1 to play \n Press 2 for info \n Press 3 for settings \n";
    std::cin >> userinput;
    system("cls");
    switch (userinput) {
    case 1:
        break;
    case 2:
        std::cout << "Created by Brady Delgadillo \n Version 0.0.3 \n \n";
        std::cin.ignore();
        std::cin.ignore();
        system("cls");
        goto Menu;
    case 3:
        std::cout << "Enter the new max cards (Must be mutiple of 2)" << std::endl;
        std::cin >> newmax;
        if (newmax % 2 == 0) {
            maxcards = newmax;
            system("cls");
            goto Menu;
        }
        else {
            system("cls");
            goto Menu;
        }

    default:
        std::cout << "Invalid Input \n \n";
        goto Menu;

    }
}
