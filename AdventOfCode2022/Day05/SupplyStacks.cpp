#include "SupplyStacks.h"

std::string getTopCrates(std::istream& inputStream, const int colCount, const bool moveIndividually)
{
	auto stacks = std::make_unique<std::stack<char>[]>(colCount);
	std::string inputLine;
	int offset = 1;
	int spacing = 4;
	while (getline(inputStream, inputLine))
	{
		if (inputLine[1] == '1')
		{
			break;
		}
		int index = 0;
		for (int i = offset; i < inputLine.size(); i+=spacing)
		{
			if (!std::isspace(inputLine[i]))
			{
				stacks[index].push(inputLine[i]);
			}
			index++;
		}
	}
	// invert stacks
	for (int i = 0; i < colCount; i++)
	{
		std::stack<char> temp;
		while (stacks[i].size() > 0)
		{
			temp.push(stacks[i].top());
			stacks[i].pop();
		}
		stacks[i] = temp;
	}

	// skip line
	getline(inputStream, inputLine);

	while (getline(inputStream, inputLine))
	{
		int count = 0;
		int from = 0;
		int to = 0;
		sscanf_s(inputLine.c_str(), "move %d from %d to %d", &count, &from, &to);
		if (moveIndividually)
		{
			for (int i = 0; i < count; i++)
			{
				stacks[to - 1].push(stacks[from - 1].top());
				stacks[from - 1].pop();
			}
		}
		else
		{
			std::stack<char> temp;
			for (int i = 0; i < count; i++)
			{
				temp.push(stacks[from - 1].top());
				stacks[from - 1].pop();
			}
			while (!temp.empty())
			{
				stacks[to - 1].push(temp.top());
				temp.pop();
			}
		}
	}

	std::string ret = "";
	for (int i = 0; i < colCount; i++)
	{
		if (!stacks[i].empty())
		{
			ret += stacks[i].top();
		}
	}

	return ret;
}
