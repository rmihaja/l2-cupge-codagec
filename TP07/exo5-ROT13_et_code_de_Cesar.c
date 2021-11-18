#include <stdlib.h>
#include <stdio.h>

int ROT13(int c) {
    // ASCII letters crypting
     if (97 <= c && c < 123)
     {
         return (c + 13) % 123 + 97;
     }

    //  ASCII capital letters crypting
    else if (65 <= c && c < 91) {
        return (c + 13) % 91 + 65;
    }

    else return c;
}

int main()
{
    char *ligne;
    char c;

    // ? utilisation de ligne
    scanf("%m[^\n]%c", &ligne, &c);
    // ? détruit char* quand la fonction scanf aura terminé
    // free(ligne);

    printf("DEBUG\n");
    printf("ligne: %s\n", ligne);
    printf("c: %c\n", c);

    for (int i = 0; ligne[i] != 0; i++) {
        printf("%c", ROT13(ligne[i * sizeof(char)]));
    }

    printf("%s", ligne);

    return 0;
}