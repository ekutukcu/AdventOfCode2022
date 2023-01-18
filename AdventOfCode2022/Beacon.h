#pragma once
#include <vector>
#include "Day09/RopeBridge.h"
#include <regex>

#include <iostream>
namespace beacon
{

	std::vector<std::string> split(const std::string& input, const std::string& regex) {
		// passing -1 as the submatch index parameter performs splitting
		std::regex re(regex);
		std::sregex_token_iterator
			first{ input.begin(), input.end(), re, -1 },
			last;
		return { first, last };
	}

	struct Beacon
	{
		std::unordered_set<Point> beacons;
		std::vector<Point> sensors;
		int64_t minX=INT64_MAX;
		int64_t maxX=INT64_MIN;

		static Beacon parse(std::istream& input)
		{
			int64_t sensorX = 0;
			int64_t sensorY = 0;
			int64_t beaconX = 0;
			int64_t beaconY = 0;


			std::regex re("-?\\d+");

			std::unordered_set<Point> beacons;
			std::vector<Point> sensors;
			std::string inputLine;
			while (getline(input, inputLine))
			{
				std::smatch match;
				std::sregex_iterator iter(inputLine.begin(), inputLine.end(), re);
				std::sregex_iterator end;
				if (std::regex_search(inputLine, match, re))
				{
					auto x = iter;
					sensorX = std::stoi(x->str());
					x++;
					sensorY = std::stoi(x->str());
					x++;
					beaconX = std::stoi(x->str());
					x++;
					beaconY = std::stoi(x->str());
					x++;
					
				}
				Point beacon(beaconX, beaconY);
				Point sensor(sensorX, sensorY);

				beacons.insert(beacon);
				sensors.push_back(sensor);
			}
			Beacon beacon;
			beacon.beacons=beacons;
			beacon.sensors= sensors;
			return beacon;
		}

		inline const int64_t getTaxiDist(const Point& p1, const Point& p2)
		{
			return abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
		}

		std::unordered_map<Point, int64_t> mapDistances()
		{
			// get the distance and coordinates for the nearest beacon from each scanner
			std::unordered_map<Point, int64_t> distanceToNearestBeacon;
			for (const Point& sensor : sensors)
			{
				auto distance = INT64_MAX;
				for (const Point& beacon : beacons)
				{
					auto newDist = getTaxiDist(sensor, beacon);
					distance = std::min(distance, newDist);
					minX = std::min(minX, sensor.X - newDist);
					maxX = std::max(maxX, sensor.X + newDist);

				}

				distanceToNearestBeacon[sensor] = distance;
			}
			return distanceToNearestBeacon;
		}

		int getBeaconLessPositionCount(int y, std::unordered_map<Point, int64_t> distanceToNearestBeacon)
		{
			int cnt = 0;
			for (int i = minX; i <= maxX; i++)
			{
				Point p(i, y);
				bool found = false;
				for (auto sensor : sensors)
				{
					if (getTaxiDist(p, sensor) <= distanceToNearestBeacon[sensor])
					{
						found = true;
						break;
					}
				}
				if (found && beacons.count(p)==0)
				{
					cnt++;
				}
				found = false;
			}

			return cnt;
		}

		int64_t getTuningfrequency(int maxCoord, int multiplier, std::unordered_map<Point, int64_t> distanceToNearestBeacon)
		{
			std::vector<int64_t> distances;
			std::vector<int64_t> bestDistances;
			std::vector<int64_t> distDiffs;
			for (int i = 0; i < sensors.size(); i++)
			{
				distances.push_back( 0);
				bestDistances.push_back(0);
				distDiffs.push_back(0);
			}
			int64_t tuningFreq = INT64_MAX;
			for (int64_t y = 0; y <= maxCoord; y++)
			{
				for (int64_t x = 0; x <= maxCoord; x++)
				{
					bool found = false;
					
					Point p(x, y);
					int i = 0;
					for (i = 0; i < sensors.size(); i++)
					{
						bool sensed = false;
						int64_t closestBeasonDist = distanceToNearestBeacon[sensors[i]];
						int64_t taxiDist = getTaxiDist(p, sensors[i]);

						distances[i] = taxiDist;
						bestDistances[i] = closestBeasonDist;
						int64_t distDiff = closestBeasonDist - taxiDist;
						distDiffs[i] = distDiff;
						if (distDiff>=0)
						{

							x += distDiff;
							found = true;
							break;
						}

					}
					if (!found)
					{
						for (int i = 0; i < sensors.size(); i++)
						{
							std::cout << "d: " << getTaxiDist(p, sensors[i]) << " b: " << distanceToNearestBeacon[sensors[i]] << " diff: " << getTaxiDist(p, sensors[i]) - distanceToNearestBeacon[sensors[i]] << std::endl;
						}
						tuningFreq=std::min(tuningFreq, x * multiplier + y);
					}
				}
			}
			

			return tuningFreq;
		}
	};

}