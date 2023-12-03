
#include <iostream>
#include <limits>

#include "Helper.h"
#include "Matrix.h"

#include "Day3.h"

void Day3_1()
{
	std::string data = ReadAll("Day3-1.txt");

	auto mat = FillMatrix(data);

	unsigned int sum = 0;

	for (unsigned int j = 0; j < mat.Height(); j++)
	{
		for (unsigned int i = 0; i < mat.Width(); i++)
		{
			unsigned int value = 0;
			unsigned int size = 0;
			bool haveSymbol = NumberHaveASymbolAround(mat, i, j, value, size);

			if (haveSymbol)
				sum += value;
			if (size > 1)
				i += size - 1;
		}
	}

	std::cout << "Result Day 3 1 : " << sum << std::endl;
}

void Day3_2()
{
	std::string data = ReadAll("Day3-1.txt");

	auto mat = FillMatrix(data);

	unsigned int sum = 0;

	for (unsigned int j = 0; j < mat.Height(); j++)
	{
		for (unsigned int i = 0; i < mat.Width(); i++)
		{
			if (mat(i, j) == Element::gear)
			{
				sum += ProcessGear(mat, i, j);
			}
		}
	}

	std::cout << "Result Day 3 2 : " << sum << std::endl;
}

unsigned int ProcessGear(const Matrix<Element>& mat, unsigned int x, unsigned int y)
{
	unsigned int number1 = 0;
	unsigned int number1X = 0;
	unsigned int number1Y = 0;
	unsigned int number2 = 0;
	unsigned int number2X = 0;
	unsigned int number2Y = 0;

	for (int i = (int)x - 1; i <= (int)x + 1; i++)
	{
		for (int j = (int)y - 1; j <= (int)y + 1; j++)
		{
			if (i < 0 || j < 0 || i >= (int)mat.Width() || j >= (int)mat.Height())
				continue;

			unsigned int startX = GetNumberStartAt(mat, i, j);
			if (startX >= mat.Width())
				continue;

			if (number1 >= 0 && startX == number1X && j == number1Y)
				continue;

			if (number2 >= 0 && startX == number2X && j == number2Y)
				continue;

			unsigned int number = GetNumberAt(mat, startX, j);

			if (number1 == 0)
			{
				number1 = number;
				number1X = startX;
				number1Y = j;
			}
			else if (number2 == 0)
			{
				number2 = number;
				number2X = startX;
				number2Y = j;
			}
			else return 0;
		}
	}

	return number1 * number2;
}

unsigned int GetNumberStartAt(const Matrix<Element>& mat, unsigned int x, unsigned int y)
{
	Element v = mat(x, y);
	if (v == Element::empty || v == Element::symbol || v == Element::gear)
		return std::numeric_limits<unsigned int>::max();

	for (int i = 1; i <= x; i++)
	{
		Element v = mat(x - i, y);
		if (v == Element::empty || v == Element::symbol || v == Element::gear)
			return x - i + 1;
	}

	return 0;
}

unsigned int GetNumberAt(const Matrix<Element>& mat, unsigned int x, unsigned int y)
{
	unsigned int value = 0;
	for (unsigned int i = x; i < mat.Width(); i++)
	{
		Element v = mat(i, y);
		if (v == Element::empty || v == Element::symbol || v == Element::gear)
			return value;
		value = value * 10 + v;
	}
	return value;
}

bool NumberHaveASymbolAround(const Matrix<Element>& mat, unsigned int x, unsigned int y, unsigned int& value, unsigned int& size)
{
	Element v = mat(x, y);

	value = 0;
	size = 0;

	if (v == Element::empty || v == Element::symbol || v == Element::gear)
		return false;

	value = v;

	bool haveSymbol = false;

	for (int i = (int)x - 1; i <= (int)x + 1; i++)
	{
		for (int j = (int)y - 1; j <= (int)y + 1; j++)
		{
			if (i < 0 || j < 0 || i >= (int)mat.Width() || j >= (int)mat.Height())
				continue;

			if (mat(i, j) == Element::symbol || mat(i, j) == Element::gear)
			{
				haveSymbol = true;
				break;
			}
		}
		if (haveSymbol)
			break;
	}

	bool nextHaveSymbol = false;
	unsigned int nextValue = 0;
	unsigned int nextSize = 0;

	if (x + 1 < mat.Width())
		nextHaveSymbol = NumberHaveASymbolAround(mat, x + 1, y, nextValue, nextSize);

	value = nextValue + v * (int)std::pow(10.0f, nextSize);
	size = nextSize + 1;

	return haveSymbol || nextHaveSymbol;
}

Matrix<Element> FillMatrix(const std::string& data)
{
	auto lines = Split(data, '\n');

	if (lines.empty())
		return { 0, 0 };

	unsigned int width = lines[0].length();
	unsigned int height = lines.size();

	Matrix<Element> mat(width, height);

	for (unsigned int j = 0; j < height; j++)
	{
		for (unsigned int i = 0; i < width; i++)
		{
			char c = '.';
			if(i < lines[j].length())
				c = lines[j][i];

			if (c >= '0' && c <= '9')
				mat(i, j) = static_cast<Element>(Element::number_0 + c - '0');
			else if (c == '.')
				mat(i, j) = Element::empty;
			else if (c == '*')
				mat(i, j) = Element::gear;
			else mat(i, j) = Element::symbol;
		}
	}

	return mat;
}