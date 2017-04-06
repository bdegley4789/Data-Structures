/* CS261- Assignment 1 - Q.3*/
/* Name: Bryce Egley
 * Date: 1/14/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j){
            if (number[j] < number[min]){
                min = j;
            }
        }
        if (min != i){
            //swap(number, i, min);
            int temp = number[i];
            number[i]=number[min];
            number[min]=temp;
        }
    }     
}

int main(){
   srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int * array = malloc(n * sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
    for (int i = 0; i < n; i++) {
      array[i] = rand()%n;
    }
    /*Print the contents of the array.*/
    printf("Unsorted\n");
    for (int i = 0; i < n; i++) {
      printf("%d:%d\n",i,array[i]);
    }
    /*Pass this array along with n to the sort() function.*/
    sort(array,n);
    /*Print the contents of the array.*/  
    printf("Sorted\n");  
    for (int i = 0; i < n; i++) {
      printf("%d:%d\n",i,array[i]);
    }
    return 0;
}
