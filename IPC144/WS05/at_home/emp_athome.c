//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101412203
// Email:          hpnpham@myseneca.ca
// Section:        NOO
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4

struct Employee
{
	int id;
	int age;
	double salary;
};

int main(void)
{
	int option = 0;
	int i, keepGoing;
	int validCounter = 0, stop;
	int inputID = 0;
	int removedID = 0;

	struct Employee emp[SIZE] = { { 0 } };

	printf("---=== EMPLOYEE DATA ===---\n");
	printf("\n");

	do
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}
			printf("\n");
			break;

		case 2:
			printf("Adding Employee\n");
			printf("===============\n");

			if (validCounter < SIZE) 
			{
				for (i = 0, stop = 0; i < SIZE && stop == 0; i++) 
				{
					if (emp[i].id < 1) 
					{
						printf("Enter Employee ID: ");
						scanf("%d", &emp[i].id);

						printf("Enter Employee Age: ");
						scanf("%d", &emp[i].age);

						printf("Enter Employee Salary: ");
						scanf("%lf", &emp[i].salary);

						if (emp[i].id > 0) 
						{
							validCounter++;
							stop = 1; 
						}
					}
				}
			}
			else if (validCounter == SIZE)
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			printf("\n");
			break;

		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");

			if (validCounter == 0)
			{
				printf("There are no employees to update salary!\n");
				printf("\n");
			}
			else
			{
				do
				{
					keepGoing = 1;

					inputID = 0;

					printf("Enter Employee ID: ");
					scanf("%d", &inputID);

					for (i = 0; i < validCounter && keepGoing == 1; i++)
					{
						if (inputID == emp[i].id)
						{
							printf("The current salary is %.2lf\n", emp[i].salary);
							printf("Enter Employee New Salary: ");
							scanf("%lf", &emp[i].salary);
							printf("\n");

							keepGoing = 0;

						}
					}

					if (keepGoing == 1)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}

				} while (keepGoing == 1);
			}
			

			break;

		case 4: 
			printf("Remove Employee\n");
			printf("===============\n");
		
			if (validCounter == 0)
			{
				printf("There are no employees to remove!\n");
				printf("\n");
			}
			else
			{
				do
				{
					keepGoing = 1;

					removedID = 0;

					printf("Enter Employee ID: ");
					scanf("%d", &removedID);

					for (i = 0; i < SIZE && keepGoing == 1; i++)
					{
						if (removedID == emp[i].id)
						{
							printf("Employee %d will be removed\n", removedID);
							printf("\n");

							emp[i].id = 0;

							validCounter--;
							keepGoing = 0;
						}
					}

					if (keepGoing == 1)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}

				} while (keepGoing == 1);
			}
			

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n");
			printf("\n");
		}

	} while (option != 0);

	return 0;
}