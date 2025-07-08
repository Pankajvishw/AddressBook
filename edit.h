/***********************************************************************
 *  File Name   : edit.h
 *  Description : Header file for editing contact information in the 
 *                Contact Management System. Declares functions for 
 *                modifying specific fields of a contact, such as 
 *                name, phone number, email, and address.
 *
 *                Functions:
 *                - editName()
 *                - editPhone()
 *                - editEmail()
 *                - editAddress()
 *                - editByName()
 *                - editByPhone()
 *                - editByEmail()
 *                - editByAddress()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 02-Jul-2025
 ***********************************************************************/

#ifndef EDIT_H
#define EDIT_H

#include "contact.h"

void editName(AddressBook *addressBook, int index);
void editPhone(AddressBook *addressBook, int index);
void editEmail(AddressBook *addressBook, int index);
void editAddress(AddressBook *addressBook, int index);

void editByName(AddressBook *addressBook);
void editByPhone(AddressBook *addressBook);
void editByEmail(AddressBook *addressBook);
void editByAddress(AddressBook *addressBook);

#endif
