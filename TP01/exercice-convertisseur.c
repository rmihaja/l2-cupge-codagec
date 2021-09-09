#include <stdio.h>

int main() {

    float somme; 

    printf("Indiquer une somme en euros :\n");
    
    // ? scanf retourne toujours l'entier 1 après son exécution 
    printf("Valeur retournée par scanf : %d\n", scanf("%f", &somme));
    printf("Son équivalent en dollars est %.2f$", somme * 1.19);

    return 0;
}