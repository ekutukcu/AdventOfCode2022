#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <algorithm>
class Directory
{
	std::vector<Directory*> SubDirs;
	std::vector<std::tuple<std::string, int>> Files;
	std::string directoryName;
	Directory* parent;

public:
	Directory(std::string path);
	Directory(Directory*parent, std::string path);
	void addFile(std::string filename, int fileSize);
	Directory* addDir(std::string dir);
	int getSize(int & total);
	std::string getCurrentDir();
	static Directory* buildDirectory(std::istream& inputSteam);
	int getSizeGreaterThan(int &total, const int needed);
	int getSize();
};