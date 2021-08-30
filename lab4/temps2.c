//----------------------------------------------
// Name:           Mindrigan Dumitru
// Student Number: 140920174
// Email:          dmindriganID@myseneca.ca
// Section:        SFF
// Workshop:       4 (at home)
//-----------------


#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define size 10

int main()
{
	int val, i, high[size], low[size];
	int max, min, d_min = 0, d_max = 0, nr;
	float aver, total;

	printf("---===IPC Temperature Calculator V2.0===---\n");
	printf("Please enter the number of day, between 3 and 10, inclusive: ");
	scanf_s("%d", &val); //11
	while (!(val >= 3 && val <= 10)) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");//5
		scanf_s("%d", &val); //5
	}
	printf("\n");
	for (i = 0; i < val; i++) {
		printf("Day %d - High: ", i + 1);
		scanf_s("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf_s("%d", &low[i]);
	}

	printf("\nDay  Hi  Low\n");
	for (i = 0; i < val; i++) {
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}

	max = high[0];//6
	min = low[0]; //-2
	for (i = 0; i < val; i++) {
		if (high[i] > max) {
			max = high[i];  //9
			d_max = i + 1;	//2
		}
		if (low[i] < min) {
			min = low[i];  //-9
			d_min = i + 1;     //4
		}
	}
	printf("The hiest temperature was %d, on day %d\n", max, d_max);
	printf("The lowest temperature was %d, on day %d\n", min, d_min);

	val = 1; // reset
	printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf_s("%d", &val);
	while (val >= 0) {
		while (!(val >= 1 && val <= 5)) {
			printf("Invalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf_s("%d", &val);
		}
		nr = 0; aver = 0; total = 0;
		for (i = 0; i < val; i++) {   //val=3 , i=3
			total += (high[i] + low[i]); // t=t +6+(-2); t= 4+9+(-1); t=12+7+(-3); t=16
			nr++;//
		}
		aver = total / (nr * 2);
		printf("The average temperature up to day %d is %.2f", val, aver);

		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf_s("%d", &val);
	}
	printf("Goodbye!");

	return 0;

}