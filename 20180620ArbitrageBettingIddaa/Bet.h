#pragma once
#include <vector>
#include "Definitions.h"

class Bet
{
public:
	Bet();
	~Bet();
	std::vector<float> bets;
	std::vector<float> betsInTypeOfX;

	void CalculateDistributionOnBets();
	void PrintFinalBalance();
	void CalculateProfitRate() { profitRate = finalBalance / betAmount; }

private:
	const float betAmount = DEFAULT_BET_AMOUNT;
	float finalBalance;
	float profitRate;
};

