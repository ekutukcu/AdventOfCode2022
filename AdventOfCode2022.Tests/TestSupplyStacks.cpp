#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Day05/SupplyStacks.h"

TEST(SupplyStacks, getTopCratesIndividually) {
	// arrange

	std::string lines = "    [D]    "
		"\n[N] [C]    "
		"\n[Z] [M] [P]"
		"\n 1   2   3"
		"\n"
		"\nmove 1 from 2 to 1"
		"\nmove 3 from 1 to 3"
		"\nmove 2 from 2 to 1"
		"\nmove 1 from 1 to 2";

	std::stringstream strStream(lines);

	// act
	auto result = getTopCrates(strStream, 3);

	// assert
	EXPECT_EQ("CMZ", result);
}


TEST(SupplyStacks, getTopCratesMultiple) {
	// arrange

	std::string lines = "    [D]    "
		"\n[N] [C]    "
		"\n[Z] [M] [P]"
		"\n 1   2   3"
		"\n"
		"\nmove 1 from 2 to 1"
		"\nmove 3 from 1 to 3"
		"\nmove 2 from 2 to 1"
		"\nmove 1 from 1 to 2";

	std::stringstream strStream(lines);

	// act
	auto result = getTopCrates(strStream, 3, false);

	// assert
	EXPECT_EQ("MCD", result);
}
