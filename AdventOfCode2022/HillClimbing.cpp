
#include "HillClimbing.h"



std::unordered_map<Point, int> get_mapped_points(std::vector<std::string> lines, std::unordered_map<Point, int> unseen_points, const Point& start)
{
	std::string line;

	std::unordered_map<Point, int> seen_points;

	int height = lines.size();
	int width = lines[0].length();

	auto map_points = [&seen_points, &unseen_points](const Point& tmp, int best_distance) -> void
	{
		if (seen_points.contains(tmp))
		{
			seen_points [tmp] = min(best_distance, seen_points[tmp]);
		}
		else if (unseen_points.contains(tmp))
		{
			unseen_points[tmp] = min(best_distance, unseen_points[tmp]);
		}

	};

	std::vector<Point> points_to_remove;
	bool changed = true;
	while (changed)
	{
		changed = false;
		Point best_point;
		int best_distance = INT_MAX;
		for (auto& p : unseen_points)
		{
			if (p.second < best_distance)
			{
				best_point = p.first;
				best_distance = p.second;
				changed = true;
			}
		}

		if (changed)
		{
			seen_points[best_point] = best_distance;
			unseen_points.erase(best_point);

			if (best_point.Y > 0 && lines[best_point.Y][best_point.X] >= (lines[best_point.Y - 1][best_point.X] - 1))
			{
				Point tmp(best_point.X, best_point.Y - 1);
				map_points(tmp, best_distance + 1);

			}
			if (best_point.X > 0 && lines[best_point.Y][best_point.X] >= (lines[best_point.Y][best_point.X - 1] - 1))
			{
				Point tmp(best_point.X - 1, best_point.Y);
				map_points( tmp, best_distance + 1);

			}
			if (best_point.Y < (height - 1) && lines[best_point.Y][best_point.X] >= (lines[best_point.Y + 1][best_point.X] - 1))
			{
				Point tmp(best_point.X, best_point.Y + 1);
				map_points( tmp, best_distance + 1);

			}
			if (best_point.X < (width - 1) && lines[best_point.Y][best_point.X] >= (lines[best_point.Y][best_point.X + 1] - 1))
			{
				Point tmp(best_point.X + 1, best_point.Y);
				map_points( tmp, best_distance + 1);

			}
		}

	}

	return seen_points;
}

int get_shortest_path(std::istream& input_stream)
{

	int height = 0;
	int width = 0;
	std::string line;
	std::unordered_map<Point, int> unseen_points;
	std::vector<std::string> lines;


	std::unique_ptr<Point> start;
	std::unique_ptr<Point> end;

	while (getline(input_stream, line))
	{
		if (width == 0)
		{
			width = line.length();
		}

		for (int i = 0; i < width; i++)
		{
			Point p(i, height);
			unseen_points.emplace(p, INT_MAX);

			if (line[i] == 'E')
			{
				line[i] = 'z' + 1;
				end = std::make_unique<Point>(p);
			}
			else if (line[i] == 'S')
			{
				line[i] = 'a';
				start = std::make_unique<Point>(p);
			}
		}
		lines.push_back(line);
		height++;
	}


	if (start->Y < height - 1)
		unseen_points[Point(start->X, start->Y + 1)] = 1;
	if (start->Y > 0)
		unseen_points[Point(start->X, start->Y - 1)] = 1;
	if (start->X < width - 1)
		unseen_points[Point(start->X + 1, start->Y)] = 1;
	if (start->X > 0)
		unseen_points[Point(start->X - 1, start->Y)] = 1;


	unseen_points.erase(*start);

	auto seen_points = get_mapped_points(lines,unseen_points, *start);

	return seen_points[*end];
}


int get_global_shortest_path(std::istream& input_stream)
{

	int height = 0;
	int width = 0;
	std::string line;
	std::unordered_map<Point, int> unseen_points;
	std::vector<std::string> lines;


	std::unique_ptr<Point> end;

	while (getline(input_stream, line))
	{
		if (width == 0)
		{
			width = line.length();
		}

		for (int i = 0; i < width; i++)
		{
			Point p(i, height);
			unseen_points.emplace(p, INT_MAX);

			if (line[i] == 'E')
			{
				line[i] = 'z' + 1;
				end = std::make_unique<Point>(p);
			}
			else if (line[i] == 'S')
			{
				line[i] = 'a';
			}
		}
		lines.push_back(line);
		height++;
	}

	int min_dist = INT_MAX;

	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines[i].length(); j++)
		{
			if (lines[i][j] != 'a')
			{
				continue;
			}
			std::unordered_map<Point, int>  unseen_points_copy(unseen_points);
			auto start = Point(j, i);
			unseen_points_copy.erase(start);

			bool any_path = false;

			if (start.Y < height - 1 && lines[i][j] >= (lines[i + 1][j]- 1))
			{
				unseen_points_copy[Point(start.X, start.Y + 1)] = 1;
				any_path = true;
			}
			if (start.Y > 0 && lines[i][j] >= (lines[i - 1][j] - 1))
			{
				unseen_points_copy[Point(start.X, start.Y - 1)] = 1;
				any_path = true;
			}
			if (start.X < width - 1 && lines[i][j] >= (lines[i][j + 1] - 1))
			{
				unseen_points_copy[Point(start.X + 1, start.Y)] = 1;
				any_path = true;
			}
			if (start.X > 0 && lines[i][j] >= (lines[i][j - 1] - 1))
			{
				unseen_points_copy[Point(start.X - 1, start.Y)] = 1;
				any_path = true;
			}

			if (!any_path)
			{
				continue;
			}

			auto seen_points = get_mapped_points(lines, unseen_points_copy, start);
			if (!seen_points.contains(*end))
			{
				continue;
			}
			auto new_dist = seen_points[*end];
			min_dist = min(min_dist, new_dist);
		}
	}
	return min_dist;
}
