#include "stdafx.h"
#include "Bulletin.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Game.h"
#include "Definitions.h"

using namespace std;


Bulletin::Bulletin()
{
}


Bulletin::~Bulletin()
{
}

bool Bulletin::FillBulletin(std::string filename)
{
	bool ret = false;
	ifstream infile(filename);
	Game game;
	string line;

	if (!infile.is_open())
	{
		return false;
	}
	while (getline(infile, line))
	{
		if (line[0] != '*')	continue;
		else
		{
			getline(infile, line);
			game.league = line;
			getline(infile, line);
			game.matchStartTime = line.substr(0, SIZE_OF_START_TIME);
			game.gameCode = stoi(line.substr(START_INDEX_OF_GAME_CODE, SIZE_OF_GAME_CODE));
			game.minimumBetAmount = stoi(line.substr(START_OF_MINIMUM_BET_AMOUNT, SIZE_OF_MINIMUM_BET_AMOUNT));
			getline(infile, line);
			game.gameName = line;
			getline(infile, line);
			game.homeWins = stof(line);
			getline(infile, line);
			game.drawGame = stof(line);
			getline(infile, line);
			game.awayWins = stof(line);
			gameList.push_back(game);
		}
	}
	ret = true;
	infile.close();
	return ret;

}

