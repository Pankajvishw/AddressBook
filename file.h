/***********************************************************************
 *  File Name   : file.h
 *  Description : Header file for file operations in the Contact 
 *                Management System. It declares functions for saving
 *                and loading contact data to/from a CSV file.
 *
 *                - saveContactsToFile()
 *                - loadContactsFromFile()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 02-Jul-2025
 *
 ***********************************************************************/

#ifndef FILE_H
#define FILE_H

#include "contact.h"

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
