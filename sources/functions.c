/*functions.c*/
//Jérémie Leclerc & Pierrick Hue

#include "headers/header.h"

void destroyTree(NODE* summit) {
    if (summit == NULL) {
        return;
    } else {
        if (summit->son != NULL) {
            destroyTree(summit->son);
            free(summit->son);
        }
        
        if (summit->brother != NULL) {
            destroyTree(summit->brother);
            free(summit->brother);
        }
    }
}

void displayTree(NODE* summit, int depth, char* root) {
    root[depth] = summit->value;
    if (root[depth] == '\0') {
        printf("%s\n", root);
    }

    if (summit != NULL) {
        if (summit->son != NULL) {
            displayTree(summit->son, depth + 1, root);
        }

        if (summit->brother != NULL) {
            displayTree(summit->brother, depth, root);
        }
    }
}

NODE* insertion(NODE* tree, char* string) {
    if (tree == NULL) {                             //Dans le cas où il n'y a plus de branche
        tree = (NODE *) calloc(1, sizeof (NODE));   //On alloue de la mémoire

        tree->value = *string;                      //La valeur de string est affectee a tree
        tree->son = NULL;
        tree->brother = NULL;

        if (*string != '\0') {
            tree->son = insertion(tree->son, string + 1);
        }
    } else {
        if (tree->value == *string) {               //La première valeur du mot coincide avec celle du dictionnaire.
            tree->son = insertion(tree->son, string + 1);
        } else {                                    //La première valeur ne coincide pas
            tree->brother = insertion(tree->brother, string);
        }
    }

    return tree;
}

void readDicoFromFile(char* path, NODE* summit) {
    FILE* canal;
    canal = fopen(path, "rt");

    char* string = (char*) calloc(30, sizeof (char));

    while (!feof(canal)) {
        fscanf(canal, "%s", string);
        insertion(summit, string);
    }

    fclose(canal);
}

bool search_word(NODE* summit, char* string) {
    if (summit == NULL || string == NULL) {
        return false;
    }
    
    while (summit != NULL) {
        if (*string == '\0' && summit->value == '\0') {
            return true;
        }

        if (summit->value == *string) {
            return search_word(summit->son, string + 1);
        }
        
        summit = summit->brother;
    }

    return false;
}
