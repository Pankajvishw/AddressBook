/***********************************************************************
 *  File Name   : file.c
 *  Description : This file handles file operations for the Contact 
 *                Management System. It contains functions to save 
 *                contacts to a file and load them from a file.
 *
 *                - Contacts are stored in "contact.csv" in CSV format.
 *                - The file starts with the contact count on the first line.
 *
 *  Author      : Pankaj Kumar
 *  Roll No     : 25008_018
 *  Date        : 02-Jul-2025
 *
 ***********************************************************************/

#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contact.csv", "w");
    if(fp == NULL)
    {
        perror("Error ");
        return ;
    }
    fprintf(fp, "#%d\n", addressBook->contactCount);
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s,%s\n",addressBook->contacts[i].name, 
                                    addressBook->contacts[i].phone, 
                                    addressBook->contacts[i].email, 
                                    addressBook->contacts[i].address);
    }
    addressBook->contactCount = 0;
    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contact.csv", "r");
    if(fp == NULL)
    {
        perror("Error ");
        return ;
    }
    fscanf(fp, "#%d\n", &addressBook->contactCount);
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name, 
                                                addressBook->contacts[i].phone, 
                                                addressBook->contacts[i].email, 
                                                addressBook->contacts[i].address);
    }
    fclose(fp);
}
