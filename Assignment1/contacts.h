#pragma once
/*------------------------------------------------
name: Dumitru Mindrigan
id: 140920174
subject: IPC 144SFF
---------------------------------------------------
--------------------------------------------
Assignment: 1
Milestone : 3
-------------------------------------------- */




// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};


// Structure type Address declaration
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};


// Structure type Contact declaration

struct Contacts {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};


// ====== Milestone 4 =======
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------


// Get and store from standard input the values for Name
void getName(struct Name *);

// Get and store from standard input the values for Address
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers *);