#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/CalorieCounting.h"

TEST(CalorieCounting, HandlesTwoReindeer) {
	// arrange
	CalorieCounting calorieCounting(3);
	std::string lines = "10\n10\n\n20\n20";
	std::stringstream strStream(lines);

	// act
	int result = calorieCounting.getMaxCalories(strStream);

	// assert
	EXPECT_EQ(60, result);
}

TEST(CalorieCounting, HandlesFourReindeer) {
	// arrange
	CalorieCounting calorieCounting(3);
	std::string lines = "10\n10\n\n20\n20\n\n10\n\n20\n20\n20";
	std::stringstream strStream(lines);

	// act
	int result = calorieCounting.getMaxCalories(strStream);

	// assert
	EXPECT_EQ(120, result);
}

TEST(CalorieCounting, HandlesSingleResult) {
	// arrange
	CalorieCounting calorieCounting(1);
	std::string lines = "10\n10\n\n20\n20\n\n20\n\n20\n20\n20";
	std::stringstream strStream(lines);

	// act
	int result = calorieCounting.getMaxCalories(strStream);

	// assert
	EXPECT_EQ(60, result);
}
