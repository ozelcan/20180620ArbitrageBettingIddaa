#pragma once
#include <vector>
#include "Game.h"
#include "Definitions.h"

class CouponGames: public Game
{
public:
	CouponGames();
	~CouponGames();
	BetTypes betOnGame;

private:

};



class Coupon
{
public:
	Coupon();
	~Coupon();

	std::vector<CouponGames> game;
	float betAmountOfCoupon;
};

