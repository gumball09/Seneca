//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101402213
// Email:          hpnphamD@myseneca.ca
// Section:        NOO
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>
int main(void)
{
	// declare variables
	int numDays, day, i;
	int highs[MAX] = { 0 }, lows[MAX] = { 0 };

	numDays = 0;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	do
	{
		printf("Please enter the number of days, between 3 and 10, inclusive: ");
		scanf("%d", &numDays);
		printf("\n");

		if (numDays < 3 || numDays > 10)
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numDays);
		printf("\n");
	} while (numDays < 3 || numDays > 10);

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
		printf("%d %4d %5d\n", i+1, highs[i], lows[i]);
	}

	return 0;
}