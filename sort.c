/***********************************************************************
 *  File Name   : sort.c
 *  Description : This file contains the function to sort the contacts 
 *                alphabetically by name in the Contact Management System.
 *                A simple bubble sort algorithm is used for this purpose.
 *
 *  Author      : Pankaj Kumar
 *  GitHub      : github.com/Pankajvishw
 *  Date        : 02-Jul-2025
 *
 ***********************************************************************/

#include "contact.h"
#include "sort.h"

// Function to sort the contacts alphabetically by name using bubble sort logic
void sort_struct(AddressBook * addressBook)
{
    int i, j;
    for(i = 0; i < addressBook->contactCount - 1; i++)
    {
        for(j = i + 1; j < addressBook->contactCount; j++)
        {
            if(strcmp(addressBook->contacts[i].name, addressBook->contacts[j].name) > 0)
            {
                Contact temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }
}