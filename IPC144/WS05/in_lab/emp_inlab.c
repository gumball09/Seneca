//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101402213
// Email:          hpnpham@myseneca.ca
// Section:        NOO
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 2

struct Employee
{
	int id;
	int age;
	double salary;
};

int main(void)
{
	int option = 0;
	int i;
	int validEmp = 0; 

	struct Employee emp[SIZE] = { { 0 } };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do 
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
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

				if (validEmp < SIZE) 
				{
					printf("Enter Employee ID: ");
					scanf("%d", &emp[validEmp].id); 

					printf("Enter Employee Age: ");
					scanf("%d", &emp[validEmp].age);

					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[validEmp].salary);

					if (emp[validEmp].id > 0)
						validEmp++; 
				}
				else if (validEmp == SIZE)
				{
					printf("ERROR!!! Maximum Number of Employees Reached\n");
					printf("\n");
				}
				break;

			default:
				printf("ERROR: Incorrect Option: Try Again\n"); 
				printf("\n");
		}

	} while (option != 0);

	return 0;
}