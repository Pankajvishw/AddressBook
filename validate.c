/***********************************************************************
 *  File Name   : validate.c
 *  Description : This file contains validation and duplication check
 *                functions for the Contact Management System. It ensures
 *                correct formats for phone numbers and email addresses,
 *                and checks for uniqueness in name, phone, email, and
 *                address fields before inserting or editing contacts.
 *
 *  Author      : Pankaj Kumar
 *  Roll No     : 25008_018
 *  Date        : 02-Jul-2025
 *
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validate.h"
#include "search.h"
#include "delete.h"
#include "edit.h"

//  Utility function: checks if a character is valid for email
int valid_mail_char(char ch)
{
    return (isdigit(ch) || islower(ch) || ch == '_' || ch == '-' || ch == '.' || ch == '@');
}

//  Checks if phone number already exists in the address book
int duplicate_phone(AddressBook *addressBook, char* phone)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (!strcmp(phone, addressBook->contacts[i].phone))
        {
            return 1;  // Duplicate found
        }
    }
    return 0;  // Unique
}

//  Checks if email already exists in the address book
int duplicate_email(AddressBook *addressBook, char* email)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (!strcmp(email, addressBook->contacts[i].email))
        {
            return 1;
        }
    }
    return 0;
}

//  Checks if name already exists in the address book
int duplicate_name(AddressBook *addressBook, char* name)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (!strcmp(name, addressBook->contacts[i].name))
        {
            return 1;
        }
    }
    return 0;
}

//  Checks if address already exists in the address book
int duplicate_address(AddressBook *addressBook, char* address)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (!strcmp(address, addressBook->contacts[i].address))
        {
            return 1;
        }
    }
    return 0;
}

//  Validates phone number format (must be 10 digits)
int valid_phone(AddressBook *addressBook, char *phone)
{
    int i = 0;

    // Check length
    if (strlen(phone) != 10)
    {
        printf("\n📵 ERROR! Number should be 10 digits only.\nPlease Enter a Valid Number: ");
        return 0;
    }

    // Check all characters are digits
    while (phone[i])
    {
        if (!isdigit(phone[i]))
        {
            printf("\n📵 ERROR! Number should contain only digits.\nPlease Enter a Valid Number: ");
            return 0;
        }
        i++;
    }

    return 1;
}

//  Validates email format
int valid_email(AddressBook *addressBook, char *email)
{
    int i = 0, count = 0;
    char *dotcom = strstr(email, ".com");

    while (email[i])
    {
        if (email[i] == '@')
        {
            // Invalid if dot comes just before or after '@'
            if (email[i+1] != '\0' && (email[i-1] == '.' || email[i+1] == '.'))
            {
                printf("\n⚠️ ERROR! Dot (.) before or after '@' is not allowed.\nPlease Enter a Valid mail ID\n");
                return 0;
            }
            count++;
        }

        if (!valid_mail_char(email[i]))
        {
            printf("\n❌ ERROR! Invalid Character in email.\nPlease Enter a Valid mail ID : ");
            return 0;
        }
        i++;
    }

    // Email must end with ".com"
    if (!dotcom || strcmp(dotcom, ".com") != 0)
    {
        printf("\n❌ ERROR! Email must end with .com.\nPlease Enter a Valid mail ID : ");
        return 0;
    }

    // Email must contain exactly one '@'
    if (count != 1)
    {
        printf("\n🚫 ERROR! Email must contain one '@'.\nPlease Enter a Valid mail ID : ");
        return 0;
    }

    return 1;
}
