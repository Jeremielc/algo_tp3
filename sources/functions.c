/*functions.c*/
//Jérémie Leclerc & Pierrick Hue

#include "header.h"

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

LIST* readDicoFromFile(char* path) {
	FILE* canal;
	canal = fopen(path, "rt");

	LIST* list = createList();
	char* string = (char*) calloc(30, sizeof(char));

	while(!feof(canal)) {
		fscanf(canal, "%s", string);
		add(list, string);
	}

	fclose(canal);
	printf("%s\n", "Fichier lu !");

	displayList(list);
	return list;
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

void fonction_bidon() {
	return 1;
}
