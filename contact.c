/***********************************************************************
 *  File Name   : contact.c
 *  Description : This file implements core functionality of a 
 *                Contact Management System including features like 
 *                adding, listing, editing, deleting, and searching contacts.
 *                It loads and saves data to a file and handles user interaction.
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
#include "sort.h"


void listContacts(AddressBook *addressBook) 
{
    /* Define the logic for print the contacts */ 
        printf("\n📇 Contact List:\n");
        // Check if contact list is empty
        if (addressBook->contactCount == 0) 
        {
                printf("📭 No contacts found! Add some to get started.\n");
                return;
        }

        print_head();
        for(int i = 0; i < addressBook->contactCount; i++)
        {
                print_data(addressBook, i, i);
        }
        line();    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
//     populateAddressBook(addressBook);

    // Welcome message
    printf("\n");
    printf("==================================================================\n");
    printf("📘  Welcome to the Contact Management System by Pankaj Kumar   📘\n");
    printf("==================================================================\n");
    printf("✨ Manage your contacts with ease: Add | Search | Edit | Delete ✨\n");
    printf("🔒 Your data is private and securely handled.\n");
    printf("------------------------------------------------------------------\n\n");
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
    sort_struct(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
        if(addressBook->contactCount == MAX_CONTACTS)
        {
                printf("❌ Sorry! Address Book is Full, Please Delete some contacts to add more.\n");
                return;
        }	

        // Read the name from user
        printf("📝 Enter the Name : ");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);

        char phone[20], email[50];
        int invalid = 0;

        // Read the Phone Number from the user and validate
        printf("📱 Enter the Phone Number : ");
        do
        {
        scanf(" %[^\n]", phone);
        invalid = (!valid_phone(addressBook, phone));
        if(duplicate_phone(addressBook, phone))
        {
                printf("\n❗ERROR! Number ALready exists.\nPlease Enter Unique Number : ");
                invalid = 1;
        }
        } while(invalid);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);

        // Read the mail id from user and validate
        printf("📧 Enter the Email ID : ");
        do
        {
        scanf(" %[^\n]", email);
        invalid = (!valid_email(addressBook, email));
        if(duplicate_email(addressBook, email))
        {
                printf("\n❗ERROR! Email ALready exists.\nPlease Enter Unique mail ID : ");
                invalid = 1;
        }
        } while(invalid);
        strcpy(addressBook->contacts[addressBook->contactCount].email, email);

        // Read the address from user
        printf("🏠 Enter the Address : ");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].address);


        // Increment count when saved Successfully
        addressBook->contactCount++;
        sort_struct(addressBook);
        printf("\n✅ Contact Saved Successfully !");
}

void searchContact(AddressBook *addressBook) 
{
	char choice;
	do
	{
		printf("\n🔍 Search Menu:\n");
		printf("1. By Name\n");
                printf("2. By Phone\n");
                printf("3. By Email\n");
                printf("4. By Address\n");
                printf("5. Exit\n");
                printf("📥 Enter your choice: ");
		scanf(" %[^\n]", &choice);

		switch(choice)
		{
			case '1': searchName(addressBook); break;
	    		case '2': searchPhone(addressBook); break;
			case '3': searchEmail(addressBook); break;
                        case '4': searchAddress(addressBook); break;
			case '5': printf("🔙 Going back to Address Menu...\n"); break;
	    		default: printf("❗Invalid choice. Please try again.\n");
		}
	}while( choice != '5');
}

void editContact(AddressBook *addressBook)
{
	char choice;
        do
        {
                printf("\n🛠️ Edit Menu:\n");
                printf("1. Edit by Name\n");
                printf("2. Edit by Phone\n");
                printf("3. Edit by Email\n");
                printf("4. Edit by Address\n");
                printf("5. Exit\n");
                printf("📥 Enter your choice: ");
                scanf(" %[^\n]", &choice);

                switch(choice)
                {
                        case '1': editByName(addressBook); break;
                        case '2': editByPhone(addressBook); break;
                        case '3': editByEmail(addressBook); break;
                        case '4': editByAddress(addressBook); break;
                        case '5': printf("🔙 Going back to Edit Menu...\n"); break;
                        default: printf("❗ Invalid choice. Please try again.\n");
                }
        }while( choice != '5');
}

void deleteContact(AddressBook *addressBook)
{
	char choice;
        do
        {
                printf("\n🗑️ Delete Menu:\n");
                printf("1. Delete by Name\n");
                printf("2. Delete by Phone\n");
                printf("3. Delete by Email\n");
                printf("4. Delete by Address\n");
                printf("5. Exit\n");
                printf("📥 Enter your choice: ");
                scanf(" %[^\n]", &choice);

                switch(choice)
                {
                        case '1': deleteByName(addressBook); break;
                        case '2': deleteByPhone(addressBook); break;
                        case '3': deleteByEmail(addressBook); break;
                        case '4': deleteByAddress(addressBook); break;
                        case '5': printf("🔙 Going back to Delete Menu...\n"); break;
                        default: printf("❗Invalid choice. Please try again.\n");
                }
        }while( choice != '5');
}