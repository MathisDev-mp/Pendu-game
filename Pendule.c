#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	void afficherPendu(int erreurs) {
    printf("\n");
    switch (erreurs) {
        case 0:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
    }
    printf("\n");
}
	char choix;
	do{
printf("Allez vous jouer seule ou a deux? 's' pour jouer seule et '2' pour jouer a deux\n");
scanf(" %c", &choix);
 if (choix != 's' && choix != '2') {

        printf("Veuillez donner une reponse valide\n");
    }
}while(choix!='s'&& choix!='2');
//Mode 1 joueur
if (choix=='s'){
	printf("=== Jeu du Pendu mode 1 joueur ===\n");
 char *mot[] = {
    "ordinateur",
    "clavier",
    "programmation",
    "linux"
};
      int nbMots = 4;
srand(time(NULL));
int index = rand() % nbMots;
char *motSecret = mot[index];
    int longueur = strlen(motSecret);
    char motTrouve[longueur+1];
    int erreurs = 0;
    int maxErreurs = 6;
    bool gagne = false;
    for (int i = 0; i < longueur; i++) {
        motTrouve[i] = '_';
    }
    motTrouve[longueur] = '\0';

    while (erreurs < maxErreurs && !gagne) {
        printf("Mot: %s\n", motTrouve);
        printf("Entrez une lettre: ");
        char lettre;
        scanf(" %c", &lettre);

        bool trouve = false;
        for (int i = 0; i < longueur; i++) {
            if (motSecret[i] == lettre) {
                motTrouve[i] = lettre;
                trouve = true;
            }
        }

        if (!trouve) {
            erreurs++;
            printf("Mauvaise lettre! Erreurs: %d/%d\n", erreurs, maxErreurs);
            afficherPendu(erreurs);
        }

        if (strcmp(motTrouve, motSecret) == 0) {
            gagne = true;
        }
    }

    if (gagne) {
        printf("Bravo! Vous avez trouve le mot: %s\n", motSecret);
    } else {
        printf("Perdu! Le mot était: %s\n", motSecret);
    }
    //Mode 2 joueur
}else{

void jouerDuel(char *motJ1, char *motJ2) {

    int longueur1 = strlen(motJ1);
    char trouve1[longueur1 + 1];
    int erreurs1  = 0;
    bool gagne1   = false;
    for (int i = 0; i < longueur1; i++) trouve1[i] = '_';
    trouve1[longueur1] = '\0';

    int longueur2 = strlen(motJ2);
    char trouve2[longueur2 + 1];
    int erreurs2  = 0;
    bool gagne2   = false;
    for (int i = 0; i < longueur2; i++) trouve2[i] = '_';
    trouve2[longueur2] = '\0';

    int maxErreurs  = 6;
    int joueurActuel = 1;   

    while (!gagne1 && !gagne2
           && erreurs1 < maxErreurs
           && erreurs2 < maxErreurs) {

        bool bonneLettre;

        do {
            printf("\n========================\n");
            printf("Mot du Joueur 1 : %s\n", trouve1);
            printf("Erreurs J1      : %d/%d\n", erreurs1, maxErreurs);
            printf("Mot du Joueur 2 : %s\n", trouve2);
            printf("Erreurs J2      : %d/%d\n", erreurs2, maxErreurs);
            printf("========================\n");
            printf("Tour du Joueur %d : ", joueurActuel);

            char lettre;
            scanf(" %c", &lettre);

            bonneLettre = false;

            if (joueurActuel == 1) {
                for (int i = 0; i < longueur2; i++) {
                    if (motJ2[i] == lettre) {
                        trouve2[i] = lettre;
                        bonneLettre = true;
                    }
                }
                if (bonneLettre) {
                    printf("Bonne lettre ! Joueur 1 rejoue !\n");
                    if (strcmp(trouve2, motJ2) == 0) {
                        gagne1 = true;
                        printf("\nBravo Joueur 1 ! Vous avez trouve le mot de J2 : %s\n", motJ2);
                    }
                } else {
                    erreurs1++;
                    printf("Mauvaise lettre ! Erreurs J1 : %d/%d\n", erreurs1, maxErreurs);
                     afficherPendu(erreurs1);
                    joueurActuel = 2;   
                }
            } else {
                for (int i = 0; i < longueur1; i++) {
                    if (motJ1[i] == lettre) {
                        trouve1[i] = lettre;
                        bonneLettre = true;
                    }
                }
                if (bonneLettre) {
                    printf("Bonne lettre ! Joueur 2 rejoue !\n");
                    if (strcmp(trouve1, motJ1) == 0) {
                        gagne2 = true;
                        printf("\nBravo Joueur 2 ! Vous avez trouve le mot de J1 : %s\n", motJ1);
                    }
                } else {
                    erreurs2++;
                    printf("Mauvaise lettre ! Erreurs J2 : %d/%d\n", erreurs2, maxErreurs);
                     afficherPendu(erreurs2);
                    joueurActuel = 1;  
                }
            }

        } while (bonneLettre && !gagne1 && !gagne2
                 && erreurs1 < maxErreurs
                 && erreurs2 < maxErreurs);
    }

    printf("\n======== RÉSULTAT FINAL ========\n");
    if (gagne1){
        printf("Joueur 1 gagne ! Il a trouve : %s\n", motJ2);
    	}else if (gagne2){
        printf("Joueur 2 gagne ! Il a trouve : %s\n", motJ1);
    	}else if (erreurs1 >= maxErreurs && erreurs2 >= maxErreurs){
        printf("Egalite ! Les deux joueurs ont perdu.\n");
    	}else if (erreurs1 >= maxErreurs){
        printf("Joueur 2 gagne ! Joueur 1 a epuise ses essais.\n");
    	}else{
        	printf("Joueur 1 gagne ! Joueur 2 a epuise ses essais.\n");
}
    printf("Mot de J1 etait : %s\n", motJ1);
    printf("Mot de J2 etait : %s\n", motJ2);
    printf("================================\n");
}
    printf("\n=== Jeu du Pendu  Mode 2 joueurs ===\n");

    char motJ1[50], motJ2[50];

    printf("\nJoueur 1, entrez votre mot secret : ");
    scanf("%s", motJ1);
    printf("\033[H\033[J");

    printf("Joueur 2, entrez votre mot secret : ");
    scanf("%s", motJ2);
    printf("\033[H\033[J");

    jouerDuel(motJ1, motJ2);   
}
return 0;
}
