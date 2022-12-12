#include <cassert>
#include "PairOverlap.h"
#include "CathodeRayTube.h"

CathodeRayTube::CathodeRayTube() :x(1), power(0),cycles(0), crtDisplay("")
{

}

int CathodeRayTube::getSignalStrength()
{
	return power;
}

void CathodeRayTube::process(std::string instruction)
{
	auto parts = split(' ', instruction);
	auto op = parts[0];
	
	logSignalStrength();
	if (op == "addx")
	{
		int value = std::stoi(parts[1]);
		logSignalStrength();
		x += value;
	}
	else
	{
		assert(op == "noop");
	}
}

void CathodeRayTube::setLogPoint(int cycleNumber)
{
	this->logPoints.insert(cycleNumber);
}

void CathodeRayTube::logSignalStrength()
{

	cycles++;
	if (logPoints.count(cycles) == 1)
	{
		power += x * cycles;
	}
	auto correctedCycles = cycles % 40 == 0 ? 40 : cycles % 40;;
	if (x <= correctedCycles && correctedCycles <= x + 2)
	{
		crtDisplay += '#';
	}
	else
	{
		crtDisplay += '.';
	}
	if (cycles % 40 == 0)
	{
		crtDisplay += '\n';
	}
}

int CathodeRayTube::processStream(std::istream& inputStream, CathodeRayTube& tube)
{
	std::string inputLine;
	while (getline(inputStream, inputLine))
	{
		tube.process(inputLine);
	}

	return tube.getSignalStrength();
}


std::string CathodeRayTube::getCrtDisplay()
{
	return crtDisplay;
}