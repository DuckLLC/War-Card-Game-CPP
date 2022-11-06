// War.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;
int randRange(int low, int high);
void war();
void getupdates(int date, string verson, int lastsupport);

//var
int maxcards = 52;
int player1cards = 26;
int cpucards = 26;
int currentcard1 = 0;
int currentcard2 = 0;
int playerwar = 0;
int cpuwar = 0;
int warnum = 1;
string userinput = "";
int newmax = 0;
int main()
{
    getupdates(1665201600, "0.0.3", 1667188800);
    fstream Gamefile;
    Gamefile.open("Game.txt", std::ios_base::out);
    if (Gamefile.is_open()) {
        cout << "Loaded War V0.0.3" << endl;
        srand(time(NULL));

        cout << "Press 0 to start!" << endl;
        cout << "Press 1 for settings" << endl;
        cin >> userinput
        if (userinput == "1"){
            cout << "Type the number of cards you would like to be the max cards (Must be a multiple of 2)" << endl;
            cin >> newmax;
            if (newmax % 2 = 0){
                maxcards = newmax;
            }
        }
        while (player1cards < maxcards && cpucards < maxcards) {
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
            }
            else {
                if (currentcard1 == currentcard2) {
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
                }


            }
        }
        Gamefile.close();

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
    }
    if (playerwar > cpuwar) {
        cout << "Player won the war" << endl;
        player1cards = player1cards + (2 * warnum);
        cpucards = cpucards - (2 * warnum);
        warnum = 1;
        cout << "Player Cards: " << player1cards << endl;
        cout << "CPU Cards: " << cpucards << endl;
        cin.ignore();
    }
    if (playerwar == cpuwar) {
        warnum++;
        cout << "Cards were equal";
        war();
    }
}
std::string latestupatelink = "https://github.com/DuckLLC/War-Card-Game-CPP/releases";
void getupdates(int date, string verson, int lastsupport)
{
    time_t now = time(0);
    time_t lastsupported = lastsupport;
    char* lastsupports = ctime(&lastsupported);

    if (now > date) {
        cout << "You are running Verson " << verson << endl << "This verson is most likely out of date" << endl << "It will no longer be supported on: " << lastsupports << "Get the latest update at: " << latestupatelink << endl << endl;
    }
}

// https://github.com/DuckLLC/War-Card-Game-CPP/tree/V0.0.1
