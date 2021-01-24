//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101412203
// Email:          hpnpham@myseneca.ca
// Section:        NOO
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// New method //

#include <stdio.h>
int main(void)
{
	// Vars: current coin denomination and total remaining as cents
	int coins, remaining;
	// Vars: calculated GST and entered amount by user
	double GST, amtDue; 
	// Initialize all values

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amtDue);

	GST = amtDue * 0.13; // calculate and show GST amount
	amtDue += GST; // add the GST to the amtDue to get total value after tax 
	printf("GST %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", amtDue);

	// Convert everything to CENTS by multiplying 100
	// *NOTE: add 0.005 first when casting a float/ double to an integer when truncation occurs
	remaining = (amtDue + 0.005) * 100;

	// Loonies/ Dollars: divided by 100
	coins = remaining / 100; // Number of loonies 
	remaining %= 100; // remainder left
	printf("Loonies required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);

	// Quarters: divided by 25
	coins = remaining / 25; // Number of quarters
	remaining %= 25; // Update remainder
	printf("Quarters required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);

	// Dimes: divided by 10
	coins = remaining / 10; // Number of dimes
	remaining %= 10; //Update remainder
	printf("Dimes required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);

	// Nickes: divided by 5
	coins = remaining / 5; // Number of nickels
	remaining %= 5; // Update remainder
	printf("Nickels required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);

	// Pennies: divided by 1...No need to do
	coins = remaining;
	remaining = 0;
	printf("Pennies required: %d, balance owing $%.2lf\n", coins, (double)remaining / 100);

	return 0;


}

























/* Old method
#include <stdio.h>
int main(void)
{
	double amountOwing, totalDue;
	float GST, bl1, bl2, bl3, bl4, bl5; 
	int intDue, loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountOwing);

	GST = amountOwing * .13 + .005;
	printf("GST: %.2f\n", GST);
	
	totalDue = amountOwing + GST;
	printf("Balance owing: $%.2lf\n", totalDue);

	intDue = (totalDue * 100) + 0.5;

	loonies = intDue / 100;
	intDue = intDue % 100; 
	bl1 = intDue / 100.0;
	printf("Loonies required: %d, balance owing $%.2f\n", loonies, bl1);

	quarters = intDue / 25; 
	intDue = intDue % 25; 
	bl2 = intDue / 100.0;
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, bl2);

	dimes = intDue / 10; 
	intDue = intDue % 10; 
	bl3 = intDue / 100.0;
	printf("Dimes required: %d, balance owing $%.2f\n", dimes, bl3);

	nickels = intDue / 5; 
	intDue = intDue % 5; 
	bl4 = intDue / 100.0;
	printf("Nickels required: %d, balance owing $%.2f\n", nickels, bl4);

	pennies = intDue / 1; 
	intDue = intDue % 1; 
	bl5 = intDue / 100.0;
	printf("Pennies required: %d, balance owing $%.2f\n", pennies, bl5);

	return 0;
} */