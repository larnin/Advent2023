#pragma once

#include <vector>
#include <assert.h>

template<typename T>
class Matrix
{
public:
	Matrix(unsigned int width, unsigned int height, T value = T{})
		:m_width(0), m_height(0)
	{
		Resize(width, height, value);
	}

	void Resize(unsigned int width, unsigned int height, T value = T{})
	{
		if (width == m_width && height == m_height)
			return;

		std::vector<T> newData(width * height, value);

		for (unsigned int i = 0; i < std::min(width, m_width); i++)
		{
			for (unsigned int j = 0; j < std::min(height, m_height); j++)
			{
				unsigned int oldIndex = PosToIndex(i, j);
				unsigned int newIndex = PosToIndex(i, j, width, height);

				newData[newIndex] = m_data[oldIndex];
			}
		}

		m_data = newData;
		m_width = width;
		m_height = height;
	}

	unsigned int Width() const { return m_width; }
	unsigned int Height() const { return m_height; }

	T& operator()(unsigned int x, unsigned int y)
	{
		return m_data[PosToIndex(x, y)];
	}

	const T& operator()(unsigned int x, unsigned int y) const
	{
		return m_data[PosToIndex(x, y)];
	}

private:
	static unsigned int PosToIndex(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
	{
		assert(x < width&& y < height);

		return x + y * width;

	}

	unsigned int PosToIndex(unsigned int x, unsigned int y) const
	{
		return PosToIndex(x, y, m_width, m_height);
	}

	std::vector<T> m_data;
	unsigned int m_width;
	unsigned int m_height;
};