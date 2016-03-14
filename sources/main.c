/*main.c*/
//Jérémie Leclerc & Pierrick Hue

#include "headers/header.h"

int main(int argc, char ** argv) {
    NODE summit;
    summit.value = 'a';
    summit.son = NULL;
    summit.brother = NULL;

    char c;
    char* string = (char*) calloc(30, sizeof (char));
    bool result = false;
    bool init = false;
    LIST* list;

    do {
        displayMenu();
        printf("Commande ? ");
        c = getchar();

        switch (c) {
            case 'h':
                printf("\nAide : \n");
                displayMenu();
                break;
            case 'a':
                if (init) {
                    displayTree(&summit, 0, string);
                    system("sleep 10s");
                }
                break;
            case 'r':
                printf("%s\n", "Que voulez vous rechercher ? ");
                scanf("%s", string);

                result = search_word(&summit, string);

                if (result == true) {
                    printf("%s\n", "Le mot est présent.");
                } else {
                    printf("%s\n", "Le mot n'est pas présent.");
                }

                system("sleep 2s");
                break;
            case 'i':
                printf("Entrez une chaine de caractère : ");
                scanf("%s", string);
                insertion(&summit, string);
                init = true;
                break;
            case 's':
                if (init) {
                    printf("%s\n", "Not implemented yet");
                    //il faut rechercher le mot pour le supprimer.
                    //ensuite on supprime les fils puis on raccorde la racine
                    //du mot aux frere des mots suivants.
                }
                break;
            case 'c':
                readDicoFromFile("./dico/dico.fr", &summit);
                init = true;
                break;
            case 'd':
                destroyTree(&summit);
                summit.value = '\0';
                break;
            case 'q':
                exit(0);
                free(string);
                break;
            default:
                printf("%s\n", "Use menu commands.");
                break;
        }

        printf("\n");
    } while (1);

    return EXIT_SUCCESS;
}

void displayMenu() {
    system("clear");
    printf("a : Affichage des mots de l'arbre par ordre alphabétique \n");
    printf("r : Recherche d'un mot \n");
    printf("i : Insertion d'un mot \n");
    printf("s : Suppression d'un mot \n");
    printf("c : Chargement d'un fichier \n");
    printf("d : Destruction de l'arbre \n");
    printf("q : Quitter \n");
}
