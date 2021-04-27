/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Rakhymzhan-Task1> 
 * @brief <I dont know what to write here>
 *
 * <I really dont know>
 *
 * @author <Rakhymzhan Mailybayev>
 * @date <27/04/2021>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_stats(test,SIZE);

}

int find_min(unsigned char *ptra,int n){
	int min =(int)*(ptra+0);
	for(int i=0;i<n;i++){
		if((int)*(ptra+i)<min){
			min=(int)*(ptra+i);
		}
	}
	return min;
}

int find_max(unsigned char *ptra,int n){
	int max = (int)*(ptra+0);
	for(int i=0;i<n;i++){
		if((int)*(ptra+i)>max){
			max=(int)*(ptra+i);
		}
	}
	return max;
}

double find_mean(unsigned char *ptra, int n){
	double mean = 0;
	for(int i=0;i<n;i++){
		mean=mean+(int)*(ptra+i);
	}
	return mean/(double)n;
}

double find_median(unsigned char *ptra, int n){
	if(n%2!=0){
		return *(ptra+(n/2));
	}
	return (*(ptra+((n-1)/2)) + *(ptra+(n/2)))/2.0;
}

void sort_arr(unsigned char *ptra, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(*(ptra+j)<*(ptra+j+1)){
				unsigned char temp = *(ptra+j);
				*(ptra+j)=*(ptra+j+1);
				*(ptra+j+1)=temp;
			}
		}
	}
}

void print_arr(unsigned char *ptra, int n){
	for(int i=0;i<n;i++){
		printf("%d ",*(ptra+i));
	}
}

void print_stats(unsigned char *ptra, int n){
	int min = find_min(ptra,n);
	int max = find_max(ptra,n);
	double average = find_mean(ptra,n);
	double median = find_median(ptra,n);

	printf("Array elements before sort: ");
	print_arr(ptra,n);
	printf("\n");

	sort_arr(ptra,n);

	printf("Array elements after sort: ");
	print_arr(ptra,n);
	printf("\n");

	printf("Maximum is equal to: %d\n",max);
	printf("Minimum is equal to: %d\n",min);
	printf("Average is equal to: %f\n",average);
	printf("Median is equal to: %f\n",median);
}

