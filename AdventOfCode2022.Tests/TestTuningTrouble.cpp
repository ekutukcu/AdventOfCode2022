#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/TuningTrouble.h"

TEST(TuningTrouble, getMarkerLocation) {
	// arrange
	std::string lines = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";

	// act
	auto result = getMarkerLocation(lines, 4);

	// assert
	EXPECT_EQ(11, result);
}
