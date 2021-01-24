//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101402213
// Email:          hpnphamD@myseneca.ca
// Section:        NOO
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX 10
#define MIN 3
int main(void)
{
	int numDays, day;
	int i, j, keepGoing;
	int highs[MAX] = { 0 }, lows[MAX] = { 0 };
	int lowestTemp, highestTemp, dayLowest, dayHighest;
	int reqDay, totalLow, totalHigh;
	double avgTemp;

	numDays = 0;
	dayLowest = dayHighest = 0;
	lowestTemp = 41; 
	highestTemp = -41;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	do
	{
		printf("Please enter the number of days, between %d and %d, inclusive: ", MIN, MAX);
		scanf("%d", &numDays);
		printf("\n");

		if (numDays < MIN || numDays > MAX)
		{
			printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MIN, MAX);
			scanf("%d", &numDays);
			printf("\n");
		}
	} while (numDays < MIN || numDays > MAX);

	for (day = 0; day < numDays; day++)
	{
		printf("Day %d - High: ", day + 1);
		scanf("%d", &highs[day]);

		printf("Day %d - Low: ", day + 1);
		scanf("%d", &lows[day]);
	}

	printf("\n");
	printf("Day  Hi  Low\n");

	for (i = 0; i < day; i++)
	{
		printf("%d %4d %5d\n", i + 1, highs[i], lows[i]);

		if (lows[i] < lowestTemp) // initialize lowestTemp = 41, so if lows[i] < lowestTemp --> update lowestTemp = lows[i]
									// If lowestTemp = 0, and in case lows[i] > lowestTemp --> the value for lowestTemp will remain 0 (not updated correctly)
									// so make lowesTemp = 41 to make sure that whatever the first input is (say 5), it is always < 41 and that the lowestTemp is updated to that first value (now lowestTemp = 5), next check the second input lows[i], if lows[i] is < lowestTemp (say 1) --> lowestTemp = lows[i] (now lowestTemp = 1) and continues
		{
			lowestTemp = lows[i]; // initialize highestTemp = -41, so if highs[i] > highestTemp --> update highestTemp = highs[i]
									// If highestTemp = 0, and in case highs[i] < highestTemp --> the value for highestTemp will remain 0 (not updated correctly)
									// so make highestTemp = -41 to make sure that whatever the first input is (say -5), it is always > -41 and that the highestTemp is updated to that first value (now highestTemp = -5), next check the second input highs[i], if highs[i] > highestTemp (say 2) --> highestTemp = highs[i] (now highestTemp = 2 and continues
			dayLowest = i + 1;
		}

		if (highs[i] > highestTemp)
		{
			highestTemp = highs[i];
			dayHighest = i + 1;
		}
	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highestTemp, dayHighest);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, dayLowest);
	printf("\n");


	do
	{
		reqDay = 0;
		totalLow = 0;
		totalHigh = 0;
		avgTemp = 0.0;

		do
		{
			printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numDays);
			scanf("%d", &reqDay);
			printf("\n");

			if ((reqDay > numDays) || (reqDay == 0))
			{
				keepGoing = 1;
				do
				{
					printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", numDays);
					scanf("%d", &reqDay);
					printf("\n");

					if (reqDay < 0)
					{
						printf("Goodbye!\n");
						keepGoing = 0;
					}
				} while ((reqDay > numDays) || (reqDay == 0));

			}
			else if (reqDay < 0)
			{
				printf("Goodbye!\n");
			}

		} while ((reqDay > numDays) || (reqDay == 0));

		if (reqDay > 0 && reqDay <= numDays)
		{
			for (j = 0; j < reqDay; j++)
			{
				totalHigh += highs[j];
				totalLow += lows[j];
				avgTemp = (double)(totalHigh + totalLow) / (reqDay * 2.0);
			}

			printf("The average temperature up to day %d is: %.2lf\n", reqDay, avgTemp);
			printf("\n");
		}

	} while (reqDay > 0 && reqDay <= numDays && keepGoing == 1);

	return 0;
}