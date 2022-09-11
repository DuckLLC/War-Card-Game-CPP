// War.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
int randRange(int low, int high);

int main()
{
    int maxcards = 52;
    int player1cards = 26;
    int cpucards = 26;
    int currentcard1 = 0;
    int currentcard2 = 0;
    int playerwar = 0;
    int cpuwar = 0;


    cout << "Loaded War V0.01" << endl;
    srand(time(NULL));

    while (player1cards < 52 && cpucards < 52) {
        currentcard1 = randRange(1, 14);
        cout << "Your card was: " << currentcard1 << endl;
        Sleep(1000);
        currentcard2 = randRange(1, 14);
        cout << "CPU's Card was: " << currentcard2 << endl;
       
        if (currentcard1 > currentcard2) {
            cout << "Player won the battle" << endl;
            player1cards = player1cards + 1;
            cpucards = cpucards - 1;

            cout << "Player has: " << player1cards << " cards" << endl;
            cout << "CPU has: " << cpucards << " cards" << endl;

            std::cin.ignore();
        }
        else {
            if (currentcard1 == currentcard2) {
                playerwar = randRange(1, 14);
                Sleep(1000);
                cpuwar = randRange(1, 14);

                cout << "Player pulled a " << playerwar << endl;
                cout << "CPU pulled a " << cpuwar << endl;

                if (playerwar > cpuwar) {
                    cout << "Player won the war!" << endl;
                    player1cards = player1cards + 2;
                    cpucards = cpucards - 2;

                    cout << "Player has: " << player1cards << " cards" << endl;
                    cout << "CPU has: " << cpucards << " cards" << endl;

                    std::cin.ignore();
                }
                else {
                    cout << "Cpu won the war" << endl;
                    player1cards = player1cards - 2;
                    cpucards = cpucards + 2;

                    cout << "Player has: " << player1cards << " cards" << endl;
                    cout << "CPU has: " << cpucards << " cards" << endl;

                    std::cin.ignore();
                }
            }
            else {
                cout << "CPU Won the battle" << endl;
                player1cards = player1cards - 1;
                cpucards = cpucards + 1;

                cout << "Player has: " << player1cards << " cards" << endl;
                cout << "CPU has: " << cpucards << " cards" << endl;

                std::cin.ignore();
            }
            
        }
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
    return rand() % (high - low) + low;
}