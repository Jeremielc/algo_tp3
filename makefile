all : main clean run

main : sources/main.o sources/functions.o sources/lists.o
	gcc sources/*.o -Wall -o output

main.o : sources/main.c
	gcc -c sources/main.c -Wall

functions.o : sources/functions.c
	gcc -c sources/functions.c -Wall

list.o : sources/lists.c
	gcc -c sources/lists.c -Wall

clean :
	rm -rf sources/*.o

run :
	./output
