#include <stdlib.h>
#include <stdio.h>

int ROT13(int c) {
    // ASCII letters crypting
    if (97 <= c && c < 123)
    {
        if (c + 13 < 123) {
            return c + 13;
        }
        return (c + 13) % 123 + 97;
        
    }

    //  ASCII capital letters crypting
    else if (65 <= c && c < 91) {
        if (c + 13 < 91) {
            return c + 13;
        }
        return (c + 13) % 91 + 65;
    }

    else return c;
}

int cesar(int c, int n) {
    // ASCII letters crypting
    if (97 <= c && c < 123)
    {
        if (c + n < 123) {
            return c + n;
        }
        return (c + n) % 123 + 97;
        
    }

    //  ASCII capital letters crypting
    else if (65 <= c && c < 91) {
        if (c + n < 91) {
            return c + n;
        }
        return (c + n) % 91 + 65;
    }

    else return c;
}

int main(int argc, char *argv[])
{
    char *ligne;
    char c;
    int n;

    // le paramètre n est donné en premier argument du programme
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    else {
        // valeur par défaut
        n = 13;
    }

    scanf("%m[^\n]%c", &ligne, &c);

    printf("\nROT13:\n");
    for (int i = 0; ligne[i] != 0; i++)
    {
        printf("%c", ROT13(ligne[i]));
    }

    printf("\n\nCode de César:\n");
    for (int i = 0; ligne[i] != 0; i++)
    {
        printf("%c", cesar(ligne[i], n));
    }

    // ? détruit char* quand la fonction scanf aura terminé
    free(ligne);

    return 0;
}