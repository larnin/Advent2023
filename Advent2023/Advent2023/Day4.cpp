
#include <iostream>

#include "Helper.h"

#include "Day4.h"

void Day4_1()
{
	std::string data = ReadAll("Day4-1.txt");

	auto allLines = Split(data, '\n');

	std::vector<Card> cards;

	for (const auto& l : allLines)
		cards.push_back(LoadOneCard(l));

	int sum = 0;
	for (const auto& c : cards)
		sum += WeightOfCard(c);

	std::cout << "Result Day 4 1 : " << sum << std::endl;
}

void Day4_2()
{
	std::string data = ReadAll("Day4-1.txt");

	auto allLines = Split(data, '\n');

	std::vector<Card> cards;

	for (const auto& l : allLines)
		cards.push_back(LoadOneCard(l));

	for (auto& c : cards)
		c.score = ScoreOfCard(c);

	for (int i = 0; i < cards.size(); i++)
	{
		const auto c = cards[i];
		for (int j = i + 1; j < cards.size() && j <= c.score + i; j++)
			cards[j].cardCount += c.cardCount;
	}

	int sum = 0;
	for (const auto& c : cards)
		sum += c.cardCount;

	std::cout << "Result Day 4 2 : " << sum << std::endl;
}

int ScoreOfCard(const Card& c)
{
	int value = 0;

	for (const auto& n : c.numbers)
	{
		if (std::find(c.winningNumbers.begin(), c.winningNumbers.end(), n) != c.winningNumbers.end())
			value++;
	}
	return value;
}

int WeightOfCard(const Card& c)
{
	int value = 0;

	for (const auto& n : c.numbers)
	{
		if (std::find(c.winningNumbers.begin(), c.winningNumbers.end(), n) != c.winningNumbers.end())
		{
			if (value == 0)
				value = 1;
			else value *= 2;
		}
	}
	return value;
}

Card LoadOneCard(const std::string& data)
{
	auto parts = Split(data, ':');
	if (parts.size() < 2)
		return {};

	Card c;
	{
		auto cardParts = Split(parts[0], ' ');
		if (cardParts.size() >= 2)
			c.id = std::stoi(cardParts[1]);
	}

	auto numbers = Split(parts[1], '|');
	if (numbers.size() >= 2)
	{
		LoadNumberList(numbers[0], c.winningNumbers);
		LoadNumberList(numbers[1], c.numbers);
	}

	return c;
}

void LoadNumberList(const std::string& data, std::vector<int>& list)
{
	auto numbers = Split(data, ' ');

	for (const auto& n : numbers)
		list.push_back(std::stoi(n));
}