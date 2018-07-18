// 20180620ArbitrageBettingIddaa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bet.h" 
#include <string>
#include <iostream>
#include "ConsoleColor.h"
#include "Bulletin.h"
#include "Log.h"
#include "Coupon.h"

using namespace std;

int main()
{
	static Log log;
	try
	{
		while (true)
		{
			Bet bet;
			int numOfGames;
			Bulletin bulletin;
			vector<Coupon> coupons;
			Coupon tempCoupon;

			if (!(bulletin.FillBulletin(DEFAULT_BULLETIN_PATH)))
			{
				log.WriteErrorLog("Bulletin Read Error");
			}

			for (size_t i = 0; i < bulletin.gameList.size(); i++)
			{
				float tempFloat;
				bet.bets.clear();
				bet.betsInTypeOfX.clear();

				bet.bets.push_back(bulletin.gameList[i].homeWins);
				bet.bets.push_back(bulletin.gameList[i].drawGame);
				bet.bets.push_back(bulletin.gameList[i].awayWins);

				bet.CalculateDistributionOnBets();
				bet.CalculateProfitRate();
				
				if (bet.GetProfitRate() > 1.0f)
				{
					CouponGames tempCouponGame(bulletin.gameList[i]);
					
					tempCouponGame.betOnGame = HOME_WINS;
					tempCoupon.game.push_back(tempCouponGame);
					coupons.push_back(tempCoupon);

					tempCouponGame.betOnGame = DRAW_GAME;
					tempCoupon.game.push_back(tempCouponGame);
					coupons.push_back(tempCoupon);

					tempCouponGame.betOnGame = AWAY_WINS;
					tempCoupon.game.push_back(tempCouponGame);
					coupons.push_back(tempCoupon);
				}
			}

			cout << "Coupons Found: " << coupons.size() << endl;
		}
	}
	catch (std::exception ex)
	{
		cout << "Exeption: " << ex.what() << endl;
	}
	
    return 0;
}

