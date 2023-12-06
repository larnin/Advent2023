#include <iostream>

#include "Day6.h"

Run runs[] = { {59, 430}, {70, 1218}, {78, 1213}, {78, 1276} };
int nbRuns = sizeof(runs) / sizeof(Run);

void Day6_1()
{
	unsigned int total = 1;
	for (int i = 0; i < nbRuns; i++)
		total *= PlayRun(runs[i]);

	std::cout << "Result Day 6 1 : " << total << std::endl;
}

Run run2 = { 59707878, 430121812131276 };

void Day6_2()
{
	unsigned long long total = PlayRun(run2);
	std::cout << "Result Day 6 2 : " << total << std::endl;
}

unsigned long long PlayRun(const Run& r)
{
	int nbRun = 0;
	for (unsigned long long i = 0; i < r.time; i++)
	{
		unsigned long long distance = i * (r.time - i);
		if (distance > r.distance)
			nbRun++;
	}
	return nbRun;
}