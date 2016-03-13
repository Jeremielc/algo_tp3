/* lists.c */
//Jeremie Leclerc & Pierrick Hue

#include "headers/header.h"

LIST* add(LIST* list, char* elementToAdd) {
    LIST* new = createList();
    new->value = elementToAdd;

    list->next = new;

    return new;
}

LIST* createList() {
    LIST* list = (LIST*) calloc(1, sizeof(LIST));
    list->value = (char*) calloc(30, sizeof(char));
    list->next = NULL;

    return list;
}

void deleteList(LIST* list) {
    if (list->value != NULL) {
        free(list->value);
    }

    if (list->next != NULL) {
        deleteList(list->next);
    }

    free(list);
}

void displayList(LIST* list) {
    if (list == NULL) {
        return;
    }
    
    do {
        printf("%s\n", list->value);
        list = list->next;
    }while (list != NULL);
}
