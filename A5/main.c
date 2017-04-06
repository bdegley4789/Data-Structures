#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');
        FILE *ofp;
        ofp = NULL;
        char *mode; /*r read w write*/
        char fname[50];
        char desc[50];
         if (cmd == 'l') {
             mode = "r";
            printf("Please enter the filename: ");
             scanf("%200[^\n]", fname);
             ofp = fopen(fname, mode); /*reading file*/
            if (ofp != NULL) {
                loadList(mainList,ofp);
                printf("The list has been loaded from file successfully.\n");
                fclose(ofp);
            } else {
                printf("File not found!\n");
            }
         } else if (cmd == 's') {
             mode = "w";
             if (sizeDynArr(mainList) != 0) {
                 printf("Please enter the filename: ");
                 scanf("%200[^\n]", fname);
                 ofp = fopen(fname,mode);
                 if (ofp != NULL) {
                     saveList(mainList,ofp);
                     fclose(ofp);
                     printf("The list has been saved into the file successfully\n");
                 } else {
                     printf("File not found!\n");
                 }
            } else {
                 printf("Your to-do list is empty!\n");
             }
         } else if (cmd == 'a') {
             int priority;
             TaskP temp = createTask(priority,desc);
             printf("Please enter the task description: ");
             scanf("%200[^\n]", desc);
             printf("Please enter the task priority (0-999): ");
             scanf("%d",&priority);
             printf("The Task '%s' has been added to your to-do list.\n",desc);
             addHeap(mainList, temp, compare);
         } else if (cmd == 'g') {
             if(sizeDynArr(mainList) != 0) {
                 TaskP temp = getMinHeap(mainList);
                 printf("Your first task is: %s\n",temp->description);
             } else {
                 printf("Your to-do list is empty!\n");
             }
         } else if (cmd == 'r') {
             if(sizeDynArr(mainList) != 0) {
                 TaskP temp = getMinHeap(mainList);
                 printf("Your first task: %s has been removed from the list.\n",temp->description);
                 removeMinHeap(mainList,compare);
             } else {
                 printf("Your to-do list is empty!\n");
             }
         } else if (cmd == 'p') {
             if (sizeDynArr(mainList) != 0) {
                sortHeap(mainList, compare);
                 printList(mainList);
             } else {
                 printf("Your to-do list is empty!\n");
             }
         }
      /* Fixme:  Your logic goes here! */

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
