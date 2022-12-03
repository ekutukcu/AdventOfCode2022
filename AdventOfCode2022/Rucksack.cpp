#include "Rucksack.h"
#include <string>
#include <bitset>
int Rucksack::getMissingItemsTotal(std::istream& inputStream)
{
	std::string inputLine;
	int total = 0;
	while (std::getline(inputStream, inputLine))
	{
		std::bitset<58> charMap;
		for (int i = 0; i < inputLine.size()/2; i++)
		{
			int position = inputLine[i] - 'A';
			charMap.set(position);
		}
		for (int i = inputLine.size() / 2; i < inputLine.size(); i++)
		{
			char position = inputLine[i];
			int index = position - 'A';
			if (charMap[index])
			{
				int offset = islower(position) ? 'a' : 'A'-26;
				int change = position - offset + 1;
				total += change;
				break;
			}
		}
	}
	return total;
}

int Rucksack::getBadgesTotal(std::istream& inputStream)
{
	int total = 0;
	while (!inputStream.eof())
	{
		std::bitset<58> charMap[3];
		for (int j = 0; j < 3; j++)
		{
			std::string inputLine;
			std::getline(inputStream, inputLine);

			for (int i = 0; i < inputLine.size(); i++)
			{
				int position = inputLine[i] - 'A';
				charMap[j].set(position);
			}
		}
		auto resultingBitmap = charMap[0] & charMap[1] & charMap[2];
		for (int i = 0; i < 58; i++)
		{
			if (resultingBitmap[i])
			{
				char position = i + 'A';
				int offset = islower(position) ? 'a' : 'A' - 26;
				int change = position - offset + 1;
				total += change;
				break;
			}
		}
	}
	return total;
}