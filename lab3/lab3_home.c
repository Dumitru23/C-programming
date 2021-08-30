//----------------------------------------------

// Name:           Mindrigan Dumitru
// Student Number: 140920174
// Email:          dmindriganID@myseneca.ca

// Section:        SFF
// Workshop:       3 (at-home)

//----------------------------------------------


#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define NUMS 4
//---===IPC Temperature Analyzer

int main(void)
{
	int high = 0, low = 0, i, tempHst = -40, tempLow = 40, day_h = 0, day_l = 0, tot_Low = 0, tot_High = 0;
	float  averTotal = 0;
	printf("---===IPC Temperature Analyzer\n");
	for (i = 1; i <= NUMS; i++) {

		printf("Enter the high value for day %d:", i);
		scanf("%d", &high);
		printf("\nEnter the low value for day %d:", i);
		scanf("%d", &low);

		while (!(high > low && high<41 && low>-41)) {
			printf("\nIncorrect values, temperatures must be in range -40 to 40, high must be greater than \nlow.");
			printf("\n\nEnter the high value for day %d:", i);
			scanf("%d", &high);
			printf("\nEnter the low value for day %d:", i);
			scanf("%d", &low);
		}
		tot_Low += low; tot_High += high; //total of high and low
		if (high > tempHst) //8 >-40 T, 9>8 T;  11>9 T, 10>11 F 
		{
			tempHst = high; day_h = i; // 8, 9, 11,  
		}
		if (low < tempLow) // -2<40 T, -4<-2 T, 5<-4 F, 3<-4 F 
		{
			tempLow = low; day_l = i;  //-2, -4,  
		}

		printf("\n");
	}
	averTotal = tot_Low + tot_High; //2+ 38 =40 
	printf("\nThe average (mean) LOW temperature was: %1.2f:", (float)tot_Low / NUMS);
	printf("\nThe average (mean) LOW temperature was %1.2f:", (float)tot_High / NUMS);
	printf("\nThe average (mean) temperature was %1.2f:", averTotal / (NUMS + NUMS));
	printf("\nThe highest temperature was %d, on day %d", tempHst, day_h);
	printf("\nThe lowest temperature was %d, on day %d", tempLow, day_l);

	return 0;
}