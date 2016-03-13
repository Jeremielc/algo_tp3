all : main clean

main : sources/main.o sources/functions.o sources/lists.o
	gcc sources/*.o -o output

main.o : sources/main.c
	gcc -c sources/main.c

functions.o : sources/functions.c
	gcc -c sources/functions.c

list.o : sources/lists.c
	gcc -c sources/lists.c

clean :
	rm -rf sources/*.o
