/* -------------------------------------------
Name: Dumitru Mindrigan
Student number: 140920174
Email: dmindrigan@myseneca.ca
Section: SFF
Date: 30/07/2019
----------------------------------------------
Assignment: 2
Milestone:  4
-------------------------------------------------------------------------
Description: This header file modularizes general helper functions
			 to help reduce redundant coding for common repetitive tasks.
------------------------------------------------------------------------- */

// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include"contacts.h"

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes below...             |
// +-------------------------------------------------+

// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);


// getIntInRange:
int getIntInRange(int, int);


// yes:
int yes(void);


// menu:
int menu(void);


// contactManagerSystem:
void ContactManagerSystem(void);


// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader function prototype:
void displayContactHeader(void);

// displayContactFooter function prototype:
void displayContactFooter(int count);

// displayContact function prototype:
void displayContact(const struct Contact* contact);

// displayContacts function prototype:
void displayContacts(const struct Contact contacts[], int size);



// searchContacts function prototype: 
void searchContacts(const struct Contact contacts[], int size);


// addContact function prototype:
void addContact(struct Contact contacts[], int size);

// updateContact function prototype: 
void updateContact(struct Contact contacts[], int size);

// deleteContact function prototype:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
void sortContacts(struct Contact contacts[], int size);

//function prototype here:#pragma once
