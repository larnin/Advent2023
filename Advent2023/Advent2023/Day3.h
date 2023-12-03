#pragma once

#include <string>
#include "Matrix.h"

void Day3_1();
void Day3_2();

enum Element
{
	number_0,
	number_1,
	number_2,
	number_3,
	number_4,
	number_5,
	number_6,
	number_7,
	number_8,
	number_9,
	symbol,
	gear,
	empty,
};

Matrix<Element> FillMatrix(const std::string& data);

bool NumberHaveASymbolAround(const Matrix<Element>& mat, unsigned int x, unsigned int y, unsigned int& value, unsigned int& nextIndex);
unsigned int GetNumberStartAt(const Matrix<Element>& mat, unsigned int x, unsigned int y);
unsigned int GetNumberAt(const Matrix<Element>& mat, unsigned int x, unsigned int y);
unsigned int ProcessGear(const Matrix<Element>& mat, unsigned int x, unsigned int y);