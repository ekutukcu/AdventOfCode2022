#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Beacon.h"

TEST(Beacon, parse) {
	// arrange
	std::string input = "Sensor at x=2, y=18: closest beacon is at x=-2, y=15\n"
		"Sensor at x=9, y=16: closest beacon is at x=10, y=16\n"
		"Sensor at x=13, y=2: closest beacon is at x=15, y=3\n"
		"Sensor at x=12, y=14: closest beacon is at x=10, y=16\n"
		"Sensor at x=10, y=20: closest beacon is at x=10, y=16\n"
		"Sensor at x=14, y=17: closest beacon is at x=10, y=16\n"
		"Sensor at x=8, y=7: closest beacon is at x=2, y=10\n"
		"Sensor at x=2, y=0: closest beacon is at x=2, y=10\n"
		"Sensor at x=0, y=11: closest beacon is at x=2, y=10\n"
		"Sensor at x=20, y=14: closest beacon is at x=25, y=17\n"
		"Sensor at x=17, y=20: closest beacon is at x=21, y=22\n"
		"Sensor at x=16, y=7: closest beacon is at x=15, y=3\n"
		"Sensor at x=14, y=3: closest beacon is at x=15, y=3\n"
		"Sensor at x=20, y=1: closest beacon is at x=15, y=3\n";
	std::stringstream inputStream(input);

	// act
	auto beacon = beacon::Beacon::parse(inputStream);

	//assert
	EXPECT_EQ(6, beacon.beacons.size());
	EXPECT_EQ(14, beacon.sensors.size());
}

TEST(Beacon, mapDistances) {
	// arrange
	std::string input = "Sensor at x=2, y=18: closest beacon is at x=-2, y=15\n"
		"Sensor at x=9, y=16: closest beacon is at x=10, y=16\n"
		"Sensor at x=13, y=2: closest beacon is at x=15, y=3\n"
		"Sensor at x=12, y=14: closest beacon is at x=10, y=16\n"
		"Sensor at x=10, y=20: closest beacon is at x=10, y=16\n"
		"Sensor at x=14, y=17: closest beacon is at x=10, y=16\n"
		"Sensor at x=8, y=7: closest beacon is at x=2, y=10\n"
		"Sensor at x=2, y=0: closest beacon is at x=2, y=10\n"
		"Sensor at x=0, y=11: closest beacon is at x=2, y=10\n"
		"Sensor at x=20, y=14: closest beacon is at x=25, y=17\n"
		"Sensor at x=17, y=20: closest beacon is at x=21, y=22\n"
		"Sensor at x=16, y=7: closest beacon is at x=15, y=3\n"
		"Sensor at x=14, y=3: closest beacon is at x=15, y=3\n"
		"Sensor at x=20, y=1: closest beacon is at x=15, y=3\n";
	std::stringstream inputStream(input);

	// act
	auto beacon = beacon::Beacon::parse(inputStream);
	auto dists = beacon.mapDistances();
	Point sensor(8, 7);
	auto dist = dists[sensor];

	//assert
	EXPECT_EQ(9, dist);
}


TEST(Beacon, getBeaconLessPositionCount) {
	// arrange
	std::string input = "Sensor at x=2, y=18: closest beacon is at x=-2, y=15\n"
		"Sensor at x=9, y=16: closest beacon is at x=10, y=16\n"
		"Sensor at x=13, y=2: closest beacon is at x=15, y=3\n"
		"Sensor at x=12, y=14: closest beacon is at x=10, y=16\n"
		"Sensor at x=10, y=20: closest beacon is at x=10, y=16\n"
		"Sensor at x=14, y=17: closest beacon is at x=10, y=16\n"
		"Sensor at x=8, y=7: closest beacon is at x=2, y=10\n"
		"Sensor at x=2, y=0: closest beacon is at x=2, y=10\n"
		"Sensor at x=0, y=11: closest beacon is at x=2, y=10\n"
		"Sensor at x=20, y=14: closest beacon is at x=25, y=17\n"
		"Sensor at x=17, y=20: closest beacon is at x=21, y=22\n"
		"Sensor at x=16, y=7: closest beacon is at x=15, y=3\n"
		"Sensor at x=14, y=3: closest beacon is at x=15, y=3\n"
		"Sensor at x=20, y=1: closest beacon is at x=15, y=3\n";
	std::stringstream inputStream(input);

	// act
	auto beacon = beacon::Beacon::parse(inputStream);
	auto dists = beacon.mapDistances();
	int y = 10;
	auto dist = beacon.getBeaconLessPositionCount(y, dists);

	//assert
	EXPECT_EQ(26, dist);
}

TEST(Beacon, getTuningfrequency) {
	// arrange
	std::string input = "Sensor at x=2, y=18: closest beacon is at x=-2, y=15\n"
		"Sensor at x=9, y=16: closest beacon is at x=10, y=16\n"
		"Sensor at x=13, y=2: closest beacon is at x=15, y=3\n"
		"Sensor at x=12, y=14: closest beacon is at x=10, y=16\n"
		"Sensor at x=10, y=20: closest beacon is at x=10, y=16\n"
		"Sensor at x=14, y=17: closest beacon is at x=10, y=16\n"
		"Sensor at x=8, y=7: closest beacon is at x=2, y=10\n"
		"Sensor at x=2, y=0: closest beacon is at x=2, y=10\n"
		"Sensor at x=0, y=11: closest beacon is at x=2, y=10\n"
		"Sensor at x=20, y=14: closest beacon is at x=25, y=17\n"
		"Sensor at x=17, y=20: closest beacon is at x=21, y=22\n"
		"Sensor at x=16, y=7: closest beacon is at x=15, y=3\n"
		"Sensor at x=14, y=3: closest beacon is at x=15, y=3\n"
		"Sensor at x=20, y=1: closest beacon is at x=15, y=3\n";
	std::stringstream inputStream(input);

	// act
	auto beacon = beacon::Beacon::parse(inputStream);
	auto dists = beacon.mapDistances();
	auto dist = beacon.getTuningfrequency(20, 4000000, dists);

	//assert
	EXPECT_EQ(56000011, dist);
}

