#pragma once
#include <vector>
#include "Game.h"

class Bulletin
{
public:
	Bulletin();
	~Bulletin();
	std::vector<Game> gameList;
	bool FillBulletin(std::string);
};

