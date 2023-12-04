#pragma once

#include <vector>
#include <string>

struct Card
{
	unsigned int id = 0;

	std::vector<int> winningNumbers;
	std::vector<int> numbers;

	int score = 0;
	int cardCount = 1;
};

void Day4_1();
void Day4_2();

int ScoreOfCard(const Card& c);
int WeightOfCard(const Card& c);
Card LoadOneCard(const std::string& data);
void LoadNumberList(const std::string& data, std::vector<int>& list);
