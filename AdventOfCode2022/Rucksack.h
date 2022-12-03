#pragma once
#include <istream>
class Rucksack
{
public:
	static int getMissingItemsTotal(std::istream& inputStream);
	static int getBadgesTotal(std::istream& inputStream);
};

