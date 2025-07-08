/***********************************************************************
 *  File Name   : search.h
 *  Description : Header file for search-related operations in the 
 *                Contact Management System. Declares utility and 
 *                search functions to find contacts by name, phone 
 *                number, email, or address.
 *
 *                Functions:
 *                - line()
 *                - print_head()
 *                - print_data()
 *                - searchName()
 *                - searchPhone()
 *                - searchEmail()
 *                - searchAddress()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 02-Jul-2025
 ***********************************************************************/

#ifndef SEARCH_H
#define SEARCH_H

#include "contact.h"

void line();
void print_head();
void print_data(AddressBook *addressBook, int i, int count);

int *searchName(AddressBook *addressBook);
int searchPhone(AddressBook *addressBook);
int searchEmail(AddressBook *addressBook);
int *searchAddress(AddressBook *addressBook);

#endif
