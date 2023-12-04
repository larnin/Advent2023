
#include <fstream>
#include <sstream>

#include "Helper.h"

std::string ReadAll(const std::string & filename)
{
	auto path = GetRelativePathToFile(filename);

	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

std::string GetRelativePathToFile(const std::string & filename)
{
	return ".\\Datas\\" + filename;
}

std::vector<std::string> Split(const std::string& str, char separator)
{
	std::vector<std::string> strs;

	size_t index = 0;

	do
	{
		size_t nextIndex = str.find(separator, index);

		if (nextIndex == std::string::npos)
		{
			strs.push_back(str.substr(index));
			index = nextIndex;
		}
		else
		{
			if (nextIndex - index >= 1)
				strs.push_back(str.substr(index, nextIndex - index));

				index = nextIndex + 1;
				if (index >= str.size())
					index = std::string::npos;
		}

	} while (index != std::string::npos);

	return strs;
}