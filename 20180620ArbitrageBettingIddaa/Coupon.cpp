#include "stdafx.h"
#include "Coupon.h"


Coupon::Coupon()
{
}

Coupon::~Coupon()
{
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
