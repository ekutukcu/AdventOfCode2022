#include <istream>
#include <unordered_map>
#include <string>
#include "RopeBridge.h"
#include "pch.h"

int get_shortest_path(std::istream& input_stream);
int get_global_shortest_path(std::istream& input_stream);
std::unordered_map<Point, int> get_mapped_points(std::vector<std::string> lines, std::unordered_map<Point, int> unseen_points, const Point& start);