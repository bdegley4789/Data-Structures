/* CS261- Assignment 1 - Q.1*/
/* Name: Bryce Egley
 * Date: 01/13/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student * data = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return data;
}

/*Add 1*/
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

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     int * x = malloc(10 * sizeof(int));
     x = uniqueRandom(10);
     for (int i = 0; i < 10; i++) {
      students[i].id = x[i]+1;
      students[i].score = rand()%100+1;
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
   for (int i = 0; i < 10; i++) {
      printf("ID: %d Score: %d\n",students[i].id,students[i].score);  
   }         
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
   int minimum, maximum;
   float average;
   minimum = 101;
   maximum = -1;
   average = 0;
   for (int i = 0; i < 10; i++) {
      average += students[i].score;
      if (students[i].score < minimum) {
         minimum = students[i].score;
      }
      if (students[i].score > maximum) {
         maximum = students[i].score;
      }       
   }
   average = average / 10;
   printf("Minimum Score: %d\n", minimum);
   printf("Maximum Score: %d\n", maximum);
   printf("Average Score: %f\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     /*struct student* stud = (student*)malloc(10);
     realloc(stud);*/
     free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
