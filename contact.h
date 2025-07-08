/***********************************************************************
 *  File Name   : contact.h
 *  Description : Header file for the Contact Management System.
 *                Contains structure definitions and function declarations
 *                used for managing contact data.
 *
 *                Structures:
 *                - Contact
 *                - AddressBook
 *
 *                Functions:
 *                - createContact()
 *                - searchContact()
 *                - editContact()
 *                - deleteContact()
 *                - listContacts()
 *                - initialize()
 *                - saveContactsToFile()
 *
 *  Author      : Pankaj Kumar
 *  Roll No     : 25008_018
 *  Date        : 02-Jul-2025
 ***********************************************************************/

#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>

#define MAX_CONTACTS 100

typedef struct Contact{
    char name[40];
    char phone[15];
    char email[40];
    char address[40];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
