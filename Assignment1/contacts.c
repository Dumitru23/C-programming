/* -------------------------------------------
Name: Dumitru  Mindrigan
Student number: 140920174
Email: dmindrigan@myseneca.ca
Section:SFF
Date:03/7/2019
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

//-----------------------------------------------------------
// Get and store from standard input the values for Name
//-----------------------------------------------------------
void getName(struct Name *name)  //name from name structure
{
	char op;
	//printf("-------------------------\n");
	//Contact Name input
	printf("Please enter the first name: ");
	scanf("%30s", (*name).firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", op);
	if ((op == 'y') || (op == 'Y')) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", (*name).middleInitial);
	}
	else
		(*name).middleInitial = '\0'; 

	printf("Please enter the contact's last name: ");
	scanf("%35s", (*name).lastName);
}

//-----------------------------------------------------------
// Get and store from standard input the values for Address
//-----------------------------------------------------------
void getAddress(struct Address *address)
{
	char op[2] = ("n");

	printf("Please enter the contact's street number: ");
	scanf("%d", &(*address).streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40s", (*address).street); 

	printf("Do you want to enter an appartment number? (y or n): ");
	scanf("\n%c", op);

	if ((*op == 'y') || (*op == 'Y')) {
		printf("Please enter the contact's appartment number: ");
		scanf("%d", &(*address).apartmentNumber);
	}
	else {
		(*address).apartmentNumber = -1;  
	}

	printf("Please enter the contact's postal code: "); 
	scanf(" %7[^\n]", (*address).postalCode);  

	printf("Please enter the contact's city: ");
	scanf("%40s", (*address).city); 
}

//-----------------------------------------------------------
// Get and store from standard input the values for Numbers
//-----------------------------------------------------------

void getNumbers(struct Numbers * numbers) 
{

	char op[2] = ("n");

	//Cell Phone
	//-------------------------------------------------------------
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("\n%c", op);

	if ((*op == 'Y') || (*op == 'y')) {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", (*numbers).cell);
	
	}
	else {
		(*numbers).cell[0] = '\0';
	}

	//Home Phone
	//-------------------------------------------------------------
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("\n%c", op);

	if ((*op == 'y') || (*op == 'Y')) {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", (*numbers).home);
		
	}
	else {
		(*numbers).home[0] = '\0'; 
	}

	//Business Phone
	//--------------------------------------------------------------------
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("\n%c", op); 

	if ((*op == 'n') || (*op == 'N')) {
		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", (*numbers).business);
	}
	else {
		(*numbers).business[0] = '\0'; 
	}
	printf("\n");
}


