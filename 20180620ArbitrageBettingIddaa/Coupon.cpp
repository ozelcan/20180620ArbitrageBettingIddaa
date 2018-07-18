#include "stdafx.h"
#include "Coupon.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Definitions.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

Coupon::Coupon()
{
}

Coupon::~Coupon()
{
}

bool Coupon::WriteToFile(std::string path_of_out_file)
{
	bool ret = false;
	string str = "";

	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	char* dt = ctime(&now);
	// convert now to tm struct for UTC
	tm *gmtm = gmtime(&now);
	gmtm->tm_sec = 0;
	dt = asctime(gmtm);
	string actualPath = path_of_out_file + dt;

	actualPath.resize(actualPath.size() - 1);
	actualPath += "";
	replace(actualPath.begin(), actualPath.end(), ' ', '_');
	replace(actualPath.begin(), actualPath.end(), ':', '_');
	ofstream outfile(actualPath);

	/*if (!outfile.is_open())
	{
		return false;
	}*/

	for (size_t i = 0; i < this->game.size(); i++)
	{
		str = to_string(this->game[i].gameCode) + "-" + to_string(this->game[i].betOnGame);
		outfile << str << endl;
	}

	outfile.close();
	ret = true;
	return ret;
}

CouponGames::CouponGames()
{
}

CouponGames::~CouponGames()
{
}

CouponGames::CouponGames(Game game)
{
	this->league = game.league;
	this->matchStartTime = game.matchStartTime;
	this->minimumBetAmount = game.minimumBetAmount;
	this->gameName = game.gameName;
	this->gameCode = game.gameCode;
	this->homeWins = game.homeWins;
	this->drawGame = game.drawGame;
	this->awayWins = game.awayWins;
}
