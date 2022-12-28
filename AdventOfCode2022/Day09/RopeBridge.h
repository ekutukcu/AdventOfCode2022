#pragma once
#include <istream>
#include <vector>
#include <string>
#include  <functional>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
struct Point
{
	int X;
	int Y;

	Point();

	Point(int x, int y);

	bool operator==(const Point& other) const;

};

int getVisitedPointCount(std::istream& inputStream, int numPoints);
void addIfNotPresent(Point point, std::vector<Point>& visitedPoints);
void printPoints(int minX, int maxX, int minY, int maxY, std::unordered_set<Point> seenPoints, std::vector<Point> points);
template<>
struct std::hash<Point>
{
    std::size_t operator()(const Point& k) const
    {
        using std::size_t;
        using std::hash;
        using std::string;

        // Compute individual hash values for first,
        // second and third and combine them using XOR
        // and bit shifting:

        return ((hash<int>()(k.X)
            ^ (hash<int>()(k.X) << 1)) >> 1);
    }
};