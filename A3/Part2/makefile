default: prog

dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -Wall -g -std=c99 -c dynamicArray.c	

testDynamicArray.o: dynamicArray.h dynamicArrayMain.c
	gcc -Wall -g -std=c99 -c dynamicArrayMain.c

prog: dynamicArray.o dynamicArrayMain.o
	gcc -Wall -g -std=c99 -o prog dynamicArray.o dynamicArrayMain.o
		
clean:
	rm dynamicArray.o
	rm dynamicArrayMain.o
