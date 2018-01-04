//I declare, upon my honor, that I made this MP by myself.

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int arr1[1000000], arr2[1000000], arr3[1000000];
void bubbleSort(int*, FILE*);
void selectionSort(int*, FILE*);
void insertionSort(int*, FILE*);
int main(){//Main function
    int i,m;//Declaring of two variables for index and storing numbers
    FILE *fp,*bfp,*sfp,*ifp;//pointers to be used in storing the memory
	fp = fopen("numbers.dat","r");
	bfp = fopen("bubblesort.dat", "w");,\
	sfp = fopen("selectionsort.dat", "w");
	ifp = fopen("insertionsort.dat", "w");
	if(fp == NULL){
		printf("\nI couldn't open results.dat for writing.");
	}
	else{//I copy everything to their respective arrays first
		for(i=0;(fscanf(fp,"%i", &m)!=EOF);i++){
			arr1[i] = m;
			arr2[i] = m;
			arr3[i] = m;
		}
	}
        printf("\nBubble Sort Algorithm Before:\n");
        timestamp();//Initial time stamp for future comparisons
		bubbleSort(arr1,bfp);//calling the respective functions
		printf("\nSelection Sort Algorithm Before:\n");
		timestamp();
		selectionSort(arr2,sfp);
		printf("\nInsertion Sort Algorithm Before:\n");
		timestamp();
		insertionSort(arr3,ifp);
    fclose(bfp);//idk but somehow it needs o be closed
    fclose(sfp);
    fclose(ifp);
	return 0;
}
void bubbleSort(int *arr1,FILE *bfp){//Bubble sorting
	int i, length = 1000000, length2=length, m,flag=0, temp;
    for(m=0; m<length2-1 ; m=0,length2--,flag=0){//to repeat this string length-1 times
        for(i=0;i<(length-1);i++){//comparing to the one beside it
            if(*(arr1+i) >*((arr1+i)+1)){//to interchange
                temp = *(arr1+i);
                *(arr1+i) = *((arr1+i)+1);
                *((arr1+i)+1) = temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
	for(i=0; i<length; i++){//printing to outtput
		fprintf(bfp,"%i\n", arr1[i]);
	}
    printf("\nBubble Sort Algorithm After:\n");
    timestamp();
}
void selectionSort(int *arr2,FILE *sfp){//selection sorting
	int i, length = 1000000, min, m,n, temp;//initialization
		for(n=0,min=0;n < (length-1) ;n++){//repeats over and over with accumulating mins until min reaches max
            min=n;
            for(i = min+1; i < (length-1) ; i++){//finds the smallest number
                if(*(arr2+min)>*(arr2+i)){
                    min=i;
                }
            }
            if(arr2+min != arr2+n){//interchanges rightful place
                temp = *(arr2+min);
                *(arr2+min) = *(arr2+n);
                *(arr2+n) = temp;
            }
		}
	for(i=0; i<length-1; i++){
        fprintf(sfp,"%d\n", *(arr2+i));
	}
    printf("\nSelection Sort Algorithm After:\n");
    timestamp();
}
void insertionSort(int *S3,FILE* ifp){
    int i, length = 1000000, length2=length, m, temp;
        for(i=0;i<(length-1);i++){
            if(*(arr3+i) > *((arr3+i)+1)){
                temp = *(arr3+i+1);
                for(m=i;*(arr3+m)> temp && m>=0;m--){
                    *((arr3+m)+1)= *(arr3+m);
                }
                *((arr3+m)+1)= temp;
            }
        }
	for(i=0; i<length; i++){
		fprintf(ifp,"%d\n", *(arr3+i));
	}
printf("\nInsertion Sort Algorithm After\n");
timestamp();
}
void timestamp(){
	time_t result = time(NULL);
	printf("%s\n", (ctime(&result)));
}
