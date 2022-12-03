// AdventOfCode2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "CalorieCounting.h"
#include "RockPaperScissors.h"
#include "Rucksack.h"

void runDay1();
void runDay2();
void runDay3();
void runDay3_2();

int main()
{
    runDay3_2();
    return 0;
}

void benchmarkDay1()
{
    CalorieCounting day1(3);
    std::string filePath("C:\\Users\\emin\\source\\repos\\AdventOfCode2022\\input.txt");
    std::ifstream inputStream(filePath);

    std::stringstream strdata();
    std::string line;

    int cals = day1.getMaxCalories(inputStream);
    std::cout << cals << std::endl;
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
