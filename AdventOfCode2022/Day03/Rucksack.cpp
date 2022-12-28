#include "Rucksack.h"
#include <string>
#include <bitset>
int Rucksack::getMissingItemsTotal(std::istream& inputStream)
{
	std::string inputLine;
	int total = 0;
	while (std::getline(inputStream, inputLine))
	{
		std::bitset<52> charMap;
		for (int i = 0; i < inputLine.size()/2; i++)
		{
			int position = getPosition(inputLine[i]);
			charMap.set(position);
		}
		for (int i = inputLine.size() / 2; i < inputLine.size(); i++)
		{
			int position = getPosition(inputLine[i]);
			if (charMap[position])
			{
				total += position+1;
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
		std::bitset<52> charMap[3];
		for (int j = 0; j < 3; j++)
		{
			std::string inputLine;
			std::getline(inputStream, inputLine);

			for (int i = 0; i < inputLine.size(); i++)
			{
				int position = getPosition(inputLine[i]);
				charMap[j].set(position);
			}
		}
		auto resultingBitmap = charMap[0] & charMap[1] & charMap[2];
		for (int i = 0; i < 52; i++)
		{
			if (resultingBitmap[i])
			{
				
				total += i+1;
				break;
			}
		}
	}
	return total;
}


int Rucksack::getPosition(char input_char)
{
	return islower(input_char) ? input_char - 'a' : input_char - 'A' + 26;
}