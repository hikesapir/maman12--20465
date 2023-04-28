my_set: set.o my_set.o
	gcc -ansi -Wall -pedantic set.o my_set.o -o my_set
set.o: set.c set.h
	gcc -c -ansi -Wall -pedantic set.c -o set.o
my_set.o: my_set.c
	gcc -c -ansi -Wall -pedantic my_set.c -o my_set.o
