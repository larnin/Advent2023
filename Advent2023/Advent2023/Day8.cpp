
#include <iostream>

#include "Helper.h"
#include "Day8.h"

void Day8_1()
{
	std::string data = ReadAll("Day8-1.txt");

	auto lines = Split(data, '\n');

	if (lines.size() < 1)
	{
		std::cout << "Error" << std::endl;
		return;
	}

	auto path = ReadPath(lines[0]);
	std::vector<Element8> elements;
	for (int i = 1; i < lines.size(); i++)
		elements.push_back(ReadElement(lines[i]));

	int startIndex = ElementIndex(elements, ToInt("AAA"));
	int endIndex = ElementIndex(elements, ToInt("ZZZ"));
	if (startIndex == -1 || endIndex == -1)
	{
		std::cout << "Error" << std::endl;
		return;
	}

	int nbStep = 0;
	int index = startIndex;

	while (true)
	{
		int pathIndex = nbStep % path.size();

		unsigned int nextID = path[pathIndex] == Direction::left ? elements[index].left : elements[index].right;
		int nextIndex = ElementIndex(elements, nextID);
		if (nextIndex == -1)
		{
			std::cout << "Error" << std::endl;
			return;
		}

		nbStep++;

		if (nextIndex == endIndex)
			break;
		index = nextIndex;
	}

	std::cout << "Result Day 8 1 : " << nbStep << std::endl;
}

void Day8_2()
{
	std::string data = ReadAll("Day8-1.txt");

	auto lines = Split(data, '\n');

	if (lines.size() < 1)
	{
		std::cout << "Error" << std::endl;
		return;
	}

	auto path = ReadPath(lines[0]);
	std::vector<Element8> elements;
	for (int i = 1; i < lines.size(); i++)
		elements.push_back(ReadElement(lines[i]));

	std::vector<int> allIndexs;
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i].endWithA)
			allIndexs.push_back(i);
	}

	unsigned int nbStep = 0; 
	int pathIndex = nbStep % path.size();
	while (true)
	{
		unsigned int pathIndex = nbStep % path.size();

		for (int i = 0; i < allIndexs.size(); i++)
		{
			int nextID = path[pathIndex] == Direction::left ? elements[allIndexs[i]].left : elements[allIndexs[i]].right;
			int nextIndex = ElementIndex(elements, nextID);
			if (nextIndex == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			allIndexs[i] = nextIndex;
		}

		nbStep++;

		bool allZ = true;
		for (int i = 0; i < allIndexs.size(); i++)
		{
			if (!elements[allIndexs[i]].endWithZ)
			{
				allZ = false;
				break;
			}
		}

		if (allZ)
			break;
	}

	std::cout << "Result Day 8 2 : " << nbStep << std::endl;
}


std::vector<Direction> ReadPath(const std::string& path)
{
	std::vector<Direction> dirs;

	for (int i = 0; i < path.size(); i++)
	{
		if (path[i] == 'L')
			dirs.push_back(Direction::left);
		else if (path[i] == 'R')
			dirs.push_back(Direction::right);
	}

	return dirs;
}

Element8 ReadElement(const std::string& element)
{
	if (element.length() != 16)
		return {};

	Element8 e;
	auto str = element.substr(0, 3);
	e.endWithA = str[2] == 'A';
	e.endWithZ = str[2] == 'Z';
	e.src = ToInt(str.c_str());
	e.left = ToInt(element.substr(7, 3).c_str());
	e.right = ToInt(element.substr(12, 3).c_str());

	return e;
}

unsigned int ToInt(const char* s)
{
	int multiplier = 'Z' - 'A' + 1;

	return ((s[0] - 'A') * multiplier + (s[1] - 'A')) * multiplier + (s[2] - 'A');
}

int ElementIndex(std::vector<Element8> elements, unsigned int id)
{
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		if (elements[i].src == id)
			return i;
	}
	return -1;
}