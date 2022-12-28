#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Day02/RockPaperScissors.h"

TEST(RockPaperScissors, HandlesSingleGame) {
	// arrange
	RockPaperScissors rockPaperScissors;
	std::string lines = "A Y\n";
	std::stringstream strStream(lines);

	// act
	int result = rockPaperScissors.calculateScoreShapePrediction(strStream);

	// assert
	EXPECT_EQ(8, result);
}

TEST(RockPaperScissors, HandlesThreeGames) {
	// arrange
	RockPaperScissors rockPaperScissors;
	std::string lines = "A Y\nB X\nC Z";
	std::stringstream strStream(lines);

	// act
	int result = rockPaperScissors.calculateScoreShapePrediction(strStream);

	// assert
	EXPECT_EQ(15, result);
}
TEST(RockPaperScissors, HandlesEightGames) {
	// arrange
	RockPaperScissors rockPaperScissors;
	std::string lines =
		"B Z"//9
		"A X"//4
		"C X"//7
		"C X"//7
		"C Z"//6
		"C X"//7
		"C X"//7
		"A Z";//3
	std::stringstream strStream(lines);

	// act
	int result = rockPaperScissors.calculateScoreShapePrediction(strStream);

	// assert
	EXPECT_EQ(50, result);
}

TEST(RockPaperScissors, PartTwoHandlesThreeGames) {
	// arrange
	RockPaperScissors rockPaperScissors;
	std::string lines = "A Y\nB X\nC Z";
	std::stringstream strStream(lines);

	// act
	int result = rockPaperScissors.calculateScoreResultPredication(strStream);

	// assert
	EXPECT_EQ(12, result);
}