/* -------------------------------------------
Name: Pham Huynh Phuong Nghi
Student number: 101412203
Email: hpnpham@myseneca.ca
Section: NOO
Date: Oct 30th, 2020
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

// Structure type Name declaration (Milestone 1) 
struct Name 
{
    char firstName[30+1];
    char middleInitial[6+1];
    char lastName[35+1];
};

// Structure type Address declaration (Milestone 1)
struct Address 
{
    int streetNumber;
    char street[40+1];
    int apartmentNumber;
    char postalCode[7+1];
    char city[40+1];
};

// Structure type Numbers declaration (Milestone 1)
struct Numbers
{
    char cell[10+1];
    char home[10+1];
    char business[10+1];
};

// Structure type Contact declaration (Milestone 3)
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

// ====== Function Prototypes (Milestone 4) =======

// Get and store from standard input the values for Name
void getName(struct Name *);

// Get and store from standard input the values for Address
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *);
