#pragma once
#include <istream>
#include <string>
#include <vector>
#include "PairOverlap.h"

std::vector<std::string> split(char delimiter, std::string input)
{
	std::vector<std::string> splitString;
	int pos = 0;
	while ((pos = input.find(delimiter)) != std::string::npos)
	{
		splitString.push_back(input.substr(0, pos));
		input.erase(0, pos + 1);
	}
	splitString.push_back(input);
	return splitString;
}

struct Assignment
{
	int lower;
	int upper;

	Assignment(int lower, int upper)
	{
		this->lower = lower;
		this->upper = upper;
	}

	Assignment(std::string input)
	{
		auto elfParts = split('-', input);;
		lower = std::stoi(elfParts[0]);
		upper = std::stoi(elfParts[1]);
	}

	bool contains(Assignment other)
	{
		return this->lower <= other.lower &&
			this->upper >= other.upper;
	}

	bool overlaps(Assignment other)
	{
		return (this->lower <= other.lower &&
			this->upper >= other.lower)
			|| (this->lower <= other.upper &&
				this->upper >= other.upper)
			|| other.contains(*this);
	}
};


int getOverlappingPairCount(std::istream& input, bool mustFullyOverlap)
{
	std::string line;
	int count = 0;
	while (getline(input, line))
	{
		auto parts = split(',', line);
		auto elf1 = Assignment(parts[0]);
		auto elf2 = Assignment(parts[1]);
		if (mustFullyOverlap)
		{
			if (elf1.contains(elf2) || elf2.contains(elf1))
			{
				count++;
			}
		}
		else
		{
			if (elf1.overlaps(elf2))
			{
				count++;
			}
		}
	}
	return count;

}

