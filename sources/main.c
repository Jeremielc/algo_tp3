/*main.c*/
//Jérémie Leclerc & Pierrick Hue

#include "headers/header.h"

int main(int argc, char ** argv) {
    NODE summit;
    summit.value = 'a';
    summit.son = NULL;
    summit.brother = NULL;

    char c;
    char* string;
    bool result;
    LIST* list;

    do {
        printf("Commande ? ");
        c = getchar();
        switch (c) {
            case 'h':
                printf("\nAide : \n");
                printf("a : Affichage des mots de l'arbre par ordre alphabétique \n");
                printf("r : Recherche d'un mot \n");
                printf("i : Insertion d'un mot \n");
                printf("s : Suppression d'un mot \n");
                printf("c : Chargement d'un fichier \n");
                printf("d : Destruction de l'arbre \n");
                printf("q : Quitter \n");
                break;

            case 'a':
                displayTree(&summit);
                break;

            case 'r':
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

            case 'i':
                string = (char*) calloc(26, sizeof (char));
                printf("Entrez une chaine de caractère : ");
                scanf("%s", string);
                insertion(&summit, string);
                break;

            case 's':
                printf("%s\n", "not implemented yet");
                break;

            case 'c':
                readDicoFromFile("./dico/dico.fr", &summit);
                break;

            case 'd':
                printf("%s\n", "not implemented yet");
                break;

            case 'q':
                exit(0);
                break;

            default:
                printf("%s\n", "Use menu commands.");
                break;
        }

        printf("\n");
        c = getchar();
    } while (1);

    return 0;
}
