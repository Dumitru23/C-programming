//----------------------------------------------

// Name:           Mindrigan Dumitru 

// Student Number: 140920174

// Email:          dmindrigan@myseneca.ca

// Section:        SFF

// Workshop:       2 (at_home)
//----------------------------------------------



#define _CRT_SECURE_NO_WARNINGS 

// Start your code below:

#include<stdio.h>

int main()
{
const double GST = 0.13;
int loonies, quarters, dimes, nickles, pennies;
double amount, GST_new, balance_owing, rest_ln;
int rest_qt, rest_dm, rest_nk, rest_pn, changes;
	
	printf("Please enter the amount to be paid:");
	scanf("%lf", &amount);

	GST_new = amount * GST + 0.005; //1.13
	printf("GST: %.2lf", GST_new);

	balance_owing = GST_new + amount; //9.81
	printf("\nBalance owing: $%.2lf", balance_owing);

	loonies = (int)balance_owing; //casting 9.81 = 9  
	rest_ln = balance_owing - loonies;//9.81-9 =0.81
	printf("\nLoonies required: %d, balance owing $%.2lf", loonies, rest_ln);

	rest_ln = rest_ln * 100; //0.81*100=81.00
	changes = (int)rest_ln; //81.00 -> 81

	
	quarters = changes / 25;// casting  81 /25 =3.24 = 3 
	rest_qt = changes % 25; // casting  81 % 3 = 25 rest +6
	
	printf("\nQuarters required: %d, balance owing $%.2f", quarters, (float)rest_qt/100 );

	 
	dimes= (int)rest_qt / 10;   // 6/10 =0.6  =0 
	rest_dm = rest_qt % 10; // 6/10 =0.6  = rest +6 
	
	printf("\nDimes required: %d, balance owing $%.2f", dimes, (float)rest_dm / 100);

	nickles = rest_dm / 5;   // 6/5 =1.2  = 1 
	rest_nk = rest_dm % 5; // 6%5 = 1.2  = rest +1
	   
	
	printf("\nNickles required: %d, balance owing $%.2f", nickles, (float)rest_nk / 100);

	
	pennies = rest_nk / 1;   // 1/1 = 1.0  = 1 
	rest_pn = rest_nk % 1; // 1%1 = 1.0  = rest +0;

	printf("\nPennies required: %d, balance owing $%.2f", pennies, (float)rest_pn / 100);

	

	return 0;
}