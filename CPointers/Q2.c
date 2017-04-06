/* CS261- Assignment 1 - Q.2*/
/* Name: Bryce Egley
 * Date: 01/14/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    *b /= 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x,y,z;
    x=7;
    y=8;
    z=9;
    /*Print the values of x, y and z*/
    printf("x = %d\ny = %d\nz = %d\n",x,y,z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int * pointerX = &x;
    int * pointerY = &y;
    int answer = foo(pointerX,pointerY,z);
    /*Print the value returned by foo*/
    printf("Answer: %d\n",answer);
    /*Print the values of x, y and z again*/
    printf("x = %d\ny = %d\nz = %d\n",x,y,z);
    /*Is the return value different than the value of z?  Why?*/
    /*The return value is 18. z is 9. Its different because*/
    /*7*2 = 14 and 8 / 2 = 4. Putting those together is 18*/
    return 0;
}
    
    
