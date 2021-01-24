//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101402213
// Email:          hpnpham@myseneca.ca
// Section:        NOO
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#define NUMS 3
#include <stdio.h>
int main(void)
{
	int day, hightemp, lowtemp, totalhigh, totallow;
	
	totalhigh = totallow = 0; 
	
	printf("---=== IPC Temperature Analyzer ===---\n");

	for (day = 0; day < NUMS; day++)
	{
		do 
		{
			printf("Enter the high value for day %d: ", day+1);
			scanf("%d", &hightemp);
			printf("\n");
			printf("Enter the low value for day %d: ", day+1);
			scanf("%d", &lowtemp);
			printf("\n");
			if (hightemp < lowtemp || hightemp > 40 || lowtemp < -40)
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
		} while (hightemp < lowtemp || hightemp > 40 || lowtemp < -40);
		
		totalhigh += hightemp;
		totallow += lowtemp;
	}
	
	printf("The average (mean) temperature was: %.2lf\n", (totalhigh + totallow) / (NUMS * 2.0));

		return 0;
}