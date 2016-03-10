all : main clean run

main : sources/main.o
	gcc sources/main.o sources/functions.o -Wall -o output

main.o : sources/main.c
	gcc -c sources/main.c -Wall

functions.o : sources/functions.c
	gcc -c sources/functions.c -Wall
clean :
	rm -rf sources/*.o

run :
	./output
