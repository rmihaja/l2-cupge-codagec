#include <stdio.h>

/* Ecrire une fonction qui prend en argument un caractère, 
 * et qui rend 1 si ce caractère est une lettre minuscule,
 * et 0 sinon */

int isMinuscule(int c) {
    // 'a' vaut 97 et 'z' vaut 122 
    if (c >= 97 && c <= 122) {
        return 1;
    }
    return 0;
}

int main() {

    /* Ecrire un programme qui affiche les caractères de 0 à 9 en tant que caractères et en tant qu'entier */
    
    for(int i = 0; i < 10; i++) {
        printf("\nBoucle #%d\n", i);
        printf("En tant que caractère : %c\n", i);
        printf("En tant qu'entier : %d\n", i);
    }

    /* Afficher tous les caractères, ainsi que leur code */
    
    printf("Tous les caractères avec leur code");
    for (int i = 0; i < 128; i++) {
        printf("%c (%d)\n", i, i);
    }
    
    // ? test de la fonction isMinuscule
    char c = 'S';
    printf("%c est il minuscule ? %d", c, isMinuscule(c));

    return 0;
}