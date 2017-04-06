/* CS261- Assignment 1 - Q.4*/
/* Name: Bryce Egley
 * Date: 01/14/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
     for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j){
            if (students[j].score < students[min].score){
                min = j;
            }
        }
        if (min != i){
            int temp = students[i].score;
            int temp2 = students[i].id;
            students[i].score=students[min].score;
            students[i].id=students[min].id;
            students[min].score=temp;
            students[min].id=temp2;
        }
    }
}
/*Add 1 to result*/
int * uniqueRandom(int n){
   int * array = malloc(n * sizeof(int));
   int * x = malloc(n * sizeof(int));
   for (int j = 0; j < n; j++) {
      array[j] = -1;
   }
   int y,go;
   for (int i = 0; i < n; i++) {
      y = rand()%n;
      go = 0;
      while (go == 0) {
         if (array[y] == -1) {
            array[y] = 0;
            x[i] = y;
            go = 1;
         } else {
            y = rand()%n;
         }
      } 
   }
   return x;
}

int main(){
   srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    struct student * students = malloc(n * sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
    int * x = malloc(n * sizeof(int));
    x = uniqueRandom(n);
    for (int i = 0; i < n; i++) {
        students[i].score = rand()%100+1;
        students[i].id = x[i]+1;
     }
    /*Print the contents of the array of n students.*/
    printf("Unsorted\n");
    for (int i = 0; i < n; i++) {
      printf("Student ID: %d\nStudent Score: %d\n",students[i].id,students[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students,n);
    /*Print the contents of the array of n students.*/
    printf("Sorted\n");  
    for (int i = 0; i < n; i++) {
      printf("Student ID: %d\nStudent Score: %d\n",students[i].id,students[i].score);
    }
    return 0;
}
