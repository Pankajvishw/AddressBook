/***********************************************************************
 *  File Name   : populate.c
 *  Description : This file contains the function to populate the 
 *                Address Book with dummy contact data for testing 
 *                and demonstration purposes.
 *
 *  Author      : Pankaj Kumar
 *  Roll No     : 25008_018
 *  Date        : 02-Jul-2025
 *
 ***********************************************************************/

#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com", "Bangalore"},
    {"Alice Smith", "0987654321", "alice@example.com", "Mumbai"},
    {"Bob Johnson", "1112223333", "bob@company.com", "Hyderabad"},
    {"Carol White", "4445556666", "carol@company.com", "Delhi"},
    {"David Brown", "7778889999", "david@example.com", "Bangalore"},
    {"Eve", "6665554444", "eve1@example.com", "Pune"},
    {"Eve", "6665554445", "eve2@example.com", "Bangalore"},
    {"Eve", "6665554446", "eve3@example.com", "Bangalore"},
    {"Eve", "6665554447", "eve4@example.com", "Kolkata"},
    {"Eve", "6665554448", "eve5@example.com", "Bangalore"},
    {"Frank Miller", "3334445555", "frank@example.com", "Chennai"},
    {"Grace Wilson", "2223334444", "grace@example.com", "Ahmedabad"},
    {"Hannah Clark", "5556667777", "hannah@example.com", "Bangalore"},
    {"Ian Lewis", "8889990000", "ian@example.com", "Jaipur"},
    {"Pankaj", "9056372098", "pkv905637@gmail.com", "Jalandhar"},
    {"Harsh", "7019864253", "harshasagarboi26@gmail.com", "Bangalore"},
    {"Suhas", "7892835394", "suhas@example.com", "Bangalore"},
    {"Shankar", "9894132192", "Shankar@example.com", "Selam"},
};

void populateAddressBook(AddressBook* addressBook)
{
    //printf("%zu\n", sizeof(dummyContacts));
    int numDummyContacts = sizeof(dummyContacts) / sizeof(dummyContacts[0]);
    for (int i = 0; i < numDummyContacts; i++) {
        addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
    }
}
