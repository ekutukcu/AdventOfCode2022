#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Day03/Rucksack.h"


TEST(Rucksack, getMissingItemsTotalHandlesFiveLines) {
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

TEST(Rucksack, getBadgesTotalHandlesFiveLines) {
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
