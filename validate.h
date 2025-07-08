/***********************************************************************
 *  File Name   : validate.h
 *  Description : Header file for validation and duplication checks in the 
 *                Contact Management System. Contains functions to validate 
 *                phone numbers and emails, and check for duplicate entries 
 *                in the address book.
 *
 *                Functions:
 *                - valid_mail_char()
 *                - valid_phone()
 *                - valid_email()
 *                - duplicate_phone()
 *                - duplicate_email()
 *                - duplicate_name()
 *                - duplicate_address()
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 02-Jul-2025
 ***********************************************************************/

#ifndef VALIDATE_H
#define VALIDATE_H

#include "contact.h"

int valid_mail_char(char ch);
int duplicate_phone(AddressBook *addressBook, char* phone);
int duplicate_email(AddressBook *addressBook, char* email);
int duplicate_name(AddressBook *addressBook, char* name);
int duplicate_address(AddressBook *addressBook, char* address);
int valid_phone(AddressBook *addressBook, char *phone);
int valid_email(AddressBook *addressBook, char *email);

#endif
