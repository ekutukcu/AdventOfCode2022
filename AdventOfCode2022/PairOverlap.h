#pragma once
#include <istream>
#include <vector>
int getOverlappingPairCount(std::istream& input, bool mustFullyOverlap);
std::vector<std::string> split(char delimiter, std::string input);