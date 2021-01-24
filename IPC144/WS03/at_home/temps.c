//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101402213
// Email:          hpnpham@myseneca.ca
// Section:        NOO
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define NUMS 4
int main(void)
{
	int day, hightemp, lowtemp, totalhigh, totallow, highestTemp, lowestTemp, dayHighestTemp, dayLowestTemp;

	totalhigh = totallow = dayHighestTemp = dayLowestTemp = 0;
	highestTemp = -41; lowestTemp = 41;

	printf("---=== IPC Temperature Analyzer ===---\n");
	
	for (day = 0; day < NUMS; day++)
	{
		do
		{
			printf("Enter the high value for day %d: ", day + 1);
			scanf("%d", &hightemp);
			printf("\n");
			printf("Enter the low value for day %d: ", day + 1);
			scanf("%d", &lowtemp);
			printf("\n");

			if (hightemp < lowtemp || hightemp > 40 || lowtemp < -40)
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");

		} while (hightemp < lowtemp || hightemp > 40 || lowtemp < -40);

		if (hightemp > highestTemp)
		{	
			highestTemp = hightemp;
			dayHighestTemp = day+1; 
		}
		
		if (lowtemp < lowestTemp)
		{	
			lowestTemp = lowtemp;
			dayLowestTemp = day+1; 
		}
		
		totallow += lowtemp;
		totalhigh += hightemp;
	}
	
	printf("The average (mean) LOW temperature was: %.2lf\n", (double)totallow / NUMS);

	printf("The average (mean) HIGH temperature was: %.2lf\n", (double)totalhigh / NUMS);

	printf("The average (mean) temperature was: %.2lf\n", (totallow + totalhigh) / (NUMS * 2.0));

	printf("The highest temperature was %d, on day %d\n", highestTemp, dayHighestTemp);

	printf("The lowest temperature was %d, on day %d\n", lowestTemp, dayLowestTemp);

	return 0;
}