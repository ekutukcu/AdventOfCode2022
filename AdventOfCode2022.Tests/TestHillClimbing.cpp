#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/HillClimbing.h"

TEST(TestHillClimbing, get_shortest_path) {
	// arrange
	std::string input = "Sabqponm"
		"\nabcryxxl"
		"\naccszExk"
		"\nacctuvwj"
		"\nabdefghi";
	std::stringstream input_stream(input);

	// act
	auto path_length = get_shortest_path(input_stream);

	// assert
	EXPECT_EQ(31, path_length);
}