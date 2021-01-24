// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

//--------------------------------
// Structure Types (AS1 - MS4)
//--------------------------------

// Structure type Name declaration
struct Name
{
    char firstName[30 + 1];
    char middleInitial[6 + 1];
    char lastName[35 + 1];
};

// Structure type Address declaration
struct Address
{
    int streetNumber;
    char street[40 + 1];
    int apartmentNumber;
    char postalCode[7 + 1];
    char city[40 + 1];
};

// Structure type Numbers declaration
struct Numbers
{
    char cell[10 + 1];
    char home[10 + 1];
    char business[10 + 1];
};


// Structure type Contact declaration 
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes (AS1 - MS4)
//--------------------------------

// Get and store from standard input the values for Name
void getName(struct Name* name);

// Get and store from standard input the values for Address
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers);

//--------------------------------
// Function Prototypes (AS2 - MS1+2)
//--------------------------------

// Get Contact Info (including name, address, numbers)
void getContact(struct Contact* contact);



// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
