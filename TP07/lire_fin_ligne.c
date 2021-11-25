#include <stdio.h>
#include <ctype.h>

// ! ce n'est pas ce qu'on demande
// int lire_fin_ligne() {
//     char *ligne;
//     char c;
//     scanf("%m[^\n]%c", &ligne, &c);

//     int ligne_length = 0;
//     for (int i = 0; ligne[i] != 0; i++)
//     {
//         if (isspace(ligne[i]) == 0) {
//             ligne_length++;
//         }
//     }

//     return ligne_length;
// }

int lire_fin_ligne() {
    int ligne_length = 0;
    int c;
    do {
        c = getchar();
        if (isspace(c) == 0) {
            ligne_length++;
        }
    } while (c != EOF && c != '\n');
    return ligne_length;
}

#ifdef TESTS

int main()
{
    printf("[TEST] Nombre de ligne: %d\n", lire_fin_ligne());
    return 0;
}

#endif