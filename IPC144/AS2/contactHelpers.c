//==============================================
// Name:           Pham Huynh Phuong Nghi
// Student Number: 101412203
// Email:          hpnpham@myseneca.ca
// Section:        NOO
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n') // empty execution code block on purpose
	{
		; // do nothing
	}
}

// pause function definition:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard(); // call clearKeyboard function used for foolproof ENTER key (\n)
}

// getInt function definition goes here:
int getInt(void)
{
	char nL;
	int intReturn;
	int keepInt = 1;
	int returnValue; // return value of scanf()

	do
	{
		keepInt = 1;

		returnValue = scanf("%d%c", &intReturn, &nL);

		if (returnValue == 0) // incorrect 1st input
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else if (nL != '\n') // 1st input is int, 2nd input != '\n'
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else if (nL == '\n') // correct 1st & 2nd input
		{
			keepInt = 0;
		}

	} while (keepInt == 1);

	return intReturn;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int numInRange;
	int keepIntRange = 1;

	do
	{
		keepIntRange = 1;

		numInRange = getInt();

		if (numInRange < min || numInRange > max) // correct input but out of range
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
		else keepIntRange = 0; // correct input

	} while (keepIntRange == 1);

	return numInRange;
}

// yes function definition goes here:
int yes(void)
{
	char yesNo, nL;
	int numInt;
	int keepYesNo = 1;

	do
	{
		keepYesNo = 1;

		scanf("%c%c", &yesNo, &nL);

		if (nL != '\n') // 1st input is char, 2nd input != '\n'
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N') // incorrect 1st input, 2nd input == '\n'
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (yesNo == 'y' || yesNo == 'Y') // correct input for y/Y
		{
			numInt = 1;
			keepYesNo = 0;
		}
		else if (yesNo == 'n' || yesNo == 'N') // correct input for n/N
		{
			numInt = 0;
			keepYesNo = 0;
		}

	} while (keepYesNo == 1);

	return numInt;
}

// menu function definition goes here:
// use function getIntInRange to validate input in range [min - max]
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	
	return getIntInRange(0, 6); // return value of getIntRange()
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int keepSystem = 1;

	// intialize array contact
	struct Contact contacts[MAXCONTACTS] =

	{ 
		{ 
			{ "Rick",{ '\0' }, "Grimes" }, 
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" }, 
			{ "4161112222", "4162223333", "4163334444" } 
		},

		{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" }
		},

		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha",{ '\0' }, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" }
		},
	};


	do
	{
		keepSystem = 1;

		switch (menu()) // simplify by evaluating the condition (return value) of menu()
		{
			// exit
			case 0:
			{
				printf("\nExit the program? (Y)es/(N)o: ");
			
				if (yes() == 1) // 1 = y/Y
				{
					printf("\nContact Management System: terminated\n");
					keepSystem = 0;
				}
				else
				{
					printf("\n");
					keepSystem = 1;
				}
				break;
			}

			// display contacts
			case 1:
			{
				printf("\n");
				displayContacts(contacts, MAXCONTACTS);
				pause();
				printf("\n");

				break;
			}

			// add a contact
			case 2:
			{
				printf("\n");
				addContact(contacts, MAXCONTACTS);
				pause();
				printf("\n");

				break;
			}

			// update a contact
			case 3:
			{
				printf("\n");
				updateContact(contacts, MAXCONTACTS);
				pause();
				printf("\n");

				break;
			}

			// delete a contact
			case 4:
			{
				printf("\n");
				deleteContact(contacts, MAXCONTACTS);
				pause();
				printf("\n");

				break;
			}

			// search a contact based on cell phone number
			case 5:
			{
				printf("\n");
				searchContacts(contacts, MAXCONTACTS);
				pause();
				printf("\n");

				break;
			}

			// sort contacts based on cell phone number
			case 6:
			{
				printf("\n");
				sortContacts(contacts, MAXCONTACTS);
				pause();
				printf("\n");

				break;
			}

		}

	} while (keepSystem == 1);
}

// +===============================+
// |           MS3 & MS4           |
// +===============================+

void getTenDigitPhone(char phoneNum[])
{
	int keepEntering; 
	int i;
	int invalid;

	do
	{
		keepEntering = 1;
		
		scanf("%10s", phoneNum);
		clearKeyboard();
				
		
		if (strlen(phoneNum) == 10)
		{
			// find character(s) in input
			for (i = 0, invalid = 0; i < strlen(phoneNum) && invalid == 0; i++)
			{
				if (isdigit(phoneNum[i]) == 0) // 0 means char found
				{
					invalid = 1;
				}
			}

			if (invalid != 0)
			{
				printf("Enter a 10-digit phone number: ");
			}
			else if (invalid == 0) 
			{
				keepEntering = 0; 
			}
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
		}
		
	} while (keepEntering == 1);
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, found;
	int indexMatch;

	// loop through all records
	for (i = 0, found = 0; i < size && found == 0; i++)
	{
		if (contacts[i].numbers.cell[0] != '\0') 
		{
			// compare number entered with number in record
			if ((strcmp(contacts[i].numbers.cell, cellNum)) == 0) 
			{
				indexMatch = i; 
				found = 1; 
			}
		}
	}

	if (!found) 
	{
		indexMatch = -1; 
	}

	return indexMatch;
}


// displayContactHeader for displayContacts()
void displayContactHeader()
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter for displayContacts()
void displayContactFooter(int count) // count receives validCounter 
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count); 
}


// displayContact
void displayContact(const struct Contact* contact) 
{

	// DISPLAY CONTACT NAME
	// without middleInitials
	if (contact->name.middleInitial[0] == '\0') 
	{
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	// with middleInitials
	else
	{
		printf(" %s %s %s\n",
			contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}

	// DISPLAY CONTACT NUMBERS
	printf("    C: %-10s   H: %-10s   B: %-10s\n",
		contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	// DISPLAY CONTACT ADDRESS
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

	if (contact->address.apartmentNumber > 0) 
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode);

}


// displayContacts:
void displayContacts(const struct Contact* contact, int size) // size receives MAXCONTACTS
{
	int i;
	int validCounter = 0; 

	displayContactHeader();

	// DISPLAY DETAILS OF EACH VALID RECORD 
	for (i = 0; i < size; i++) 
	{
		if (strlen(contact[i].numbers.cell) > 0)  
		{
			displayContact(&contact[i]); 
			validCounter++; 
		}
	}

	displayContactFooter(validCounter); 

}


// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char numEntered[10 + 1] = { '\0' };
	int indexMatch;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(numEntered); 
	indexMatch = findContactIndex(contacts, MAXCONTACTS, numEntered);

	if (indexMatch != -1)
	{
		printf("\n");
		displayContact(&contacts[indexMatch]);
		printf("\n");
	}
	else 
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
}


// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i, found;
	
	for (i = 0, found = 0; i < size && found == 0; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0) // length = 0 means an empty record
		{
			getContact(&contacts[i]);

			printf("--- New contact added! ---\n\n");

			found = 1;
		}
	}

	if (!found)
	{
		printf("*** ERROR: The contact list is full! ***\n\n");
	}

}


// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char numUpdate[10 + 1] = { '\0' };
	int indexMatch;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(numUpdate);
	indexMatch = findContactIndex(contacts, MAXCONTACTS, numUpdate);

	if (indexMatch == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else if (indexMatch != -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[indexMatch]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1)
		{
			
			getName(&contacts[indexMatch].name); 
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
		{
			getAddress(&contacts[indexMatch].address); 
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
		{
			getNumbers(&contacts[indexMatch].numbers); 
		}

		printf("--- Contact Updated! ---\n\n");
	}
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char delContact[10 + 1] = { '\0' };
	int indexMatch;
	
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(delContact); 
	indexMatch = findContactIndex(contacts, MAXCONTACTS, delContact);

	if (indexMatch == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
	else if (indexMatch != -1)
	{
		printf("\nContact found:\n");

		displayContact(&contacts[indexMatch]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1)
		{
			contacts[indexMatch].numbers.cell[0] = '\0';
			contacts[indexMatch].numbers.home[0] = '\0';
			contacts[indexMatch].numbers.business[0] = '\0';
			printf("--- Contact deleted! ---\n\n");
		}
		else
		{
			printf("\n");
		}
	}
}

// sort contacts
void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	struct Contact tempPosition;
	
	
	for (i = 0; i <= size - 1; i++) 
	{
		for (j = i + 1; j <= size; j++)
		{
			// compare cell phone numbers of 2 consecutive VALID CONTACTS
			if (contacts[i].numbers.cell[0] != '\0' && contacts[j].numbers.cell[0] != '\0')
			{
				if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) 
				{
					tempPosition = contacts[j]; 
					contacts[j] = contacts[i];
					contacts[i] = tempPosition; 
				}
			}
		}
	}

	printf("--- Contacts sorted! ---\n\n");
}