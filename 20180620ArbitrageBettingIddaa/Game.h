#pragma once
#include <string>

class Game
{
public:
	Game();
	~Game();
	std::string league;
	std::string matchStartTime;
	int minimumBetAmount;
	std::string gameName;
	int gameCode;
	float homeWins;
	float drawGame;
	float awayWins;
};

