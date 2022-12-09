#include "Directory.h"
#include "PairOverlap.h"
#include <stdexcept>


Directory::Directory(Directory* parent1, std::string path):parent(parent1), directoryName(path)
{
}


Directory::Directory(std::string path) : parent(nullptr),directoryName(path)
{
}

void Directory::addFile(std::string filename, int fileSize)
{
	for (auto file : Files)
	{
		if (std::get<0>(file) == filename)
		{
			return;
		}
	}
	Files.push_back(std::make_tuple(filename, fileSize));
}

Directory* Directory::addDir(std::string dir)
{
	for (int i = 0; i < SubDirs.size(); i++)
	{
		if (SubDirs[i]->directoryName == dir) 
		{
			return SubDirs[i];
		}
	}
	auto newDir = new Directory(this, dir);
	SubDirs.push_back(newDir);
	return newDir;
}


int Directory::getSize(int & total)
{
	int size = 0;

	for (int i = 0; i < SubDirs.size(); i++)
	{
		auto dirSize = this->SubDirs[i]->getSize(total);
		size += dirSize;
	}

	for (int i = 0; i < Files.size(); i++)
	{
		size += std::get<1>(this->Files[i]);
	}
	if (size < 100000)
	{
		total += size;
	}
	return size;
}

int Directory::getSize()
{
	int size = 0;

	for (int i = 0; i < SubDirs.size(); i++)
	{
		size += this->SubDirs[i]->getSize();;
	}

	for (int i = 0; i < Files.size(); i++)
	{
		size += std::get<1>(this->Files[i]);
	}
	return size;
}

int Directory::getSizeGreaterThan(int& total, const int needed)
{
	int size = 0;
	for (int i = 0; i < SubDirs.size(); i++)
	{
		auto dirSize = this->SubDirs[i]->getSize();
		size += dirSize;
	}

	for (int i = 0; i < Files.size(); i++)
	{
		size += std::get<1>(this->Files[i]);
	}
	if (size < total && size>needed)
	{
		total = size;
	}
	if (size > needed)
	{
		for (int i = 0; i < SubDirs.size(); i++)
		{
			auto dirSize = this->SubDirs[i]->getSizeGreaterThan(total, needed);
		}
	}
	return size;
}

std::string Directory::getCurrentDir()
{
	return directoryName;
}

Directory* Directory::buildDirectory(std::istream& inputSteam)
{
	std::string input;
	getline(inputSteam, input);
	Directory * rootDir = new Directory("/");
	Directory* currentDir = rootDir;
	while (getline(inputSteam, input))
	{
		if (input.rfind("$ cd ",0)==0)
		{
			// process dir change
			auto dir = input.substr(5);
			if (dir == "/")
			{
				currentDir = rootDir;
			}
			else if (dir == "..")
			{
				currentDir = currentDir->parent;
			}
			else
			{
				auto nextDir = currentDir->addDir(dir);
				currentDir = nextDir;
			}
		}
		else if (input.rfind("$ ls", 0) == 0)
		{
			// process ls
			while (inputSteam.peek() != '$' && !inputSteam.eof())
			{
				getline(inputSteam, input);
				if (input[0] >= '0' && input[0] <= '9')
				{
					auto parts = split(' ', input);
					int size=std::stoi(parts[0]);
					auto name = parts[1];
					currentDir->addFile(parts[1], size);
				}
				else 
				{
					auto parts = split(' ', input);
					auto name = parts[1];
					currentDir->addDir(name);
				}
			}
		}
		else
		{
			throw std::invalid_argument(input);
		}
	}
	return rootDir;
}