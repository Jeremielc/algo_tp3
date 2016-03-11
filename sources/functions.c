/*functions.c*/
//Jérémie Leclerc & Pierrick Hue

#include "header.h"

void displayTree(NODE* summit) {
	NODE* psummit = summit;

	do {
		printf("%s\t", summit->value);
		psummit = summit->brother;
	} while (hasBrother(psummit));
}

bool hasBrother(NODE* node) {
	if (node == NULL) {
		return false;
	} else {
		if (node->brother == NULL) {
			return false;
		} else if (node->brother != NULL) {
			return true;
		}
	}
}

NODE* insertion(NODE* tree, char* string) {
	if (tree == NULL){                                                          //Dans le cas où il n'y a plus de branche
		tree = (NODE *) calloc(1, sizeof(NODE));                                //On alloue de la mémoire

		tree->value = *string;                                                  //La valeur de string est affectee a tree
		tree->son = NULL;
		tree->brother = NULL;

		if (*string != '\0'){
			tree->son = insertion(tree->son, string + 1);
		}
	} else {
		if (tree->value == *string){                          //La première valeur du mot coincide avec celle du dictionnaire.
			tree->son = insertion(tree->son, string + 1);
		} else {             	                                                //La première valeur ne coincide pas
			tree->brother = insertion(tree->brother, string);
		}
	}

	return tree;
}

void flush() {
    char c;
    do {
        c = getchar();
    } while (c != NULL && c != '\n');
}

/*LIST* readDicoFromFile(char* path) {
	FILE* canal;
	canal = fopen(path, "rt");

	LIST* list = createList();
	LIST* plist = list;
	char* string = (char*) calloc(30, sizeof(char));

	while(!feof(canal)) {
		fscanf(canal, "%s", string);
		plist = add(plist, string);
	}

	fclose(canal);
	printf("%s\n", "Fichier lu !");

	return list;
}*/

void readDicoFromFile(char* path, NODE* summit) {
	FILE* canal;
	canal = fopen(path, "rt");

	char* string = (char*) calloc(30, sizeof(char));

	while(!feof(canal)) {
		fscanf(canal, "%s", string);
		insertion(summit, string);
	}

	fclose(canal);
}

bool search_word(NODE* p, char* w) {
    if(p == NULL || w == NULL) {
        return false;
    }

    // Pour chaque noeud
    for (;p != NULL; p = p->brother) {
        if(*w == '\0' && p->value == '\0') {
            return true;
        }

        if(p->value == *w){
            return search_word(p->son, w + 1);
        }
    }

    return false;
}
