#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/RopeBridge.h"

TEST(RopeBridge, getVisitedPointCount) {
	// arrange
	std::string lines = "R 4"
		"\nU 4"
		"\nL 3"
		"\nD 1"
		"\nR 4"
		"\nD 1"
		"\nL 5"
		"\nR 2";
	std::stringstream strStream(lines);

	// act
	auto pointsVisited = getVisitedPointCount(strStream, 2);

	// assert
	EXPECT_EQ(13, pointsVisited);
}

TEST(RopeBridge, getVisitedPointCountManyPoint) {
	// arrange
	std::string lines = "R 4"
		"\nU 4"
		"\nL 3"
		"\nD 1"
		"\nR 4"
		"\nD 1"
		"\nL 5"
		"\nR 2";
	std::stringstream strStream(lines);

	// act
	auto pointsVisited = getVisitedPointCount(strStream, 10);

	// assert
	EXPECT_EQ(1, pointsVisited);
}

TEST(RopeBridge, getVisitedPointCountManyPoint2) {
	// arrange
	std::string lines = "R 5"
		"\nU 8"
		"\nL 8"
		"\nD 3"
		"\nR 17"
		"\nD 10"
		"\nL 25"
		"\nU 20";
	std::stringstream strStream(lines);

	// act
	auto pointsVisited = getVisitedPointCount(strStream, 10);

	// assert
	EXPECT_EQ(36, pointsVisited);
}