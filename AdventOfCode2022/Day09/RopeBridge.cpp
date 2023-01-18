
#include "RopeBridge.h"
#include <fstream>
#include "../Day04/PairOverlap.h"
int getVisitedPointCount(std::istream& inputStream, int numPoints)
{
	std::string inputLine;

	std::vector<Point> points;
	for (int i = 0; i < numPoints; i++)
	{
		points.push_back(Point());
	}

	std::unordered_map<char, Point> movements{
		{'U', Point(0,1)},
		{'D', Point(0,-1)},
		{'L', Point(-1,0)},
		{'R', Point(1,0)},
	};

	std::unordered_set<Point> seenPoints;
	int64_t minX=0, maxX=0, minY=0, maxY=0;
	while (getline(inputStream, inputLine))
	{
		auto parts = split(' ', inputLine);
		char direction = parts[0][0];
		int distance = std::stoi(parts[1]);
		auto movement = movements[direction];
		for (int i = 0; i < distance; i++)
		{
			points[numPoints - 1].X += movement.X;
			points[numPoints - 1].Y += movement.Y;
			for (int j = numPoints - 1; j > 0; j--)
			{
				auto diffX = points[j].X- points[j - 1].X ;
				auto diffY = points[j].Y- points[j - 1].Y;

				auto absDiffX = abs(diffX);
				auto absDiffY = abs(diffY);

				if ((absDiffX >1 && absDiffY ==0) || (absDiffX ==0 && absDiffY >1))
				{
					auto diagonalXMovement = diffX == 0 ? 0 : diffX / absDiffX;
					auto diagonalYMovement = diffY == 0 ? 0 : diffY / absDiffY;

					points[j - 1].X += diagonalXMovement;
					points[j - 1].Y += diagonalYMovement;
				}
				else if ((absDiffX > 1 && absDiffY > 0) || (absDiffX > 0 && absDiffY > 1))
				{
					auto diagonalXMovement = diffX == 0 ? 0 : diffX / absDiffX;
					auto diagonalYMovement = diffY == 0 ? 0: diffY / absDiffY;
					points[j - 1].X +=diagonalXMovement;
					points[j - 1].Y +=diagonalYMovement;
				}
			}
			seenPoints.insert(points[0]);
			minX = std::min(minX, points[0].X);
			maxX = std::max(maxX, points[0].X);
			minY = std::min(minY, points[0].Y);
			maxY = std::max(maxY, points[0].Y);
		}
	}

	
	return seenPoints.size();
}
void printPoints(int minX, int maxX, int minY, int maxY, std::unordered_set<Point> seenPoints, std::vector<Point> points)
{
	std::ofstream outputFile("test.log", std::ofstream::app);
	minX = -12;
	minY = -12;
	maxX = 14;
	maxY = 14;
	for (int i = maxY; i >= minY; i--)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (i == 0 && j == 0)
			{
				outputFile << 's';
			}
			else
			{
				char output = '.';
				Point p(j, i);
				for (int i = points.size()-1; i >=0; i--)
				{
					if (points[i] == p)
					{
						output = '0'+i;
						break;
					}
				}
				if (seenPoints.count(p))
				{
					output= '#';
				}
				outputFile << output;
				
			}
		}

		outputFile << '\n';
	}

}

bool Point:: operator==(const Point& other) const
{
return other.X == X && other.Y == Y;
}

Point::Point() : X(0), Y(0)
{

}

Point::Point(int64_t x, int64_t y) :X(x), Y(y)
{

}