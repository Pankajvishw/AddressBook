/***********************************************************************
 *  File Name   : search.c
 *  Description : This file implements search-related functionality for 
 *                the Contact Management System. It provides utilities 
 *                to search contacts by name, phone number, email ID, 
 *                or address, and displays the matched results in a 
 *                formatted table.
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

// Global array used to return matched indices
int arr[MAX_CONTACTS + 1];

// Utility: prints a separator line
void line()
{
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Utility: prints the header for contact listing
void print_head()
{
    printf("\n%90s\n\n", "📒 **********Contact Detail**********");
    line();
    printf("📄%-8s%-40s%-15s%40s%40s\n", "S.No", "Name", "Phone Number", "Email ID", "Address");
    line();
}

// Utility: prints a single contact's data
void print_data(AddressBook *addressBook, int i, int count)
{
    printf("%-10d%-40s%-15s%40s%40s\n", count + 1,
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email,
           addressBook->contacts[i].address);
}

// 🔍 Search contacts by name (returns pointer to array of matching indices)
int *searchName(AddressBook *addressBook)
{
    int count = 0;
    char name[50];
    int arr_index = 1;

    printf("\n(🔍 Type '0' to go Back) Enter the Name: ");
    do
    {
        scanf(" %[^\n]", name);
        if (!strcmp(name, "0"))
        {
            printf("\n👋 Going Back to Search Menu...\n");
            break;
        }

        if (duplicate_name(addressBook, name))
        {
            print_head();
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, name) == 0)
                {
                    print_data(addressBook, i, count);
                    arr[arr_index++] = i;  // Store index
                    count++;
                }
            }
            line();
        }
        else
        {
            printf("\n❌ Sorry! No Data Found... \nEnter Again: ");
        }
    } while (count == 0);

    arr[0] = arr_index;  // Store total matched indices
    return arr;
}

// 🔍 Search contact by phone (returns index or -1 if cancelled)
int searchPhone(AddressBook *addressBook)
{
    int count = 0, i;
    char phone[20];
    printf("\n(🔍 Type '0' to go Back) Enter the Phone Number: ");

    do
    {
        scanf(" %[^\n]", phone);

        if (!strcmp(phone, "0"))
        {
            printf("\n👋 Going Back to Previous Menu...\n");
            return -1;
        }

        if (valid_phone(addressBook, phone))
        {
            if (!duplicate_phone(addressBook, phone))
            {
                printf("\n❌ Sorry! No Data Found... \nEnter Again: ");
            }
            else
            {
                print_head();
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    if (!strcmp(addressBook->contacts[i].phone, phone))
                    {
                        print_data(addressBook, i, count);
                        count++;
                        break; // only one phone match allowed
                    }
                }
                line();
            }
        }
    } while (!count);

    return i; // returns index of matched contact
}

// 🔍 Search contact by email (returns index or -1 if cancelled)
int searchEmail(AddressBook *addressBook)
{
    int count = 0, i;
    char email[50];
    printf("\n(🔍 Type '0' to go Back) Enter the Email ID: ");

    do
    {
        scanf(" %[^\n]", email);

        if (!strcmp(email, "0"))
        {
            printf("\n👋 Going Back to Previous Menu...\n");
            return -1;
        }

        if (valid_email(addressBook, email))
        {
            if (!duplicate_email(addressBook, email))
            {
                printf("\n❌ Sorry! No Data Found... \nEnter Again: ");
            }
            else
            {
                print_head();
                for (i = 0; i < addressBook->contactCount; i++)
                {
                    if (!strcmp(addressBook->contacts[i].email, email))
                    {
                        print_data(addressBook, i, count);
                        count++;
                        break; // only one email match allowed
                    }
                }
                line();
            }
        }
    } while (!count);

    return i; // returns index of matched contact
}

int *searchAddress(AddressBook *addressBook)
{
    int count = 0;
    char address[50];
    int arr_index = 1;

    printf("\n(🔍 Type '0' to go Back) Enter the Address: ");
    do
    {
        scanf(" %[^\n]", address);
        if (!strcmp(address, "0"))
        {
            printf("\n👋 Going Back to Search Menu...\n");
            break;
        }

        if (duplicate_address(addressBook, address))
        {
            print_head();
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].address, address) == 0)
                {
                    print_data(addressBook, i, count);
                    arr[arr_index++] = i;  // Store index
                    count++;
                }
            }
            line();
        }
        else
        {
            printf("\n❌ Sorry! No Data Found... \nEnter Again: ");
        }
    } while (count == 0);

    arr[0] = arr_index;  // Store total matched indices
    return arr;
}
