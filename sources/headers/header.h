/*header.h*/
//Jeremie Leclerc, Pierrick Hue

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LIST{
    char* value;
    struct LIST* next;
} LIST;

typedef struct NODE{
    char value;
    struct NODE* son;
    struct NODE* brother;
} NODE;

//main.c
void displayMenu();

//functions.c
void displayTree(NODE*);
void flush();
bool hasBrother(NODE*);
NODE* insertion(NODE*, char*);
void readDicoFromFile(char*, NODE*);
bool search_word(NODE*, char*);

//lists.c
LIST* add(LIST*, char*);
LIST* createList();
void deleteList(LIST*);
void displayList(LIST*);

#endif	// HEADER_H

