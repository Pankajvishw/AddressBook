/***********************************************************************
 *  File Name   : delete.h
 *  Description : Header file for delete operations in the 
 *                Contact Management System. Declares functions used
 *                to delete contacts based on different criteria:
 *                name, phone, email, and address.
 *
 *                Functions:
 *                - delete_data()
 *                - deleteByName()
 *                - deleteByPhone()
 *                - deleteByEmail()
 *                - deleteByAddress()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 02-Jul-2025
 ***********************************************************************/

#ifndef DELETE_H
#define DELETE_H

#include "contact.h"

void delete_data(AddressBook *addressBook, int index);

void deleteByName(AddressBook *addressBook);

void deleteByPhone(AddressBook *addressBook);

void deleteByEmail(AddressBook *addressBook);

void deleteByAddress(AddressBook *addressBook);

#endif
