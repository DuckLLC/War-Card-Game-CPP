#pragma once
#include <iostream>
#pragma warning(disable : 4996)
class Game
{
private:
	std::string latestupdatelink = "https://github.com/DuckLLC/War-Card-Game-CPP/releases";
public:
	void getupdates(int date, std::string verson, int lastsupport);
};

class States
{
public:
	void homescreen();
};