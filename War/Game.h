#pragma once
#include <iostream>
#include <stdlib.h>

#pragma warning(disable : 4996)
class Game
{
private:
	std::string latestupdatelink = "https://github.com/DuckLLC/War-Card-Game-CPP/releases";
public:
	int maxcards = 52;
	int newmax = 0;
	void getupdates(int date, std::string verson, int lastsupport);
	void homescreen();
};
