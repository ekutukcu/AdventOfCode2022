#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Day04/PairOverlap.h"


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