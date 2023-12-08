
#include <iostream>
#include <algorithm>

#include "Helper.h"

#include "Day7.h"

void PrintHandPower(int power)
{
	if (power == 7)
		std::cout << "Five of a kind ";
	else if (power == 6)
		std::cout << "Four of a kind ";
	else if (power == 5)
		std::cout << "Full house ";
	else if (power == 4)
		std::cout << "Three of a kind ";
	else if(power == 3)
		std::cout << "Two pair ";
	else if (power == 2)
		std::cout << "One pair ";
	else if (power == 1)
		std::cout << "High card ";
}

void PrintCards(const Hand& h)
{
	for (const auto& c : h.cards)
		std::cout << c << "\t";
	std::cout << std::endl;
}

void Day7_1()
{
	std::string data = ReadAll("Day7-1.txt");

	auto lines = Split(data, '\n');

	std::vector<Hand> hands;
	for (const auto& l : lines)
		hands.push_back(ReadHand(l));

	std::sort(hands.begin(), hands.end(), Comp1);

	unsigned int score = 0;
	for (int i = 0; i < hands.size(); i++)
	{
		//PrintHandPower(GetHandPower1(hands[i]));
		//PrintCards(hands[i]);
		score += hands[i].bid * (i + 1);
	}
		

	std::cout << "Result Day 7 1 : " << score << std::endl;
}

void Day7_2()
{
	std::string data = ReadAll("Day7-1.txt");

	auto lines = Split(data, '\n');

	std::vector<Hand> hands;
	for (const auto& l : lines)
		hands.push_back(ReadHand(l));

	std::sort(hands.begin(), hands.end(), Comp2);

	unsigned int score = 0;
	for (int i = 0; i < hands.size(); i++)
		score += hands[i].bid * (i + 1);

	std::cout << "Result Day 7 2 : " << score << std::endl;
}

Hand ReadHand(const std::string& line)
{
	auto parts = Split(line, ' ');
	if (parts.size() != 2)
		return {};

	Hand h;
	h.bid = std::stoi(parts[1]);

	for (const auto& c : parts[0])
	{
		if (c >= '0' && c <= '9')
			h.cards.push_back(c - '0');
		else if (c == 'T')
			h.cards.push_back(10);
		else if (c == 'J')
			h.cards.push_back(11);
		else if (c == 'Q')
			h.cards.push_back(12);
		else if (c == 'K')
			h.cards.push_back(13);
		else if (c == 'A')
			h.cards.push_back(14);
		else h.cards.push_back(0);
	}

	return h;
}

const int jokerValue = 11;
const int nbPower = 15;

bool Comp1(const Hand& a, const Hand& b)
{
	int pow1 = GetHandPower1(a);
	int pow2 = GetHandPower1(b);

	if (pow1 == pow2)
	{
		for (int i = 0; i < a.cards.size() && i < b.cards.size(); i++)
		{
			if (a.cards[i] != b.cards[i])
				return a.cards[i] <= b.cards[i];
		}
	}
	return pow1 <= pow2;
}

bool Comp2(const Hand& a, const Hand& b)
{
	int pow1 = GetHandPower2(a);
	int pow2 = GetHandPower2(b);

	if (pow1 == pow2)
	{
		for (int i = 0; i < a.cards.size() && i < b.cards.size(); i++)
		{
			int cA = a.cards[i];
			int cB = b.cards[i];
			if (cA == jokerValue) cA = 0;
			if (cB == jokerValue) cB = 0;

			if (cA != cB)
				return cA <= cB;
		}
	}
	return pow1 <= pow2;
}

int GetHandPower1(const Hand& h)
{
	int data[nbPower] = { 0 };
	for (const auto& c : h.cards)
		data[c]++;

	std::sort(data, data + nbPower);
	int number1 = data[nbPower - 1];
	int number2 = data[nbPower - 2];

	if (number1 == 5)
		return 7;
	if (number1 == 4)
		return 6;
	if (number1 == 3 && number2 == 2)
		return 5;
	if (number1 == 3)
		return 4;
	if (number1 == 2 && number2 == 2)
		return 3;
	if (number1 == 2)
		return 2;
	return 1;
}

int GetHandPower2(const Hand& h)
{
	int data[nbPower] = { 0 };
	for (const auto& c : h.cards)
		data[c]++;

	int nbJoker = data[jokerValue];
	data[jokerValue] = 0;

	std::sort(data, data + nbPower);
	int number1 = data[nbPower - 1] + nbJoker;
	int number2 = data[nbPower - 2];

	if (number1 == 5)
		return 7;
	if (number1 == 4)
		return 6;
	if (number1 == 3 && number2 == 2)
		return 5;
	if (number1 == 3)
		return 4;
	if (number1 == 2 && number2 == 2)
		return 3;
	if (number1 == 2)
		return 2;
	return 1;
}