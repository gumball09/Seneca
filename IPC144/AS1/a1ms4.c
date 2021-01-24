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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "contacts.h"

int main(void)
{
    struct Name name = { { { 0 } } };
    struct Address address = { { 0 } };
    struct Numbers numbers = { { { 0 } } } ;
    struct Contact contact = { { { 0 } } };

    printf("Contact Management System\n");
    printf("=========================\n");

    printf("name: %ld   address: %ld    numbers: %ld\n\n", sizeof(name), sizeof(address), sizeof(numbers));
    printf("size struct contacT: %ld\n\n", sizeof(name) + sizeof(address) + sizeof(numbers));
    printf("size struct contact: %ld\n\n", sizeof(contact));

    // call function getName to store values for Name member
    getName(&contact.name);
    
    // call function getAddress to store values for Address member
    getAddress(&contact.address);

    // call function getNumbers to store values for Numbers member
    getNumbers(&contact.numbers);

    printf("\n");

    printf("Contact Details\n");
    printf("===============\n");
    printf("Name Details\n");
    printf("------------\n");
    printf("First name: %s\n", contact.name.firstName);
    printf("Middle initial(s): %s\n", contact.name.middleInitial);
    printf("Last name: %s\n\n", contact.name.lastName);

    printf("Address Details\n");
    printf("---------------\n");
    printf("Street number: %d\n", contact.address.streetNumber);
    printf("Street name: %s\n", contact.address.street);
    printf("Apartment: %d\n", contact.address.apartmentNumber);
    printf("Postal code: %s\n", contact.address.postalCode);
    printf("City: %s\n\n", contact.address.city);

    printf("Phone Numbers\n");
    printf("-------------\n");
    printf("Cell phone number: %s\n", contact.numbers.cell);
    printf("Home phone number: %s\n", contact.numbers.home);
    printf("Business phone number: %s\n\n", contact.numbers.business);

    printf("Structure test for Contact using functions done!\n");
    
    return 0;
}