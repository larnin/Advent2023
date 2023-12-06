#pragma once

struct Run
{
	unsigned long long time;
	unsigned long long distance;

	Run(unsigned long long _time, unsigned long long _distance) :time(_time), distance(_distance) {}
};

void Day6_1();
void Day6_2();

unsigned long long PlayRun(const Run& r);