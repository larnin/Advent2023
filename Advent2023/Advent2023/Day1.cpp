
#include <iostream>

#include "Helper.h"

#include "Day1.h"

void Day1()
{
	std::string data = ReadAll("Day1-1.txt");

	auto lines = Split(data, '\n');

	int nb = 0;

	for (const auto& l : lines)
	{
		int value = GetFirstDigit(l) * 10 + GetLastDigit(l);
		nb += value;
	}

	std::cout << "Result " << nb << std::endl;
}

int GetFirstDigit(const std::string& line)
{
	for (const auto& c : line)
	{
		if (c >= '0' && c <= '9')
			return c - '0';
	}

	return 0;
}

int GetLastDigit(const std::string& line)
{
	for (auto it = line.rbegin(); it != line.rend(); ++it)
	{
		char c = *it;
		if (c >= '0' && c <= '9')
			return c - '0';
	}

	return 0;
}