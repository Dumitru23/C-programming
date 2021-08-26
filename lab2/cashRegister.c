//----------------------------------------------
// Name:           Mindrigan Dumitru
// Student Number: 140920174
// Email:          dmindrigan@seneca.ca
// Section:        SFF
// Workshop:       2 (in-lab)
//----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>

int main(void)
{
	double amount = 0;
	double  rest1, rest2 ;
	int Loonies, Quarter;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	Loonies = (int)amount;			//8.68 ->8

	rest1 = amount - Loonies;				// 8.68- 8 =0.68

	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, rest1);
	rest2 = rest1 / 0.25;				//0.68 / 0,25 =2.72
	Quarter =(int) rest2;			//8.68 /0,25 = 2.72  =2



	rest2 = rest1 - Quarter * 0.25; // 0.68-2*0.25 = 0.18

	printf("Quarters required: %d, balance owing $%.2lf\n", Quarter, rest2);




	return 0;


}
