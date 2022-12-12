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
#include "../AdventOfCode2022/RopeBridge.h"
#include "../AdventOfCode2022/CathodeRayTube.h"

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

void runDay9()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input9.txt");
    std::ifstream inputStream(filePath);
    auto visitedPoints = getVisitedPointCount(inputStream,2);

    // assert
    std::cout << visitedPoints << std::endl;
}
void runDay9_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input9.txt");
    std::ifstream inputStream(filePath);
    auto visitedPoints = getVisitedPointCount(inputStream, 10);

    // assert
    std::cout << visitedPoints << std::endl;
}
void runDay10()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input10.txt");
    std::ifstream inputStream(filePath);
    CathodeRayTube tube;
    tube.setLogPoint(20);
    tube.setLogPoint(60);
    tube.setLogPoint(100);
    tube.setLogPoint(140);
    tube.setLogPoint(180);
    tube.setLogPoint(220);

    auto result = CathodeRayTube::processStream(inputStream, tube);

    // assert
    std::cout << result << std::endl;
}

void runDay10_2()
{
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input10.txt");
    std::ifstream inputStream(filePath);
    CathodeRayTube tube;
    CathodeRayTube::processStream(inputStream, tube);

    // assert
    std::cout << tube.getCrtDisplay() << std::endl;
}

int main()
{
    runDay10_2();
    return 0;
}