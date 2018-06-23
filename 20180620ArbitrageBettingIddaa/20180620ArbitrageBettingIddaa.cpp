// 20180620ArbitrageBettingIddaa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bet.h" 
#include <iostream>
#include "ConsoleColor.h"

using namespace std;


int main()
{
	try
	{
		while (true)
		{
			Bet bet;
			int length;

			cout << "Insert the number of bets: " << endl;
			cin >> length;


			for (size_t i = 0; i < length; i++)
			{
				float tempFloat;

				cout << "Insert the " << i << "th bet: " << endl;
				cin >> tempFloat;
				bet.bets.push_back(tempFloat);
			}

			bet.CalculateDistributionOnBets();
			bet.CalculateProfitRate();

			bet.PrintFinalBalance();
		}
	}
	catch (std::exception ex)
	{
		cout << "Exeption: " << ex.what() << endl;
	}
	
    return 0;
}

