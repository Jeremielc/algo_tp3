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

void flush();
NODE* insertion(NODE*, char*);
bool search_word(NODE*, char*);
