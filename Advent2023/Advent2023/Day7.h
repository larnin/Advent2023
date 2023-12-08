#pragma once

#include <vector>

struct Hand
{
	std::vector<int> cards;
	int bid;
};

void Day7_1();
void Day7_2();

Hand ReadHand(const std::string& line);

bool Comp1(const Hand& a, const Hand& b);
bool Comp2(const Hand& a, const Hand& b);

int GetHandPower1(const Hand& h);
int GetHandPower2(const Hand& h);