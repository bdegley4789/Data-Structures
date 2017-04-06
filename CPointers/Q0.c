/* CS261- Assignment 1 - Q. 0*/
/* Name: Bryce Egley
 * Date: 01/13/2106
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value of iptr* is: %d\n",*iptr);
     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr* is: %p\n",iptr);
     /*Print the address of iptr itself*/
     printf("The address of iptr* is: %p\n",&iptr);
}

int main(){
    
    /*declare an integer x*/
    int x;
    x = 0;
    /*print the address of x*/
    printf("Address of x: %p\n",&x);
    /*Call fooA() with the address of x*/
    int * pointerX;
    pointerX = &x;
    fooA(pointerX);
    /*print the value of x*/
    printf("Value of x: %d\n",x);
    return 0;
}
