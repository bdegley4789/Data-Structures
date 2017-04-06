/* CS261- Assignment 1 - Q.5*/
/* Name: Bryce Egley
 * Date: 01/14/2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
     for (int i = 0; i < 20; i++) {
      if (i % 2 == 0) {
         if (word[i] > 'a') {
            word[i] = toUpperCase(word[i]);
         }
      } else {
         if (word[i] < 'a') {
            word[i] = toLowerCase(word[i]);
         }
      }
     }
}

int main(){
    /*Read word from the keyboard using scanf*/
    printf("Enter a word: ");
    char * word = malloc(20 * sizeof(word));
    scanf("%s",word);
    /*Call studly*/
    studly(word);
    /*Print the new word*/
    printf("New Word: %s\n",word);
    return 0;
}
