

//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	int streetNumber;
	int apartmentNumber;
	char street[41];
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here...
// NOTE: Modify the C String arrays sizes according to the
//       Assignment-2 Milestone-1 specifications
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
// Place your code here...

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// Get and store from standard input the values for a Contact 

void getContact(struct Contact *);

// Get and store from standard input the values for Name

void getName(struct Name *);

// Get and store from standard input the values for Address

void getAddress(struct Address *);

// Get and store from standard input the values for Numbers

void getNumbers(struct Numbers *);