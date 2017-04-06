default: prog

linkedList.o: linkedList.c linkedList.h
	gcc -Wall -g -std=c99 -c linkedList.c	

testLinkedList.o: linkedList.h testLinkedList.c
	gcc -Wall -g -std=c99 -c testLinkedList.c

prog: linkedList.o testLinkedList.o
	gcc -Wall -g -std=c99 -o prog linkedList.o testLinkedList.o

linkedListMain.o: linkedListMain.c
	gcc -Wall -g -std=c99 -o linkedListMain.c

test: linkedList.o linkedListMain.o
	gcc -Wall -g -std=c99 -o test linkedListMain.o linkedList.o
		
clean:
	rm linkedList.o
	rm testLinkedList.o

