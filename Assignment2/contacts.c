/* -------------------------------------------
Name: Dumitru Mindrigan
Student number: 140920174
Email: dmindrigan@myseneca.ca
Section: SFF
Date: 30/07/2019
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contactHelpers.h"
#include"contacts.h"


// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName: ---------------------------------------------------------------
void getName(struct Name *name) {

	int option = 0; 

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]%*c", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	option = yes();


	if (option == 1) {

		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]%*c", name->middleInitial); 
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]%*c", name->lastName);

}
// getAddress:
void getAddress(struct  Address * address) {

	int option;

	printf("Please enter the contact's street number: ");
	option = getInt();
	address->streetNumber = option; 


	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]%*c", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's apartment number: ");
		option = getInt();
		address->apartmentNumber = option; 
	}
	else
		address->apartmentNumber = 0;
	 

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]%*c", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]%*c", address->city); 
} 
// getNumbers:

void getNumbers(struct Numbers* numbers) {

	int option;

	// Contact Numbers Input:

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();

	if (option == 1) {

		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
		strcpy(numbers->home, "\0");

	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();

	if (option == 1) {

		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
		strcpy(numbers->business, "\0"); 

}
// getContact:

void getContact(struct Contact* contact) {

	getName(&(*contact).name);
	getAddress(&(*contact).address);
	getNumbers(&(*contact).numbers);

}
