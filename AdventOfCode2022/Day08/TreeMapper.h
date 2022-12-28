#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <istream>



int getScenicScore(int x, int y, std::vector< std::vector<int>> map)
{
	int total = 1;
	int xBlock = std::max(x,0);
	// left
	for (int i = x - 1; i >= 0; i--)
	{
		if (map[y][x] <= map[y][i])
		{

			xBlock = x - i;
			break;
		}
	}
	total *= xBlock;
	xBlock = map[0].size()-x-1;
	// right
	for (int i = x + 1; i < map[0].size(); i++)
	{
		if (map[y][x] <= map[y][i])
		{
			xBlock = i - x;
			break;
		}
	}
	total *= xBlock;

	int yBlock = std::max(y, 0);
	// up
	for (int i = y - 1; i >= 0; i--)
	{
		int treeHeight = map[y][x];
		if (treeHeight <= map[i][x])
		{
			yBlock = y - i;
			break;
		}
	}
	total *= yBlock;
	yBlock = map.size() - y-1;
	//down
	for (int i = y + 1; i < map.size(); i++)
	{
		if (map[y][x] <= map[i][x])
		{
			yBlock = i - y;
			break;
		}
	}
	total *= yBlock;
	return total;
}

int get_visible_tree_count(std::istream& inputStream)
{
	std::vector<std::string> map;
	std::string inputLine;

	int width = -1;
	while (getline(inputStream, inputLine))
	{
		if (width == -1)
		{
			width = inputLine.size();
		}
		map.push_back(inputLine);
	}

	int height = map.size();

	bool** visibleTreeMap = new bool*[width];
	for (int i = 0; i < width; i++)
	{
		visibleTreeMap[i] = new bool[height] {false};
	}


	// left to right
	int highestTree = -1;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int treeHeight = map[i][j] - '0';
			if (treeHeight > highestTree)
			{
				visibleTreeMap[i][j] = true;
				highestTree = treeHeight;
			}

		}
		highestTree = -1;
	}
	// right to left
	for (int i = 0; i < height; i++)
	{
		for (int j = width-1; j >=0; j--)
		{
			int treeHeight = map[i][j] - '0';
			if (treeHeight > highestTree)
			{
				visibleTreeMap[i][j] = true;
				highestTree = treeHeight;
			}

		}
		highestTree = -1;
	}

	// top to bottom
	for (int j = 0; j < width; j++)
	{
		for (int i = 0; i < height; i++)
		{
			int treeHeight = map[i][j] - '0';
			if (treeHeight > highestTree)
			{
				visibleTreeMap[i][j] = true;
				highestTree = treeHeight;
			}
		}
		highestTree = -1;
	}

	// bottom to top
	for (int j = 0; j < width; j++)
	{
		for (int i = height-1; i >=0; i--)
		{
			int treeHeight = map[i][j] - '0';
			if (treeHeight > highestTree)
			{
				visibleTreeMap[i][j] = true;
				highestTree = treeHeight;
			}
		}
		highestTree = -1;
	}


	int count = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (visibleTreeMap[i][j])
			{
				count++;
				std::cout << '1';
			}
			else
			{
				std::cout << '0';
			}
		}
		std::cout << '\n';
	}
	return count;
}

std::vector<std::vector<int>> getMap(std::istream& inputStream)
{
	std::vector<std::vector<int>> map;
	std::string inputLine;
	while (getline(inputStream, inputLine))
	{
		std::vector<int> lineVector;
		for (int i = 0; i < inputLine.size(); i++)
		{
			lineVector.insert(lineVector.end(), inputLine[i]-'0');
		}
		map.insert(map.end(),lineVector);
	}
	return map;
}
int getBestScenicScore(std::istream& inputStream)
{
	std::vector<std::vector<int>> map = getMap(inputStream);

	int bestScore = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			auto currentScore = getScenicScore(j, i, map);
			bestScore = std::max(bestScore, currentScore);
		}
	}
	return bestScore;
}
