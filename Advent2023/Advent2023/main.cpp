
#include <iostream>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"

#define DAY 5

int main()
{
#if  DAY == 1
	Day1_1();
	Day1_2();
#elif DAY == 2
	Day2_1();
	Day2_2();
#elif DAY == 3
	Day3_1();
	Day3_2();
#elif DAY == 4
	Day4_1();
	Day4_2(); 
#elif DAY == 5
	Day5_1();
	Day5_2();
#elif DAY == 6
	Day6_1();
	Day6_2();
#endif

	//wait before closing window
	int i = getchar();
}
