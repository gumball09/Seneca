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
// |        contents here...                         |
// +-------------------------------------------------+

// +===============================+
// |           MS1 & MS2           |
// +===============================+

// Clear the standard input buffer:
void clearKeyboard(void);

// pause until <enter>:
void pause(void);

// get & validate integer:
int getInt(void);

// getIntInRange:
int getIntInRange(int min, int max);

// yes/no validation:
int yes(void);

// display menu:
int menu(void);

// display contactManagerSystem:
void contactManagerSystem(void);

// +===============================+
// |           MS3 & MS4           |
// +===============================+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader
void displayContactHeader();

// displayContactFooter:
void displayContactFooter(int count);

// displayContact:
void displayContact(const struct Contact* contact);

// displayContacts:
void displayContacts(const struct Contact* contact, int size);

// searchContacts:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
void addContact(struct Contact contacts[], int size);

// updateContact:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
void deleteContact(struct Contact contacts[], int size);

// sortContacts
void sortContacts(struct Contact contacts[], int size);
