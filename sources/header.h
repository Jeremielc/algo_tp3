/*header.h*/
//Jeremie Leclerc, Pierrick Hue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* value;
    struct LIST* next;
} LIST;

typedef struct {
    char value;
    struct NODE* son;
    struct NODE* brother;
} NODE;

//functions.c
void displayTree(NODE*);
void flush();
bool hasBrother(NODE*);
NODE* insertion(NODE*, char*);
//LIST* readDicoFromFile();
void readDicoFromFile(char*, NODE*);
bool search_word(NODE*, char*);

//lists.c
LIST* add(LIST*, char*);
LIST* createList();
void deleteList(LIST*);
void displayList(LIST*);
