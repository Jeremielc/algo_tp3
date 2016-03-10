/*main.c*/
//Jérémie Leclerc & Pierrick Hue
#include "header.h"

int main(int argc, char ** argv) {
    NODE summit;
    summit.value = 'a';
    summit.son = NULL;
    summit.brother = NULL;

    char c;
    char* string;
    bool result;

    do {
        printf("Commande ? ");
        c = getchar();
        switch(c)
        {
            case 'h' :
                printf("\nAide : \n");
                printf("a : Affichage des mots de l'arbre par ordre alphabétique \n");
                printf("r : Recherche d'un mot \n");
                printf("i : Insertion d'un mot \n");
                printf("s : Suppression d'un mot \n");
                printf("c : Chargement d'un fichier \n");
                printf("d : Destruction de l'arbre \n");
                printf("q : Quitter \n");
                break;

            case 'a' :
                printf("%s\n", "not implemented yet");
                break;

            case 'r' :
                result = false;
                printf("%s\n", "Que voulez vous rechercher ? ");
                scanf("%s", string);

                result = search_word(&summit, string);

                if (result == true) {
                    printf("%s\n", "Le mot est présent.");
                } else {
                    printf("%s\n", "Le mot n'est pas présent.");
                }
                break;

            case 'i' :
                string = (char*) calloc (26, sizeof(char));
                printf("Entrez une chaine de caractère : ");
                scanf("%s", string);
                insertion(&summit, string);
                break;

            case 's' :
                printf("%s\n", "not implemented yet");
                break;

            case 'c' :
                printf("%s\n", "not implemented yet");
                break;

            case 'd' :
                printf("%s\n", "not implemented yet");
                break;

            case 'q' :
                exit(0);
                break;
        }

        printf("\n");
        c = getchar();
    } while (1);

    return 0;
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
