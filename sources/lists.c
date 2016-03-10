/* lists.c */
//Jeremie Leclerc & Pierrick Hue

#include "header.h"

LIST* createList() {
    LIST* list = (LIST*) calloc(1, sizeof(LIST));
    return list;
}

void deleteList(LIST* list) {
    free(list);
}

void add(LIST* list, element elementToAdd) {

}
