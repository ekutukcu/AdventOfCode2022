// AdventOfCode2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "../AdventOfCode2022/CalorieCounting.h"
#include "../AdventOfCode2022/RockPaperScissors.h"
#include "../AdventOfCode2022/Rucksack.h"
#include "../AdventOfCode2022/PairOverlap.h"
#include "../AdventOfCode2022/SupplyStacks.h"
#include "../AdventOfCode2022/TuningTrouble.h"
#include "../AdventOfCode2022/Directory.h"
#include "../AdventOfCode2022/TreeMapper.h"

void runDay1();
void runDay2();
void runDay3();
void runDay3_2();
void runDay4();
void runDay4_2();
void runDay5();
void runDay5_2();
void runDay6();
void runDay6_2();
void runDay7();
void runDay7_2();
void runDay8();
void runDay8_2();

int main()
{
    runDay8_2();
    return 0;
}

void runDay1()
{
    CalorieCounting day1(3);
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input.txt");
    std::ifstream inputStream(filePath);
    int cals = day1.getMaxCalories(inputStream);
    std::cout << cals << std::endl;
}

void runDay2()
{
    RockPaperScissors day2;
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input2.txt");
    std::ifstream inputStream(filePath);
    int cals = day2.calculateScoreResultPredication(inputStream);
    std::cout << cals << std::endl;
}
void runDay3()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input3.txt");
    std::ifstream inputStream(filePath);
    int cals = Rucksack::getMissingItemsTotal(inputStream);
    std::cout << cals << std::endl;
}

void runDay3_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input3.txt");
    std::ifstream inputStream(filePath);
    int cals = Rucksack::getBadgesTotal(inputStream);
    std::cout << cals << std::endl;
}

void runDay4()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input4.txt");
    std::ifstream inputStream(filePath);
    int cals = getOverlappingPairCount(inputStream, true);
    std::cout << cals << std::endl;
}

void runDay4_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input4.txt");
    std::ifstream inputStream(filePath);
    int cals = getOverlappingPairCount(inputStream, false);
    std::cout << cals << std::endl;
}

void runDay5()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input5.txt");
    std::ifstream inputStream(filePath);
    auto res = getTopCrates(inputStream, 9);
    std::cout << res << std::endl;
}

void runDay5_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input5.txt");
    std::ifstream inputStream(filePath);
    auto res = getTopCrates(inputStream, 9, false);
    std::cout << res << std::endl;
}


void runDay6()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input6.txt");
    std::ifstream inputStream(filePath);
    std::string line;
    getline(inputStream, line);
    auto res = getMarkerLocation(line, 4);
    std::cout << res << std::endl;
}


void runDay6_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input6.txt");
    std::ifstream inputStream(filePath);
    std::string line;
    getline(inputStream, line);
    auto res = getMarkerLocation(line, 14);
    std::cout << res << std::endl;
}

void runDay7()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input7.txt");
    std::ifstream inputStream(filePath);
    auto dir = Directory::buildDirectory(inputStream);
    int res = 0;
    dir->getSize(res);
    std::cout << res << std::endl;
}

void runDay7_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input7.txt");
    std::ifstream inputStream(filePath);
    auto rootDir = Directory::buildDirectory(inputStream);
    int total = INT_MAX;
    int used = rootDir->getSize();
    int free = 70000000 - used;
    int needed = 30000000 - free;
    int a = rootDir->getSizeGreaterThan(total, needed);
    // assert
    std::cout << total << std::endl;
}

void runDay8()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input8.txt");
    std::ifstream inputStream(filePath);
    auto visibleTreeCount = get_visible_tree_count(inputStream);

    // assert
    std::cout << visibleTreeCount << std::endl;
}

void runDay8_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input8.txt");
    std::ifstream inputStream(filePath);
    auto visibleTreeCount = getBestScenicScore(inputStream);

    // assert
    std::cout << visibleTreeCount << std::endl;
}


void benchmark(void(*func)(), int repeat, int number_runs) {
    double smallest = std::numeric_limits<double>::infinity();
    for (int i = 0; i < repeat; i++) {
        auto t0 = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < number_runs; j++) {
            func();
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> delta = t1 - t0;
        if (delta.count() < smallest) {
            smallest = delta.count();
        }
    }
    std::cout << smallest << std::endl;
}
