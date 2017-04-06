/*Bryce Egley*/
#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   struct cirListDeque *q;  
   q = createCirListDeque(); /*create*/
   printf("Creating: ");
   if (isEmptyCirListDeque(q)) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   addFrontCirListDeque(q, 1);/*1*/
   printf("Add Front: ");
   if (frontCirListDeque(q) == 1) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   addBackCirListDeque (q, 2); /*1,2*/
   printf("Check addBack: ");
   if (backCirListDeque(q) == 2) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   int m = 1;
   addFrontCirListDeque(q, 3); /*3,1,2*/
   if (frontCirListDeque(q) == 3) {
      m++;
   }
   addFrontCirListDeque(q, 4); /*4,3,1,2*/
   if (frontCirListDeque(q) == 4) {
      m++;
   }
   addFrontCirListDeque(q, 5); /*5,4,3,1,2*/
   if (frontCirListDeque(q) == 5) {
      m++;
   }
   printf("Check addFront: ");
   if (m == 4) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   printf("Check Print 5 4 3 1 2\n");
   printf("            ");
   printCirListDeque(q);
   removeFrontCirListDeque(q); /*Removed 5 so 4,3,1,2*/
   printf("Checking front remove: ");
   if (frontCirListDeque(q) == 4) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   printf("Check removeBack: ");
   removeBackCirListDeque(q); /*Remove 2 so 4,3,1*/
   if (backCirListDeque(q) == 1) { /*Size now 1*/
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   removeBackCirListDeque(q); /*Remove 1 so 4,3*/
   removeBackCirListDeque(q); /*Remove 3 so 4*/
   isEmptyCirListDeque(q); /*0 or False*/
   printf("Check is isEmpty(): ");
   if(isEmptyCirListDeque(q) == 0) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   addFrontCirListDeque(q, 3); /*3,4*/
   addFrontCirListDeque(q, 2); /*2,3,4*/
   addFrontCirListDeque(q, 1); /*1,2,3,4*/
   printf("Check Print: 1 2 3 4\n");
   printf("             "); 
   printCirListDeque(q);
   printf("Check Front: ");
   if (frontCirListDeque(q) == 1) { /*Checking front list*/
      printf("PASSED\n");
   } else {
      printf("FAILED");
   }
   printf("Check Back: ");
   if (backCirListDeque(q) == 4) {
      printf("PASSED\n");
   } else {
      printf("FAILED");
   }
   reverseCirListDeque(q);
   printf("Check Reverse: 4 3 2 1\n");
   printf("               ");
   printCirListDeque(q); /*4,3,2,1*/
   deleteCirListDeque(q);
   printf("Check Delete/Free: ");
   if (q == NULL) {
      printf("FAILED\n");
   } else {
      printf("PASSED\n");
   }
   
	/*Test your linked list in here!*/

	printf("Hello from test code!\n");
	return 0;
}