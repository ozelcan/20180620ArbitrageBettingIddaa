#pragma once

#define DEFAULT_BET_AMOUNT				1000.0
#define MIN_NUM_OF_BETS					2
#define SIZE_OF_START_TIME				5
#define START_INDEX_OF_GAME_CODE		SIZE_OF_START_TIME
#define SIZE_OF_GAME_CODE				3
#define START_OF_MINIMUM_BET_AMOUNT		START_INDEX_OF_GAME_CODE + SIZE_OF_GAME_CODE
#define SIZE_OF_MINIMUM_BET_AMOUNT		1
#define	DEFAULT_BULLETIN_PATH			"bulletins\\default_bulletin.txt"
#define MIN_NUM_OF_BETS_FOR_A_GAME		3
#define	DEFAULT_OUTPUT_COUPONS_PATH		"output_coupons\\out_coupons"

enum BetTypes
{
	HOME_WINS = 0,
	DRAW_GAME,
	AWAY_WINS
};