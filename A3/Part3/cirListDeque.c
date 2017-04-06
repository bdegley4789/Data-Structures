#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	/* FIXME: you must write this */	
   q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink)); 
   assert(q != NULL);
   q->Sentinel->prev = q->Sentinel;
   q->Sentinel->next = q->Sentinel;
   q->size = 0;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
   struct DLink * temp = (struct DLink *) malloc (sizeof(struct DLink));
   temp->value = val;
   temp->next = temp;
   temp->prev = temp;
	/*temporary return value..you may need to change it*/
	return temp;	 

}

int isIn(struct cirListDeque *q, struct DLink *lnk){
   //1 for true, 0 for false
   if (q->size == 0 || lnk == q->Sentinel) {
      return 1;
   }
   int j = 1;
   struct DLink* temp = q->Sentinel->next;
   while(q->size >= j) {
      if (temp->value == lnk->value) {
         return 1;
      }
      temp = temp->next;
      j++;
   }
   return 0;
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */	 
   assert(q != NULL);
   assert(lnk != NULL);
   assert(isIn(q,lnk));
   
   struct DLink *temp = _createLink(v);
   if (q->size > 0) { 
   //lnk->next->prev = temp;
      lnk->next = temp;
      temp->prev = lnk;
      temp->next = q->Sentinel;
   } else {
      q->Sentinel = temp;
      q->Sentinel->next = temp;
      q->Sentinel->prev = temp;   
   }
   q->size++;
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */	 
   assert(q != NULL);
   struct DLink *temp = _createLink(val);
   if(q->size > 0) {
      temp->next = q->Sentinel;
      temp->prev = q->Sentinel->prev;
      temp->prev->next = temp;
   } else {
      q->Sentinel = temp;
      q->Sentinel->next = temp;
   }
   q->size++;
   q->Sentinel->prev = temp;
   //_addLinkAfter(q,q->Sentinel->prev,val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	
   assert(q != NULL);
   struct DLink *temp = _createLink(val);
   if (q->size >0) {
      temp->next = q->Sentinel;
      temp->prev = q->Sentinel->prev;
      temp->prev->next = temp;
      q->Sentinel->prev = temp;
   } else {
      q->Sentinel = temp;
   }
   q->size++;
   q->Sentinel = q->Sentinel->prev; //push sentinel to start
   //_addLinkAfter(q,q->Sentinel,val);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
   assert(q != NULL);
   assert(q->size != 0);
	return q->Sentinel->value; 
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
   assert(q != NULL);
   assert(q->size != 0);
	return q->Sentinel->prev->value; 
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */	 
   assert(q != NULL);
   assert(q->size != 0);
   //assert(isIn(q,lnk));
   lnk->next->prev = lnk->prev;
   lnk->prev->next = lnk->next;
   free(lnk);
   q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
   assert(q != 0);
   assert(q->size != 0);
   q->Sentinel = q->Sentinel->next;
   q->Sentinel->prev = q->Sentinel->prev->prev;
   //free(q->Sentinel);
   q->size--;
   //_removeLink(q,q->Sentinel);
   //q->Sentinel = q->Sentinel->next->next->next->next->prev;
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */	 
   /*assert(q != 0);
   assert(q->size != 0);
   q->Sentinel->prev = q->Sentinel->prev->next;
   q->Sentinel->prev->prev = q->Sentinel->prev->prev->prev;
   free(q->Sentinel->prev);
   q->size--;*/
  _removeLink(q,q->Sentinel->prev);
  q->Sentinel->prev = q->Sentinel->prev->prev;
   
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	free(q);
}

/* 	Deallocate all the links and the deque itself. 

	param: 	v		pointer to the dynamic array 
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteCirListDeque(struct cirListDeque *q) {
	free(q->Sentinel);
   //free(v->data);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
   if (q->size != 0) {
      return 0;
   } else {
	   return 1;
   }
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
   assert(q != NULL);
   assert(q->size != 0);
   int j = 0;
   struct DLink* temp = q->Sentinel;
   while(q->size > j) {
      printf("%d ",(int)temp->value);
      temp = temp->next;
      j++;
   }
   printf("\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
   assert(q != NULL);
   assert(q->size != 0);
   struct cirListDeque* temp = createCirListDeque();
   int i = 0;
   while (q->size > 1) {
      addBackCirListDeque(temp,backCirListDeque(q));
      if(i == 0) {
         addBackCirListDeque(temp,q->Sentinel->next->value);
         i++;
      }
      removeBackCirListDeque(q);
   }
   addBackCirListDeque(temp,backCirListDeque(q));
   while (temp->size > 1) {
      addBackCirListDeque(q,frontCirListDeque(temp));
      removeFrontCirListDeque(temp);
   }
   addBackCirListDeque(q,frontCirListDeque(temp));
   free(temp);
}