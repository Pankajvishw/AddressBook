/***********************************************************************
 *  File Name   : edit.c
 *  Description : This file contains all the editing functionalities
 *                for the Contact Management System. It allows the user 
 *                to update contact details such as name, phone number, 
 *                email, and address, either by searching with specific fields
 *                or choosing from multiple matches.
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

// Edit the name of a contact at the given index
void editName(AddressBook *addressBook, int index)
{
	char name[50];
    printf("\n✏️ (Type '0' to go Back) Enter the new Name: ");
	scanf(" %[^\n]", name);
	if (!strcmp(name, "0"))
	{
		printf("\n👋 Going Back to Previous Menu...\n");
		return ;
	}
	strcpy(addressBook->contacts[index].name, name);
    printf("\n✅ Name updated successfully!\n");
    print_head();
    print_data(addressBook, index, 0);
    line();
}

// Edit the phone number of a contact at the given index
void editPhone(AddressBook *addressBook, int index)
{
    int invalid = 0;
    char phone[20];
    printf("\n📱 (Type '0' to go Back) Enter the Phone Number: ");
    do
    {
        scanf(" %[^\n]", phone);
		if (!strcmp(phone, "0"))
        {
            printf("\n👋 Going Back to Previous Menu...\n");
            return ;
        }
        invalid = (!valid_phone(addressBook, phone));
        if (duplicate_phone(addressBook, phone))
        {
            printf("\n❌ ERROR! Number already exists.\nPlease enter a unique number: ");
            invalid = 1;
        }
    } while (invalid);

    strcpy(addressBook->contacts[index].phone, phone);
    printf("\n✅ Phone number updated successfully!\n");
    print_head();
    print_data(addressBook, index, 0);
    line();
}

// Edit the email of a contact at the given index
void editEmail(AddressBook *addressBook, int index)
{
    int invalid = 0;
    char email[50];
    printf("\n📧 (Type '0' to go Back) Enter the Email ID: ");
    do
    {
        scanf(" %[^\n]", email);
		if (!strcmp(email, "0"))
        {
            printf("\n👋 Going Back to Previous Menu...\n");
            return ;
        }
        invalid = (!valid_email(addressBook, email));
        if (duplicate_email(addressBook, email))
        {
            printf("\n❌ ERROR! Email already exists.\nPlease enter a unique Email ID: ");
            invalid = 1;
        }
    } while (invalid);

    strcpy(addressBook->contacts[index].email, email);
    printf("\n✅ Email updated successfully!\n");
    print_head();
    print_data(addressBook, index, 0);
    line();
}

void editAddress(AddressBook *addressBook, int index)
{
	char address[50];
    printf("\n✏️ (Type '0' to go Back) Enter the new Address: ");
	scanf(" %[^\n]", address);
	if (!strcmp(address, "0"))
	{
		printf("\n👋 Going Back to Previous Menu...\n");
		return ;
	}
	strcpy(addressBook->contacts[index].address, address);
    printf("\n✅ Name updated successfully!\n");
    print_head();
    print_data(addressBook, index, 0);
    line();
}

// Edit a contact found by name (handles duplicates too)
void editByName(AddressBook *addressBook)
{
    int index, count;
    int *arr = searchName(addressBook); // Returns index list of matching contacts
    index = arr[0];

    // If multiple contacts match, ask user to choose
    if (index - 1 > 1)
    {
        printf("Enter the Serial No. to Edit: ");
        int flag = 0;
        do
        {
            scanf(" %d", &index);
            if (index < 1 || index > arr[0])
            {
                printf("Invalid Serial No. Please enter again: ");
                flag = 1;
            }
            else
                flag = 0;
        } while (flag);
    }

    char choice;
    do
    {
        printf("\n🛠️ What would you like to edit?\n");
        printf("1. ✏️ Edit Name\n");
        printf("2. 📱 Edit Phone\n");
        printf("3. 📧 Edit Email\n");
        printf("4. 🏠 Edit Address\n");
        printf("5. 🔙 Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1': editName(addressBook, arr[index]); break;
            case '2': editPhone(addressBook, arr[index]); break;
            case '3': editEmail(addressBook, arr[index]); break;
            case '4': editAddress(addressBook, arr[index]); break;
            case '5': printf("🔙 Going back to Edit Menu...\n"); break;
            default:
                printf("❗ Invalid choice. Please try again.\n");
        }
    } while (choice != '4');
}

// Edit a contact by searching with phone number
void editByPhone(AddressBook *addressBook)
{
    int index;
    char choice;
    index = searchPhone(addressBook); // Returns exact index
    do
    {
        printf("\n🛠️ What would you like to edit?\n");
        printf("1. ✏️ Edit Name\n");
        printf("2. 📱 Edit Phone\n");
        printf("3. 📧 Edit Email\n");
        printf("4. 🏠 Edit Address\n");
        printf("4. 🔙 Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1': editName(addressBook, index); break;
            case '2': editPhone(addressBook, index); break;
            case '3': editEmail(addressBook, index); break;
            case '4': editAddress(addressBook, index); break;
            case '5': printf("🔙 Going back to Edit Menu...\n"); break;
            default: printf("❗ Invalid choice. Please try again.\n");
        }
    } while (choice != '5');
}

// Edit a contact by searching with email address
void editByEmail(AddressBook *addressBook)
{
    int index;
    char choice;
    index = searchEmail(addressBook); // Returns exact index
    do
    {
        printf("\n🛠️ What would you like to edit?\n");
        printf("1. ✏️ Edit Name\n");
        printf("2. 📱 Edit Phone\n");
        printf("3. 📧 Edit Email\n");
        printf("4. 🏠 Edit Address\n");
        printf("5. 🔙 Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1': editName(addressBook, index); break;
            case '2': editPhone(addressBook, index); break;
            case '3': editEmail(addressBook, index); break;
            case '4': editAddress(addressBook, index); break;
            case '5': printf("🔙 Going back to Edit Menu...\n"); break;
            default: printf("❗ Invalid choice. Please try again.\n");
        }
    } while (choice != '5');
}

void editByAddress(AddressBook *addressBook)
{
    int index, count;
    int *arr = searchAddress(addressBook); // Returns index list of matching contacts
    index = arr[0];

    // If multiple contacts match, ask user to choose
    if (index - 1 > 1)
    {
        printf("Enter the Serial No. to Edit: ");
        int flag = 0;
        do
        {
            scanf(" %d", &index);
            if (index < 1 || index > arr[0])
            {
                printf("Invalid Serial No. Please enter again: ");
                flag = 1;
            }
            else
                flag = 0;
        } while (flag);
    }

    char choice;
    do
    {
        printf("\n🛠️ What would you like to edit?\n");
        printf("1. ✏️ Edit Name\n");
        printf("2. 📱 Edit Phone\n");
        printf("3. 📧 Edit Email\n");
        printf("4. 🏠 Edit Address\n");
        printf("5. 🔙 Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1': editName(addressBook, arr[index]); break;
            case '2': editPhone(addressBook, arr[index]); break;
            case '3': editEmail(addressBook, arr[index]); break;
            case '4': editAddress(addressBook, arr[index]); break;
            case '5': printf("🔙 Going back to Edit Menu...\n"); break;
            default:
                printf("❗ Invalid choice. Please try again.\n");
        }
    } while (choice != '5');
}