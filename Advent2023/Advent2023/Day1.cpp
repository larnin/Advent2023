
#include <iostream>

#include "Helper.h"

#include "Day1.h"

void Day1_1()
{
	std::string data = ReadAll("Day1-1.txt");

	auto lines = Split(data, '\n');

	int nb = 0;

	for (const auto& l : lines)
	{
		int value = GetFirstDigit(l) * 10 + GetLastDigit(l);
		nb += value;
	}

	std::cout << "Result Day 1 1 : " << nb << std::endl;
}

void Day1_2()
{
	std::string data = ReadAll("Day1-1.txt");

	auto lines = Split(data, '\n');


	int nb = 0;

	for (const auto& l : lines)
	{
		int value = GetFirstDigitText(l) * 10 + GetLastDigitText(l);
		nb += value;
	}

	std::cout << "Result Day 1 2 : " << nb << std::endl;
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

std::string numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const int nbNumbers = 9;

int GetFirstDigitText(const std::string& line)
{
	int number = 0;
	size_t index = line.length();

	for (int i = 0; i < nbNumbers; i++)
	{
		auto numberIndex = line.find(numbers[i]);
		if (numberIndex == std::string::npos)
			continue;

		if (numberIndex < index)
		{
			index = numberIndex;
			number = i;
		}
	}

	for (size_t i = 0; i < index; i++)
	{
		char c = line[i];
		if (c >= '0' && c <= '9')
			return c - '0';
	}

	return number + 1;
}

int GetLastDigitText(const std::string& line)
{
	int number = 0;
	size_t index = 0;

	for (int i = 0; i < nbNumbers; i++)
	{
		auto numberIndex = line.rfind(numbers[i]);
		if (numberIndex == std::string::npos)
			continue;

		if (numberIndex >= index)
		{
			index = numberIndex;
			number = i;
		}
	}

	for (int i = line.length() - 1; i >= (int)index; i--)
	{
		char c = line[i];
		if (c >= '0' && c <= '9')
			return c - '0';
	}

	return number + 1;
}