#pragma once

#include <string>
#include <vector>

std::string ReadAll(const std::string & filename);

std::string GetRelativePathToFile(const std::string & filename);

std::vector<std::string> Split(const std::string& str, char separator);