#include "pch.h"
#include "../AdventOfCode2022/CalorieCounting.h"
#include "../AdventOfCode2022/CalorieCounting.cpp"
#include "../AdventOfCode2022/RockPaperScissors.h"
#include "../AdventOfCode2022/RockPaperScissors.cpp"
#include "../AdventOfCode2022/Rucksack.h"
#include "../AdventOfCode2022/Rucksack.cpp"
#include "../AdventOfCode2022/PairOverlap.cpp"

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
		int result = rockPaperScissors.calculateScoreShapePrediction(strStream);

		// assert
		EXPECT_EQ(8, result);
	}

	TEST(RocksPaperScissorsTest, HandlesThreeGames) {
		// arrange
		RockPaperScissors rockPaperScissors;
		std::string lines = "A Y\nB X\nC Z";
		std::stringstream strStream(lines);

		// act
		int result = rockPaperScissors.calculateScoreShapePrediction(strStream);

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
		int result = rockPaperScissors.calculateScoreShapePrediction(strStream);

		// assert
		EXPECT_EQ(50, result);
	}

	TEST(RocksPaperScissorsTest, PartTwoHandlesThreeGames) {
		// arrange
		RockPaperScissors rockPaperScissors;
		std::string lines = "A Y\nB X\nC Z";
		std::stringstream strStream(lines);

		// act
		int result = rockPaperScissors.calculateScoreResultPredication(strStream);

		// assert
		EXPECT_EQ(12, result);
	}
	TEST(RucksackTest, getMissingItemsTotalHandlesFiveLines) {
		// arrange
		
		std::string lines = "vJrwpWtwJgWrhcsFMMfFFhFp"
			"\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL"
			"\nPmmdzqPrVvPwwTWBwg"
			"\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn"
			"\nttgJtRGJQctTZtZT"
			"\nCrZsJsPPZsGzwwsLwLmpwMDw";
		std::stringstream strStream(lines);

		// act
		int result = Rucksack::getMissingItemsTotal(strStream);

		// assert
		EXPECT_EQ(157, result);
	}

	TEST(RucksackTest, getBadgesTotalHandlesFiveLines) {
		// arrange

		std::string lines = "vJrwpWtwJgWrhcsFMMfFFhFp"
			"\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL"
			"\nPmmdzqPrVvPwwTWBwg"
			"\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn"
			"\nttgJtRGJQctTZtZT"
			"\nCrZsJsPPZsGzwwsLwLmpwMDw";

		std::stringstream strStream(lines);

		// act
		int result = Rucksack::getBadgesTotal(strStream);

		// assert
		EXPECT_EQ(70, result);
	}

	TEST(CampCleaning, getOverlappingPairCountFull) {
		// arrange

		std::string lines = "2-4,6-8"
			"\n2 - 3, 4 - 5"
			"\n5 - 7, 7 - 9"
			"\n2 - 8, 3 - 7"
			"\n6 - 6, 4 - 6"
			"\n2 - 6, 4 - 8";

		std::stringstream strStream(lines);

		// act
		int result = getOverlappingPairCount(strStream, true);

		// assert
		EXPECT_EQ(2, result);
		}

	TEST(CampCleaning, getOverlappingPairCountPartial) {
		// arrange

		std::string lines = "2-4,6-8"
			"\n2 - 3, 4 - 5"
			"\n5 - 7, 7 - 9"
			"\n2 - 8, 3 - 7"
			"\n6 - 6, 4 - 6"
			"\n2 - 6, 4 - 8";

		std::stringstream strStream(lines);

		// act
		int result = getOverlappingPairCount(strStream, false);

		// assert
		EXPECT_EQ(4, result);
	}
}