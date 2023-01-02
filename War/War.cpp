// War.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include "Game.h"
#include <stdlib.h>


using namespace std;
using std::cout;
int randRange(int low, int high);
void war();
Game newgame;
//var
int player1cards = newgame.maxcards / 2;
int cpucards = newgame.maxcards / 2;
int currentcard1 = 0;
int currentcard2 = 0;
int playerwar = 0;
int cpuwar = 0;
int warnum = 1;
string userinput = "";
int main()
{
    Start:
    newgame.getupdates(1672549152, "0.0.4", 1675227552);
    newgame.homescreen();
    system("cls");
    player1cards = newgame.maxcards / 2;
    cpucards = newgame.maxcards / 2;

    fstream Gamefile;
    Gamefile.open("Game.txt", std::ios_base::out);
    if (Gamefile.is_open()) {
        cout << "Loaded War V0.0.4" << endl;
        srand(time(NULL));

        cout << "Press enter to start!" << endl;
        cin.ignore();
        cin.ignore();
        system("cls");

        while (player1cards < newgame.maxcards && cpucards < newgame.maxcards) {
            currentcard1 = randRange(1, 14);
            cout << "Your card was: " << currentcard1 << endl;
            Sleep(1000);
            currentcard2 = randRange(1, 14);
            cout << "CPU's Card was: " << currentcard2 << endl;
            Gamefile << "Players card was :" << currentcard1 << endl;
            Gamefile << "Cups card was :" << currentcard2 << endl;

            if (currentcard1 > currentcard2) {
                cout << "Player won the battle" << endl;
                player1cards = player1cards + 1;
                cpucards = cpucards - 1;

                cout << "Player has: " << player1cards << " cards" << endl;
                cout << "CPU has: " << cpucards << " cards" << endl;
                Gamefile << "Player won" << endl;
                std::cin.ignore();
                system("cls");
            }
            else {
                if (currentcard1 == currentcard2) {
                    Gamefile << "War Commences" << endl;
                    war();
                }
                else {
                    cout << "CPU Won the battle" << endl;
                    player1cards = player1cards - 1;
                    cpucards = cpucards + 1;

                    cout << "Player has: " << player1cards << " cards" << endl;
                    cout << "CPU has: " << cpucards << " cards" << endl;
                    Gamefile << "Cpu Won" << endl;
                    std::cin.ignore();
                    system("cls");
                }


            }
        }
        Gamefile.close();
        cout << "The war is over. Here are the results" << endl;
        cout << "Player had: " << player1cards << " cards" << endl;
        cout << "CPU had: " << cpucards << " cards" << endl;
    }
    else {
        cout << "Error, file did not open" << endl;
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int randRange(int low, int high)
{
    return rand() % (high - low) + low; //Gets a random number (Highest has to be 1 more than higest number disired)
}

void war()
{
    playerwar = randRange(1, 14);
    Sleep(1000);
    cpuwar = randRange(1, 14);
    cout << "Player had a: " << playerwar << endl;
    cout << "Cpu had a: " << cpuwar << endl;

    if (playerwar < cpuwar) {
        cout << "Cpu won the war" << endl;
        cpucards = cpucards + (2 * warnum);
        player1cards = player1cards - (2 * warnum);
        warnum = 1;
        cout << "Player Cards: " << player1cards << endl;
        cout << "CPU Cards: " << cpucards << endl;
        cin.ignore();
        system("cls");
    }
    if (playerwar > cpuwar) {
        cout << "Player won the war" << endl;
        player1cards = player1cards + (2 * warnum);
        cpucards = cpucards - (2 * warnum);
        warnum = 1;
        cout << "Player Cards: " << player1cards << endl;
        cout << "CPU Cards: " << cpucards << endl;
        cin.ignore();
        system("cls");
    }
    if (playerwar == cpuwar) {
        warnum++;
        cout << "Cards were equal";
        war();
    }
}


// https://github.com/DuckLLC/War-Card-Game-CPP/tree/V0.0.1
