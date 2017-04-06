/*Bryce Egley*/
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   struct linkedList *lst;
   lst = createLinkedList(); /*create*/
   printf("Creating: ");
   if (isEmptyList(lst)) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   addBackList(lst, 4); /*Add back list*/
   int m = 1;
   if (backList(lst) == 4) {
      m++;
   }
   addBackList(lst, 5);
   if (backList(lst) == 5) {
      m++;
   }
   addBackList(lst, 6);
   if (backList(lst) == 6) {
      m++;
   }
   printf("Checking addBackList: ");
   if (m == 4) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   int n = 1;
   addFrontList(lst, 3); /*Add front list*/
   if (frontList(lst) == 3) {
      n++;
   }
   addFrontList(lst, 2);
   if (frontList(lst) == 2) {
      n++;
   }
   addFrontList(lst, 1); //list is now 1,2,3,4,5,6
   if (frontList(lst) == 1) {
      n++;
   }
   printf("Checking addFrontList: ");
   if (n == 4) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   /*printf("Check Print 1 2 3 4 5 6\n");
      printf("            ");
   _printList(lst); //1,2,3,4,5,6*/
   printf("Checking isEmpty: "); /*isEmpty*/
   if(isEmptyList(lst) == 0) { //0 or False
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   printf("Checking containsList: ");
   if (containsList(lst, 4)) { //1 or True
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   printf("Checking containsList: ");
   if(containsList(lst,9)){ //0 or False
      printf("FAILED\n");
   } else {
      printf("PASSED\n");
   }
   removeBackList(lst); //remove 6
   printf("Checking removeBackList: ");
   if (backList(lst) == 6) {
      printf("FAILED\n");
   } else {
      printf("PASSED\n");
   }
   addList(lst, 8); //1,2,3,4,5,8
   printf("Checking addList: ");
   if (backList(lst) == 8) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   addFrontList(lst,7); //7,1,2,3,4,5,8
   /*printf("Check Print 7 1 2 3 4 5 8\n");
   printf("            ");
   _printList(lst);*/
   removeFrontList(lst);  /*remove Front list*/
   printf("Checking removeFrontList: ");
   if(frontList(lst) == 7) {
      printf("FAILED\n");
   } else {
      printf("PASSED\n");
   } /*remove back list*/
   removeBackList(lst); /*1,2,3,4,5*/
   /*printf("Check Print 1 2 3 4 5\n");
   printf("            ");
   _printList(lst);*/
   removeList(lst, 3); /*1,2,4,5*/
   printf("Check removeList: ");
   if(!containsList(lst,3)) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }  
   removeList(lst,2); /*1,4,5*/
   /*printf("Check Print 1 4 7 5\n");
   printf("            ");
   _printList(lst);*/
   printf("Check Frontlist: ");
   if(frontList(lst) == 1) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   printf("Check isEmpty: ");
   if(isEmptyList(lst)) {
      printf("FAILED\n");
   } else {
      printf("PASSED\n");
   }
   removeBackList(lst); /*1,4,7*/
   removeBackList(lst); /*1,4*/
   removeBackList(lst); /*1*/
   printf("Check isEmpty: ");
   if(isEmptyList(lst)) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
   int lk = 0;
   if(isEmptyList(lst)) {
      lk++;
   }
   deleteLinkedList(lst); /*checking delete list*/
   printf("Checking deleteList: ");
   if (lst != 0 && lst != NULL) {
      lk++;
   }
   if(lk == 2) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }
	/* Test your linked list in here! */
	printf("Hello from test code!\n");
	return 0;
}


