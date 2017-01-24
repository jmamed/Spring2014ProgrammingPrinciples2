//Jason Mamed
//CS 1412
//March 26, 2014
//lab7.1.c

#include<stdio.h>
#include "sorting.h"


int main(void){
	int cnt=0;
	int cnttwopointoh=0;
	int i;
	int size=26;
	int alphabet[]= {'A','E','O','D','B','Q','G','V','Y','J','Z','S','M','N','C','P','F','R','L','T','U','H','W','X','I','K'};
	int notalphabet[]={'A','E','O','D','B','Q','G','V','Y','J','Z','S','M','N','C','P','F','R','L','T','U','H','W','X','I','K'};
printf("Bubble Sort:\n");
bubble_sort(alphabet,size,&cnt);
for(i=0;i<26;i++){
	printf("%c",alphabet[i]);
}
printf("\n%d\n",cnt);

printf("Selection Sort:\n");
selection_sort(notalphabet,size,&cnttwopointoh);
for(i=0;i<26;i++){
	printf("%c",notalphabet[i]);
}
printf("\n%d",cnttwopointoh);

getchar();
return 0;

}