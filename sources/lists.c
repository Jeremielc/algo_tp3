/* lists.c */
//Jeremie Leclerc & Pierrick Hue

#include "header.h"

void add(LIST* list, char* elementToAdd) {
    LIST* new = createList();
    new->value = elementToAdd;

    if (list->next == NULL) {
        list->next = new;
    } else {
        while (list->next != NULL) {
            list = list->next;
        }

        list->next = new;
    }
}

LIST* createList() {
    LIST* list = (LIST*) calloc(1, sizeof(LIST));
    list->value = (char*) calloc(30, sizeof(char));
    list->next = NULL;

    return list;
}

void deleteList(LIST* list) {
    free(list->value);

    if (list->next != NULL) {
        deleteList(list->next);
    }

    free(list);
}

void displayList(LIST* list) {
    while (list->next != NULL) {
        if (list->value != NULL) {
            printf("%s\n", list->value);
        }
        list = list->next;
    }
}
