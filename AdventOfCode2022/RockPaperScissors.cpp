#include "RockPaperScissors.h"
#include <functional>
#include <unordered_map>

int RockPaperScissors::calculateScoreShapePrediction(std::istream& inputStream)
{
	char theirMove;
	char myMove;
	int score = 0;
	inputStream >> theirMove;
	inputStream >> myMove;

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
	}

	return score;
}


int RockPaperScissors::calculateScoreResultPredication(std::istream& inputStream)
{
	char theirMove;
	char myMove;
	int score = 0;
	inputStream >> theirMove;
	inputStream >> myMove;

	std::unordered_map<std::string, int> points_map = {
		{"AX", 3},
		{"AY", 4},
		{"AZ", 8},
		{"BX", 1},
		{"BY", 5},
		{"BZ", 9},
		{"CX", 2},
		{"CY", 6},
		{"CZ", 7}
	};

	while (!inputStream.eof())
	{
		auto index = std::string(1,theirMove);
		index.push_back(myMove);

		score += points_map[index];

		inputStream >> theirMove;
		inputStream >> myMove;
	}

	return score;


}