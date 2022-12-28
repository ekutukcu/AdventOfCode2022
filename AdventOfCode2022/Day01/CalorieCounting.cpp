#include "CalorieCounting.h"

CalorieCounting::CalorieCounting(int numberOfDeer) :results(std::make_unique<int[]>(numberOfDeer))
{
    this->numberOfDeer = numberOfDeer;
    for (int i = 0; i < numberOfDeer; i++)
    {
        results[i] = 0;
    }
}

int CalorieCounting::getMaxCalories(std::istream& inputStream)
{
    int currentLine = 0;
    int runningTotal = 0;
    std::string line;

    while (std::getline(inputStream, line))
    {
        if (line.length() > 0)
        {
            runningTotal += std::stoi(line);
        }
        else
        {
            insertTotal(runningTotal);
            runningTotal = 0;
        }
    }
    insertTotal(runningTotal);

    int total = 0;
    for (int i = 0;i < numberOfDeer;i++)
    {
        total += results[i];
    }
    return total;
}

void CalorieCounting::insertTotal(int runningTotal)
{
    int index = INT_MAX;
    for (int i = 0; i < numberOfDeer; i++)
    {
        if (runningTotal > results[i])
        {
            index = i;
            break;
        }
    }

    for (int i = index; i < numberOfDeer; i++)
    {
        int temp = results[i];
        results[i] = runningTotal;
        runningTotal = temp;
    }
}
