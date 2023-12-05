#pragma once

#include <vector>

struct Range
{
	unsigned int rangeStart = 0;
	unsigned int rangeLength = 0;
	unsigned int destinationStart = 0;
};

struct Table
{
	std::vector<Range> ranges;
};

void Day5_1();
void Day5_2();

unsigned int Convert(const Table& table, unsigned int value);
unsigned int ConvertInverse(const Table& table, unsigned int value);

std::vector<unsigned int> ReadSeeds(const std::string& data);
Table ReadTable(const std::vector<std::string>& lines, unsigned int startIndex, unsigned int& outIndex);
Range ReadRange(const std::string& line);

Table FlatenTables(const Table& first, const Table& second);