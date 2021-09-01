/*----------------------------------
Name: Dumitru Mindrigan
Student number : 140920174
Email : dmindrigan@myseneca.ca 
Section : SFF
Date : 30 / 07 / 2019
----------------------------------------------
Assignment : 2
Milestone : 4
----------------------------------*/

#include<string.h>
#include<stdio.h>
#include"contactHelpers.h" 
#define MAXCONTACTS 5  // SIZE OF CONTACTS ARRAY 
#define _CRT_SECURE_NO_WARNINGS

//------------------------------------------


// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n')   ; // empty execution code block
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
int val;
	char next_line = 'x';
	while (next_line != '\n'){
		scanf("%d%c",&val, &next_line);
		if(next_line!='\n'){
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &val, &next_line);
		}
	}
	//printf("Integer entered: %d", value);
	return val;
}


// getIntInRange:
int getIntInRange(int low, int high){
	int r_val; //range value
	int r_check=0; // range check
	
	while(r_check == 0){
		r_val=getInt();
		if(r_val>high || r_val <low){
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low, high);
		}
		else {
			 r_check=1;
			}
	}
	return r_val;
}

// yes:------------------------- start Yes()-----------------------------------
int yes(void){
{
	char new_l ='x'; //newline
	char conf= 'x'; //confirmation
	int yes; // yes or no 



	while (new_l !='\n'){
		scanf("%c%c", &conf,&new_l); 
		if(new_l !='\n'){
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (conf == 'y' || conf == 'Y') {
			yes = 1;
		}
		else if (conf == 'n'|| conf == 'N') {
			yes = 0;
		}
		else{
			new_l='x';
		}
	}
	return yes;
}
//---------------------------------------end of Yes()------------------------------------------------------

// menu:--------------------------------Start menu()---------------------------------------------------
int menu(void){
int ch = 0; //choise
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	printf("\n");
return ch;
}
//-----------------------------------end of Menu()-----------------------------------------------------

// ------------------------------------Start ContactStartManagerSystem()-------------------------------------

void ContactManagerSystem(void){

struct Contact contact[MAXCONTACTS] = {
{	{	{ "Rick", {'\0'}, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" } },
	{
		{"Sasha", {'\0'}, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" } },
};

	int res = 0, opt;

	while (res == 0) {

		opt = menu();
		
	switch (opt) {

		case 1:
			displayContacts(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 2:
			addContact(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 3:
			updateContact(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 4: 
			deleteContact(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 5:
			searchContacts(contact, MAXCONTACTS);
			pause();
			break;
			printf("\n");

		case 6:
			sortContacts(contact, MAXCONTACTS)
			pause();
			break;
			printf("\n"); 

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			res  = yes();
			printf("\n");
			break;

		default:
			break;
		}
	}
	printf("Contact Management System: terminated\n");
}

// -------------------------------END----ContactStartManagerSystem()-------------------------------------


//----------------------------------Start getTenDigitPhone()----------------------------------------

void getTenDigitPhone(char telNum[])
{
  char telNum[11];
   int Input = 1,ch_length=0, ch_digit=0,l=0,i,flag=0;

  printf("string: ");

	while (Input == 1) {
	  scanf("%s", telNum);
	 
	l=strlen(telNum);
	//printf("\n l=%d", l);
	if (l<10 || l>10)
	  printf("\n you did't eneter 10 char ");
	else
	  ch_length=1;

   for(i = 0 ; telNum[i] !='\0' && flag==0; i++)
		if(isdigit(telNum[i])){
		  ch_digit=1;
		}
		else{
		  ch_digit=0;
		  //printf("\n there is characters in string: ");
		  //printf("\n i=%d chararter=%c",i, telNum[i] );
		  flag=1;
		}

//printf("\n ch_length=%d ch_digit=%d", ch_length , ch_digit);

	if(ch_length ==1 && ch_digit ==1)
		Input = 0;
	else {
	  ch_length=0; ch_digit=0; flag=0;   //restart all nessesary var-s
	  printf("\n Enter a 10-digit phone number: ");
	}

  }
return 0; 
}

//----------------------------------END getTenDigitPhone()----------------------------------------

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
	int j;
	int i = 0;
	int index = -1;
	do {
		j = strcmp(contacts[i].numbers.cell, cellNum); //compare alphabeticaly 2 phones number 
		if (j == 0) {
			index = i;
		}
		i++;
	} while (i < size);

	return index;

}


// -------------------- Start ---------displayContactHeader-------------------------------------------------

void displayContactHeader(void){
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}
// ---------------------------------------END ---------displayContactHeader------------------------------------------------


// ------------------------Start-----displayContactFooter()------------------------------------------------------------ 

void displayContactFooter(int count){
printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}

//-----------------------------End-----displayContactFooter()------------------------------------------------------------



//---------------------------------------START  void displayContact()----------------------------------------------
void displayContact(const struct Contact* contact){
	if (strcmp((*contact).name.middleInitial, "") == 0)
		printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
	else
		printf(" %s %s %s\n", (*contact).name.firstName, (*contact).name.middleInitial, (*contact).name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business);

	if ((*contact).address.apartmentNumber > 0)
		printf("       %d %s, Apt# %d, %s, %s\n", (*contact).address.streetNumber, (*contact).address.street, (*contact).address.apartmentNumber, (*contact).address.city, (*contact).address.postalCode);
	else
		printf("       %d %s, %s, %s\n", (*contact).address.streetNumber, (*contact).address.street, (*contact).address.city, (*contact).address.postalCode);
}

//---------------------------------------END  void displayContact()-------------------------------------------



//--------------------------------START---displayContacts()-----------------------------------------------------------
void displayContacts(const struct Contact contacts[], int size){
	int i = 0, j = 0;
	int lenght;
	displayContactHeader();

	for (i = 0; i < size; i++) {
		lenght = strlen(contact[i].numbers.cell);
		if (lenght > 0) {
			displayContact(&(contact[i]));
			j++;
		}
	}displayContactFooter(j);
}
//--------------------------------END displayContacts()-----------------------------------------------------------


//---------------------------------Start- searchContacts ()-------------------------------------
void searchContacts(const struct Contact contacts[], int size){
int i;
	char cellNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	printf("\n");
	i = findContactIndex(contact, size, cellNum);

	if (i >= 0 && i < size) {
		displayContact(&(contact[i]));
	}
	else printf("*** Contact NOT FOUND ***");
	printf("\n");

}
//---------------------------------END- searchContacts ()---------------------------------------------------


//----------------------------------------Start----void addContact(,)-------------------------------------------
void addContact(struct Contact contacts[], int size){
	int i, available = -1;

	for (i = 0; i<size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			available = i;
			break;
		}
	}
	if (available > -1)
	{
		getContact(&contacts[available]); 
		printf("--- New contact added! ---\n");
	}
	else
	{
		printf("*** ERROR: The contact list is full! ***");
		printf("\n");
	}
}
//----------------------------END----void addContact()-------------------------------------------------------



// ----------------------------------Start----void updateContact()---------------------------------------------------

void updateContact(struct Contact contacts[], int size){
	int myIndex;
	char cellNum[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	myIndex = findContactIndex(contact, size, cellNum);
	if (myIndex == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&(contact[myIndex]));
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) {
			getName(&(contact[myIndex].name));
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			getAddress(&(contact[myIndex].address));
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getNumbers(&(contact[myIndex].numbers));
		}
		printf("--- Contact Updated! ---\n");
	}
}
// ---------------------------------End-----void updateContact()-----------------------------------------


//--------------------------------------START--- deleteContact()------------------------------------------

void deleteContact(struct Contact contacts[], int size)
{
	int myIndex;
	char cellNum[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	//searchContacts(contact, size, cellNum);
	myIndex = findContactIndex(contact, size, cellNum);

	if (myIndex == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else printf("\nContact found:\n");
	displayContact(&(contact[myIndex]));
	printf("\n");
	printf("CONFIRM: Delete this contact? (y or n): ");
	if (yes() == 1) {
		strcpy(contact[myIndex].numbers.cell, "\0");
		printf("--- Contact deleted! ---\n");
	}
}
//---------------------------------------END--------deleteContact()-----------------------------------


//---------------------------------Start --sortContacts:---------------------------------------------------
void sortContacts(struct Contact contacts[], int size){

   int i,j;
   char *temp;
 
   for(i=0;i<size-1;i++)
	  for(j=i+1;j<size;j++){
		 if(strcmp(contact[i].numbers.cell, contact[j].numbers.cell)>0) {  
			strcpy(temp,contact[i]);
			strcpy(contact[i],contact[j]);
			strcpy(contact[j],temp);
		 }
	  }
   printf("--- Contacts sortded ---\n");
  
return 0;
}

}
//---------------------------------END --sortContacts:---------------------------------------------------