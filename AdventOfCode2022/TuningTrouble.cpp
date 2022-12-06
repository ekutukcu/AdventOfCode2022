#include "TuningTrouble.h"
#include <set>

int getMarkerLocation(std::string input, int numberDistinctElememts)
{
	for (int i = numberDistinctElememts; i < input.size(); i++)
	{
		std::set<char> lastN;
		for (int j = numberDistinctElememts-1; j >= 0; j--)
		{
			lastN.insert(input[i-j]);

		}
		if (lastN.size() == numberDistinctElememts)
		{
			return i+1;
		}
	}
	return -1;
}