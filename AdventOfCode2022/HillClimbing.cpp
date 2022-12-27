#include <string>
#include "HillClimbing.h"
int get_shortest_path(std::istream& input_stream)
{
	int height = 0;
	int width = 0;
	std::string line;

	while (getline(input_stream, line))
	{
		if (width == 0)
		{
			width = line.length();
		}

		for (int i = 0; i < width; i++)
		{

		}
	}
	return 0;
}