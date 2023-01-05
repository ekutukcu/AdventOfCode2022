#pragma once
#include <vector>
#include <istream>
#include <string>
#include <regex>
#include <unordered_set>
#include "../Day09/RopeBridge.h"

namespace regolith
{

	std::vector<std::string> split(const std::string& input, const std::string& regex) {
		// passing -1 as the submatch index parameter performs splitting
		std::regex re(regex);
		std::sregex_token_iterator
			first{ input.begin(), input.end(), re, -1 },
			last;
		return { first, last };
	}

	class Regolith
	{
	};


	struct Line
	{
		Point start;
		Point end;

		Line(Point start, Point end) :start(start), end(end)
		{

		}

		bool intersects(Point p) const
		{
			auto minX = std::min(start.X, end.X);
			auto minY = std::min(start.Y, end.Y);
			auto maxX = std::max(start.X, end.X);
			auto maxY = std::max(start.Y, end.Y);
			if (p.X >= minX && p.X <= maxX && p.Y >= minY && p.Y <= maxY)
			{
				return true;
			}
			return false;
		}
	};

	Point readPoint(std::string pointStr)
	{
		auto pointString = split(pointStr, ",");
		int x = std::stoi(pointString[0]);
		int y = std::stoi(pointString[1]);

		return Point(x, y);
	}

	std::vector<Line> readLines(std::istream& inputStream)
	{
		std::string current;
		std::vector<Line> lines;
		while (getline(inputStream, current))
		{
			auto pointStrings = split(current, " -> ");

			auto start = readPoint(pointStrings[0]);
			for (int i = 1; i < pointStrings.size(); i++)
			{
				auto end = readPoint(pointStrings[i]);
				lines.push_back(Line(start, end));
				start = end;
			}
		}
		return lines;
	}

	enum Movement
	{
		Down,
		Left,
		Right,
		None
	};

	Movement getPossibleMovement(Point sandStartingPoint, const std::vector<Line>& lines, const std::unordered_set<Point>& pointSet)
	{
		bool down=true, left=true, right = true;
		Point downP(sandStartingPoint.X, sandStartingPoint.Y + 1);
		Point leftP(sandStartingPoint.X-1, sandStartingPoint.Y + 1);
		Point rightP(sandStartingPoint.X+1, sandStartingPoint.Y + 1);


		for (const Line& line : lines)
		{
			if (line.intersects(downP))
			{
				down=false;
			}
			if (line.intersects(leftP))
			{
				left = false;
			}
			if (line.intersects(rightP))
			{
				right = false;
			}
		}


		if (pointSet.count(downP)==1)
		{
			down = false;
		}
		if (pointSet.count(leftP) == 1)
		{
			left = false;
		}
		if (pointSet.count(rightP) == 1)
		{
			right = false;
		}
		

		if (down)
		{
			return Movement::Down;
		}
		if (left)
		{
			return Movement::Left;
		}
		if (right)
		{
			return Movement::Right;
		}
		return Movement::None;
	}

	int getRestingSandCount(Point sandStartingPoint, std::vector<Line>& lines)
	{
		int maxY = INT_MIN;
		for (auto& line : lines)
		{
			maxY = std::max(maxY, std::max(line.start.Y, line.end.Y));
		}

		std::unordered_set<Point> points;
		Point current(sandStartingPoint);
		while (current.Y <= maxY)
		{
			auto movement = getPossibleMovement(current, lines, points);
			if (movement == Movement::None)
			{
				points.insert(current);
				current = sandStartingPoint;
				continue;
			}
			else
			{
				switch (movement)
				{
				case regolith::Down:
					current.Y++;
					break;
				case regolith::Left:
					current.Y++;
					current.X--;
					break;
				case regolith::Right:
					current.Y++;
					current.X++;
					break;
				case regolith::None:
					break;
				default:
					break;
				}
			}
		}
		return points.size();
	}

	int getRestingSandWithFloorCount(Point sandStartingPoint, std::vector<Line>& lines)
	{
		int maxY = INT_MIN;
		for (auto& line : lines)
		{
			maxY = std::max(maxY, std::max(line.start.Y, line.end.Y));
		}

		std::unordered_set<Point> points;
		Point current(sandStartingPoint);
		while (current.Y <= maxY+1)
		{
			if (current.Y == maxY + 1)
			{

				points.insert(current);
				current = sandStartingPoint;
			}
			auto movement = getPossibleMovement(current, lines, points);
			if (movement == Movement::None)
			{
				if (current.X == sandStartingPoint.X && current.Y == sandStartingPoint.Y)
				{
					break;
				}
				points.insert(current);
				current = sandStartingPoint;
				continue;
			}
			else
			{
				switch (movement)
				{
				case regolith::Down:
					current.Y++;
					break;
				case regolith::Left:
					current.Y++;
					current.X--;
					break;
				case regolith::Right:
					current.Y++;
					current.X++;
					break;
				case regolith::None:
					break;
				default:
					break;
				}
			}
		}
		return points.size()+1;
	}
}