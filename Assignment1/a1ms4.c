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


int main(void)
{
	// Declare variables here:

	// Create a variable of type Contact and call it something self-describing like "contact"
	// - HINT: Be sure to initialize the values to 0 and empty C strings
	struct Contacts mycontact = { {"","",""},{0,"",0,"",""},{"","",""} };


	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n"); 

	// Call the Contact function getName to store the values for the Name member
	getName(&mycontact.name); 

	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&mycontact.address);
	
	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&mycontact.numbers);     

		// Display Contact summary details
		printf("\nContact Details");
		printf("\n---------------");

		printf("\nFirst name: %s", mycontact.name.firstName);
		printf("\nMiddle initial(s): %s", mycontact.name.middleInitial);
		printf("\nLast name: %s\n", mycontact.name.lastName); 
		printf("\n");

		printf("Address Details");
		printf("\nStreet number: %d", mycontact.address.streetNumber); 
		printf("\nStreet name: %s", mycontact.address.street);
		printf("\nAppartment: %d", mycontact.address.apartmentNumber); 
		printf("\nPostal code: %s", mycontact.address.postalCode);
		printf("\nCity: %s", mycontact.address.city);    

		printf("\n\nPhone numbers:"); 
		printf("\nCell phone number: %s", mycontact.numbers.cell);
		printf("\nHome phone number: %s", mycontact.numbers.home);
		printf("\nBusiness phone number: %s", mycontact.numbers.business);
		printf("\n"); 

		// Display Completion Message
		printf("Structure test for Contact using functions done!\n");
	return 0; 
}

/*  SAMPLE OUTPUT:
Contact Management System
-------------------------
Please enter the contact's first name: Wilma
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Dino
Please enter the contact's last name: Flintstone
Please enter the contact's street number: 100
Please enter the contact's street name: Bedrock
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 14
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: Markham
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 647-505-5555
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 905-222-3333
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-491-5050
Contact Details
---------------
Name Details
First name: Wilma
Middle initial(s): Dino
Last name: Flintstone
Address Details
Street number: 100
Street name: Bedrock
Apartment: 14
Postal code: Z8Z 7R7
City: Markham
Phone Numbers:
Cell phone number: 647-505-5555
Home phone number: 905-222-3333
Business phone number: 416-491-5050
Structure test for Contact using functions done!
*/