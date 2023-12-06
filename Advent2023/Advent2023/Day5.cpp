
#include <iostream>

#include "Helper.h"

#include "Day5.h"

void Day5_1()
{
	std::string data = ReadAll("Day5-1.txt");

	auto lines = Split(data, '\n');

	auto seeds = ReadSeeds(lines[0]);

	unsigned int index = 1;
	std::vector<Table> tables;
	while (index < lines.size())
		tables.push_back(ReadTable(lines, index, index));

	unsigned int minTarget = ~0;

	for (auto s : seeds)
	{
		for (const auto& t : tables)
		{
			s = Convert(t, s);
		}

		if (s < minTarget)
			minTarget = s;
	}

	std::cout << "Result Day 5 1 : " << minTarget << std::endl;
}

void Day5_2()
{
	std::string data = ReadAll("Day5-1.txt");

	auto lines = Split(data, '\n');

	auto seeds = ReadSeeds(lines[0]);

	unsigned int index = 1;
	std::vector<Table> tables;
	while (index < lines.size())
		tables.push_back(ReadTable(lines, index, index));

	unsigned int minTarget = ~0;

	for(unsigned int i = 0; i < seeds.size() / 2 ; i++)
	{
		unsigned int start = seeds[2ll * i];
		unsigned int size = seeds[2ll * i + 1];

		for (unsigned int j = start; j < start + size; j++)
		{
			unsigned int s = j;

			for (const auto& t : tables)
			{
				s = Convert(t, s);
			}

			if (s < minTarget)
				minTarget = s;
		}
	}

	std::cout << "Result Day 5 2 : " << minTarget << std::endl;
}

unsigned int Convert(const Table& table, unsigned int value)
{
	for (const auto& r : table.ranges)
	{
		if (r.rangeStart <= value && r.rangeStart + r.rangeLength > value)
			return r.destinationStart + (value - r.rangeStart);
	}

	return value;
}

unsigned int ConvertInverse(const Table& table, unsigned int value)
{
	for (const auto& r : table.ranges)
	{
		if (r.destinationStart <= value && r.destinationStart + r.rangeLength > value)
			return r.rangeStart + (value - r.destinationStart);
	}

	return value;
}

std::vector<unsigned int> ReadSeeds(const std::string& data)
{
	auto parts = Split(data, ':');
	if (parts.size() != 2)
		return {};

	auto seeds = Split(parts[1], ' ');

	std::vector<unsigned int> numbers;

	for (const auto& s : seeds)
		numbers.push_back(std::stoul(s));

	return numbers;
}

Table ReadTable(const std::vector<std::string>& lines, unsigned int startIndex, unsigned int& outIndex)
{
	if (lines[startIndex][lines[startIndex].length() - 1] == ':')
		startIndex++;

	Table t;
	for (int i = startIndex; i < lines.size(); i++)
	{
		const auto& l = lines[i];
		if (l[l.length() - 1] == ':')
		{
			outIndex = i;
			return t;
		}
		t.ranges.push_back(ReadRange(l));
	}

	outIndex = lines.size();
	return t;
}

Range ReadRange(const std::string& line)
{
	auto parts = Split(line, ' ');

	if (parts.size() != 3)
		return {};

	Range r;

	r.destinationStart = std::stoul(parts[0]);
	r.rangeStart = std::stoul(parts[1]);
	r.rangeLength = std::stoul(parts[2]);

	return r;
}

Table FlatenTables(const Table& first, const Table& second)
{
	return {};
}

//0 1 -- 1 69

//56 92 -- 93 96

//0 1 -- 1 56 -- 57 69 -- 69 92 -- 93 96