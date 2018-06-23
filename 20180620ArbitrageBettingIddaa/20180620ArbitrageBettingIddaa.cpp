// 20180620ArbitrageBettingIddaa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bet.h" 
#include <string>
#include <iostream>
#include "ConsoleColor.h"
#include "Bulletin.h"

using namespace std;


int main()
{
	try
	{
		while (true)
		{
			Bet bet;
			int length;
			string bulletinName;
			Bulletin bulletin;

			cout << "Insert the bulletin name: " << endl;
			cin >> bulletinName;
			bulletin.FillBulletin(DEFAULT_BULLETIN_FOLDER_NAME + bulletinName);

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

