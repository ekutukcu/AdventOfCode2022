#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class CalorieCounting
{
public:
    CalorieCounting(int numberOfDeer);
    int getMaxCalories(std::istream& inputStream);
private:
    void insertTotal(int value);

    int numberOfDeer;
    std::unique_ptr<int[]> results;
};

