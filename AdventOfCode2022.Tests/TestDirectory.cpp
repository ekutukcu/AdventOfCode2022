#include "pch.h"
#include "gtest/gtest.h"
#include "../AdventOfCode2022/Directory.h"


TEST(Directory, cd) {
	// arrange
	std::string lines = "$ cd /\n$ cd e";
	std::stringstream strStream(lines);

	// act
	auto rootDir = Directory::buildDirectory(strStream);
	int total = 0;
	rootDir->getSize(total);
	// assert
	EXPECT_EQ("/", rootDir->getCurrentDir());
	EXPECT_EQ(0, total);
}

TEST(Directory, multipleLines) {
	// arrange
	std::string lines = "$ cd /"
		"\n$ ls"
		"\ndir a"
		"\n14848514 b.txt"
		"\n8504156 c.dat";
	std::stringstream strStream(lines);

	// act
	auto rootDir = Directory::buildDirectory(strStream);
	int total = rootDir->getSize();
	// assert
	EXPECT_EQ("/", rootDir->getCurrentDir());
	EXPECT_EQ(23352670, total);
}

TEST(Directory, fullExample) {
	// arrange
	std::string lines = "$ cd /"
		"\n$ ls"
		"\ndir a"
		"\n14848514 b.txt"
		"\n8504156 c.dat"
		"\ndir d"
		"\n$ cd a"
		"\n$ ls"
		"\ndir e"
		"\n29116 f"
		"\n2557 g"
		"\n62596 h.lst"
		"\n$ cd e"
		"\n$ ls"
		"\n584 i"
		"\n$ cd .."
		"\n$ cd .."
		"\n$ cd d"
		"\n$ ls"
		"\n4060174 j"
		"\n8033020 d.log"
		"\n5626152 d.ext"
		"\n7214296 k";
	std::stringstream strStream(lines);

	// act
	auto rootDir = Directory::buildDirectory(strStream);
	int total = 0;
	rootDir->getSize(total);
	// assert
	EXPECT_EQ("/", rootDir->getCurrentDir());
	EXPECT_EQ(95437, total);
}

TEST(Directory, getSizeGreaterThan) {
	// arrange
	std::string lines = "$ cd /"
		"\n$ ls"
		"\ndir a"
		"\n14848514 b.txt"
		"\n8504156 c.dat"
		"\ndir d"
		"\n$ cd a"
		"\n$ ls"
		"\ndir e"
		"\n29116 f"
		"\n2557 g"
		"\n62596 h.lst"
		"\n$ cd e"
		"\n$ ls"
		"\n584 i"
		"\n$ cd .."
		"\n$ cd .."
		"\n$ cd d"
		"\n$ ls"
		"\n4060174 j"
		"\n8033020 d.log"
		"\n5626152 d.ext"
		"\n7214296 k";
	std::stringstream strStream(lines);

	// act
	auto rootDir = Directory::buildDirectory(strStream);

	int total = INT_MAX;
	int used = rootDir->getSize();
	int free = 70000000 - used;
	int needed = 30000000 - free;
	int a = rootDir->getSizeGreaterThan(total, needed);
	// assert
	EXPECT_EQ(24933642, total);
}

TEST(Directory, getTotal) {
	// arrange
	std::string lines = "$ cd /"
		"\n$ ls"
		"\ndir a"
		"\n14848514 b.txt"
		"\n8504156 c.dat"
		"\ndir d"
		"\n$ cd a"
		"\n$ ls"
		"\ndir e"
		"\n29116 f"
		"\n2557 g"
		"\n62596 h.lst"
		"\n$ cd e"
		"\n$ ls"
		"\n584 i"
		"\n$ cd .."
		"\n$ cd .."
		"\n$ cd d"
		"\n$ ls"
		"\n4060174 j"
		"\n8033020 d.log"
		"\n5626152 d.ext"
		"\n7214296 k";
	std::stringstream strStream(lines);

	// act
	auto rootDir = Directory::buildDirectory(strStream);
	int total = rootDir->getSize();
	// assert
	EXPECT_EQ(48381165, total);
}
