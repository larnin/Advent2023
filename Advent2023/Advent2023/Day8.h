#pragma once

#include <vector>

struct Element8
{
	bool endWithA;
	bool endWithZ;
	unsigned int src;
	unsigned int left;
	unsigned int right;
};

enum class Direction
{
	left,
	right,
};

void Day8_1();
void Day8_2();

std::vector<Direction> ReadPath(const std::string& path);
Element8 ReadElement(const std::string& element);

unsigned int ToInt(const char* s);

int ElementIndex(std::vector<Element8> elements, unsigned int id);