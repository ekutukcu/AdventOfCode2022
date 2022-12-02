#include "pch.h"
#include "../AdventOfCode2022/CalorieCounting.h"
#include "../AdventOfCode2022/CalorieCounting.cpp"
#include "../AdventOfCode2022/RockPaperScissors.h"
#include "../AdventOfCode2022/RockPaperScissors.cpp"

namespace AdventOfCode2022Tests
{
	TEST(CalorieCountingTest, HandlesTwoReindeer) {
		// arrange
		CalorieCounting calorieCounting(3);
		std::string lines = "10\n10\n\n20\n20";
		std::stringstream strStream(lines);

		// act
		int result = calorieCounting.getMaxCalories(strStream);

		// assert
		EXPECT_EQ(60, result);
	}

	TEST(CalorieCountingTest, HandlesFourReindeer) {
		// arrange
		CalorieCounting calorieCounting(3);
		std::string lines = "10\n10\n\n20\n20\n\n10\n\n20\n20\n20";
		std::stringstream strStream(lines);

		// act
		int result = calorieCounting.getMaxCalories(strStream);

		// assert
		EXPECT_EQ(120, result);
	}

	TEST(CalorieCountingTest, HandlesSingleResult) {
		// arrange
		CalorieCounting calorieCounting(1);
		std::string lines = "10\n10\n\n20\n20\n\n20\n\n20\n20\n20";
		std::stringstream strStream(lines);

		// act
		int result = calorieCounting.getMaxCalories(strStream);

		// assert
		EXPECT_EQ(60, result);
	}

	TEST(RocksPaperScissorsTest, HandlesSingleGame) {
		// arrange
		RockPaperScissors rockPaperScissors;
		std::string lines = "A Y\n";
		std::stringstream strStream(lines);

		// act
		int result = rockPaperScissors.calculateScore(strStream);

		// assert
		EXPECT_EQ(8, result);
	}

	TEST(RocksPaperScissorsTest, HandlesThreeGames) {
		// arrange
		RockPaperScissors rockPaperScissors;
		std::string lines = "A Y\nB X\nC Z";
		std::stringstream strStream(lines);

		// act
		int result = rockPaperScissors.calculateScore(strStream);

		// assert
		EXPECT_EQ(15, result);
	}
	TEST(RocksPaperScissorsTest, HandlesEightGames) {
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
		int result = rockPaperScissors.calculateScore(strStream);

		// assert
		EXPECT_EQ(50, result);
	}
}