
#include <iostream>

#include "Helper.h"

#include "Day2.h"


void Day2_1()
{
	std::string data = ReadAll("Day2-1.txt");

	auto lines = Split(data, '\n');

	int sum = 0;

	for (const auto& l : lines)
	{
		int index = 0;
		if (IsGamePossible(l, index))
			sum += index;
	}

	std::cout << "Result Day 2 1 : " << sum << std::endl;
}

void Day2_2()
{

}

bool IsGamePossible(const std::string& game, int & gameIndex)
{
	const int nbRed = 12;
	const int nbGreen = 13;
	const int nbBlue = 14;

	auto tokens = Split(game, ' ');
	if (tokens.size() < 2)
		return false;

	gameIndex = std::stoi(tokens[1]);

	for (size_t i = 2; i < tokens.size(); i += 2)
	{
		if (tokens.size() <= i + 1)
			continue;

		int value = std::stoi(tokens[i]);

		if (tokens[i + 1][0] == 'r' && value > nbRed)
			return false;
		if (tokens[i + 1][0] == 'g' && value > nbGreen)
			return false;
		if (tokens[i + 1][0] == 'b' && value > nbBlue)
			return false;
	}

	return true;
}