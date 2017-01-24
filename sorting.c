//Jason Mamed
//CS 1412
//March 26, 2014
//sorting.c

#include "sorting.h"

int bubble_sort(int arr[], int length,int *cnt){
	int n=length;
	int swap=0;
	int i,j;
	for( i = 0; i< (n-1); i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
				

			}(*cnt)++;
			
		}
	}
}
void selection_sort(int array[], int length, int *cntagain){
	int current=0;
	int currentIndex=0;
	int i,j;
	for(i=0;i<length;i++){
		current=array[i];

		for(j=i;j<length;j++){
			if(current>=array[j]){
				current=array[j];
				currentIndex=j;
				(*cntagain)=*cntagain+1;

				}
		}
		        //printf("%c ",array[currentIndex] );

		if(currentIndex !=i){
				array[currentIndex]=array[i];
				array[i]=current;
				(*cntagain)=*cntagain+1;
	}
}
}