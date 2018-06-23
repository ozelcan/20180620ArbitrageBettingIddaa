#include "stdafx.h"
#include "Bet.h"
#include <vector>
#include <iostream>
#include "ConsoleColor.h"
#include "Definitions.h"

using namespace std;
Bet::Bet()
{
	cout << "Constructor called for Bet class " << endl;
}

Bet::~Bet()
{
	cout << "Destructor called for Bet class " << endl;
}

void Bet::CalculateDistributionOnBets()
{
	exception ex;
	if (bets.size() < MIN_NUM_OF_BETS)
	{
		throw ex;	
	}

	float temp_float = 0;
	float amount_of_first_bet;

	betsInTypeOfX.push_back(1.0);		//constant for fisrt bet, itself

	for (size_t i = 1; i < bets.size(); i++)
	{
		betsInTypeOfX.push_back(bets[0] / bets[i]);		//fill betsInTypeOfX
	}

	for (size_t i = 0; i < betsInTypeOfX.size(); i++)
	{
		temp_float += betsInTypeOfX[i];
	}

	amount_of_first_bet = betAmount / temp_float;

	finalBalance = amount_of_first_bet * bets[0];

}

void Bet::PrintFinalBalance()
{
	if (finalBalance > betAmount)
	{
		cout << green << finalBalance << endl;
		cout << green << (profitRate - 1) * 100 << endl;

	}
	else
	{
		cout << red << finalBalance << endl;
		cout << red << (profitRate - 1) * 100 << endl;
	}
	cout << white << endl;

}
