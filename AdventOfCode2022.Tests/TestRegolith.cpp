#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Day14/Regolith.h"

using namespace regolith;

TEST(Regolith, readLines) {
	// arrange
	std::string input = "498,4 -> 498,6 -> 496,6\n"
		"503,4 -> 502,4 -> 502,9 -> 494,9";
	std::stringstream inputStream(input);

	// act
	auto lines = readLines(inputStream);

	// assert
	EXPECT_EQ(5, lines.size());
	EXPECT_EQ(498, lines[0].start.X);
	EXPECT_EQ(498, lines[0].end.X);
	EXPECT_EQ(4, lines[0].start.Y);
	EXPECT_EQ(6, lines[0].end.Y);


	EXPECT_EQ(502, lines[4].start.X);
	EXPECT_EQ(494, lines[4].end.X);
	EXPECT_EQ(9, lines[4].start.Y);
	EXPECT_EQ(9, lines[4].end.Y);
}

TEST(Regolith, getRestingSandCount) {
	// arrange
	std::string input = "498,4 -> 498,6 -> 496,6\n"
		"503,4 -> 502,4 -> 502,9 -> 494,9";
	std::stringstream inputStream(input);
	auto lines = readLines(inputStream);
	Point sandStart(500, 0);

	// act
	auto cnt = getRestingSandCount(sandStart, lines);
	// assert
	EXPECT_EQ(24, cnt);
}


TEST(Regolith, getRestingSandWithFloorCount) {
	// arrange
	std::string input = "498,4 -> 498,6 -> 496,6\n"
		"503,4 -> 502,4 -> 502,9 -> 494,9";
	std::stringstream inputStream(input);
	auto lines = readLines(inputStream);
	Point sandStart(500, 0);

	// act
	auto cnt = getRestingSandCount(sandStart, lines);
	// assert
	EXPECT_EQ(24, cnt);
}

TEST(Line, intersects) {
	// arrange
	std::string input = "498,4 -> 498,6";
	std::stringstream inputStream(input);
	auto line = readLines(inputStream)[0];
	Point p1(498, 4);
	Point p2(498, 5);
	Point p3(498, 6);
	Point p4(498, 7);
	Point p5(499, 5);

	// act

	// assert
	EXPECT_TRUE(line.intersects(p1));
	EXPECT_TRUE(line.intersects(p2));
	EXPECT_TRUE(line.intersects(p3));
	EXPECT_FALSE(line.intersects(p4));
	EXPECT_FALSE(line.intersects(p5));
}