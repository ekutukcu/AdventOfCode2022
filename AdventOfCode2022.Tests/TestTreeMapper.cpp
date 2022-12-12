#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/TreeMapper.h"

TEST(TreeMapper, getScenicScore) {
	// arrange
	std::string lines = "30373"
		"\n25512"
		"\n65332"
		"\n33549"
		"\n35390";
	std::stringstream strStream(lines);
	auto map = getMap(strStream);

	// act
	auto treeCount = getScenicScore(2, 3, map);

	// assert
	EXPECT_EQ(8, treeCount);
}

TEST(TreeMapper, getBestScenicScore) {
	// arrange
	std::string lines = "30373"
		"\n25512"
		"\n65332"
		"\n33549"
		"\n35390";
	std::stringstream strStream(lines);

	// act
	auto treeCount = getBestScenicScore(strStream);

	// assert
	EXPECT_EQ(8, treeCount);
}

TEST(TreeMapper, get_visible_tree_count) {
	// arrange
	std::string lines = "30373"
		"\n25512"
		"\n65332"
		"\n33549"
		"\n35390";
	std::stringstream strStream(lines);

	// act
	auto treeCount = get_visible_tree_count(strStream);

	// assert
	EXPECT_EQ(21, treeCount);
}

TEST(TreeMapper, getMap) {
	// arrange
	std::string lines = "30373"
		"\n25512"
		"\n65332"
		"\n33549"
		"\n35390";
	std::stringstream strStream(lines);

	// act
	auto treeMap = getMap(strStream);

	// assert
	EXPECT_EQ(3, treeMap[0][0]);
	EXPECT_EQ(0, treeMap[0][1]);
	EXPECT_EQ(3, treeMap[0][2]);
}