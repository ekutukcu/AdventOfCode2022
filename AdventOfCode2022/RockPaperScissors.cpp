#include "RockPaperScissors.h"

int RockPaperScissors::calculateScore(std::istream& inputStream)
{
	char theirMove;
	char myMove;
	int score = 0;
	inputStream >> theirMove;
	inputStream >> myMove;
	int line = 0;
	while (!inputStream.eof())
	{
		if (myMove == theirMove + 23)
		{
			score += 3;
		}
		else if (theirMove == 'A' && myMove == 'Y' ||
			theirMove == 'B' && myMove == 'Z' ||
			theirMove == 'C' && myMove == 'X')
		{
			score += 6;
		}
		else
		{
			score += 0;
		}
		score += myMove - 'W';
		inputStream >> theirMove;
		inputStream >> myMove;
		line++;
	}

	return score;


}


int RockPaperScissors::calculateScore2(std::istream& inputStream)
{
	char theirMove;
	char myMove;
	int score = 0;
	inputStream >> theirMove;
	inputStream >> myMove;
	int line = 0;
	while (!inputStream.eof())
	{
		if (myMove == theirMove + 23)
		{
			score += 3;
		}
		else if (theirMove == 'A' && myMove == 'Y' ||
			theirMove == 'B' && myMove == 'Z' ||
			theirMove == 'C' && myMove == 'X')
		{
			score += 6;
		}
		else
		{
			score += 0;
		}
		score += myMove - 'W';
		inputStream >> theirMove;
		inputStream >> myMove;
		line++;
	}

	return score;


}