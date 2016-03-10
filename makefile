all : main clean run

main : sources/main.o
	gcc sources/main.o -Wall -o output

main.o : sources/main.c
	gcc -c sources/main.c -Wall

clean :
	rm -rf sources/*.o

run :
	./output
