
#include <iostream>
#include "Day1.h"
#include "Day2.h"

#define DAY 2

int main()
{
#if  DAY == 1
	Day1_1();
	Day1_2();
#elif DAY == 2
	Day2_1();
	Day2_2();
#endif

	//wait before closing window
	int i = getchar();
}
