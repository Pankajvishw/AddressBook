/***********************************************************************
 *  File Name   : delete.c
 *  Description : This file contains functions to delete contacts from
 *                the address book based on name, phone number, email ID, 
 *                or address. It supports handling multiple matching entries
 *                and updates the contact list accordingly.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
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

// Deletes a contact by shifting all elements after the index one step left
void delete_data(AddressBook *addressBook, int index)
{
    int i;
    for (i = index + 1; i < addressBook->contactCount; i++)
    {
        addressBook->contacts[i - 1] = addressBook->contacts[i];
    }
    addressBook->contactCount--;  // Decrease the contact count
    printf("\n🗑️ Contact Deleted Successfully...\n");
}

// Delete a contact by searching with the Name
void deleteByName(AddressBook *addressBook)
{
    int index;
    int *arr = searchName(addressBook);  // Returns list of matched indices
    index = arr[0];                      // Total matches stored at arr[0]

    // If multiple contacts with the same name exist, prompt for serial number
    if (index - 1 > 1)
    {
        printf("🗂️ Multiple entries found.\n");
        printf("🔢 Enter the Serial No. to Delete: ");
        int flag = 0;
        do
        {
            scanf(" %d", &index);
            if (index < 1 || index > arr[0])
            {
                printf("❗ Invalid serial number. Enter again: \n");
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        } while (flag);
    }

    // Delete the selected contact using its actual index
    delete_data(addressBook, arr[index]);
}

// Delete a contact by searching with the Phone number
void deleteByPhone(AddressBook *addressBook)
{
    int index;
    index = searchPhone(addressBook);  // Gets the exact index of the contact
    if(index != -1)
        delete_data(addressBook, index);   // Deletes that contact
}

// Delete a contact by searching with the Email ID
void deleteByEmail(AddressBook *addressBook)
{
    int index;
    index = searchEmail(addressBook);  // Gets the exact index
    if(index != -1)
        delete_data(addressBook, index);   // Deletes the contact
}

void deleteByAddress(AddressBook *addressBook)
{
    int index;
    int *arr = searchAddress(addressBook);  // Returns list of matched indices
    index = arr[0];                      // Total matches stored at arr[0]

    // If multiple contacts with the same name exist, prompt for serial number
    if (index - 1 > 1)
    {
        printf("🗂️ Multiple entries found.\n");
        printf("🔢 Enter the Serial No. to Delete: ");
        int flag = 0;
        do
        {
            scanf(" %d", &index);
            if (index < 1 || index > arr[0])
            {
                printf("❗ Invalid serial number. Enter again: \n");
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        } while (flag);
    }

    // Delete the selected contact using its actual index
    delete_data(addressBook, arr[index]);
}
