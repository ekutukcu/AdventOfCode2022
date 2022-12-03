#pragma once
#include <istream>
class Rucksack
{
public:
	static int getMissingItemsTotal(std::istream& inputStream);
	static int getPosition(char input_char);
	static int getBadgesTotal(std::istream& inputStream);
};

