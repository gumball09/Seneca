//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: ###
// Email:          ###@myseneca.ca
// Section:        ###
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double amountOwing, totalDue, gst; 
	int intDue, loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountOwing);

	gst = amountOwing * .13 + .005;
	printf("GST: %.2f\n", (float)gst);

	totalDue = amountOwing + gst;
	printf("Balance owing: $%.2lf\n", totalDue);

	intDue = (totalDue * 100) + 0.5;

	loonies = intDue / 100;
	intDue = intDue % 100;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, (float)intDue/100);

	quarters = intDue / 25;
	intDue = intDue % 25;
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, (float)intDue/100);

	dimes = intDue / 10;
	intDue = intDue % 10;
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, (float)intDue/100);

	nickels = intDue / 5;
	intDue = intDue % 5;
	printf("Nickels required: %d, balance owing $%.2f\n", nickels, (float)intDue/100);

	pennies = intDue / 1;
	intDue = intDue % 1;
	printf("Pennies required: %d, balance owing $%.2f\n", pennies, (float)intDue);

	return 0;
}
