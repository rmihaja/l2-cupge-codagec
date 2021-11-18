#include <stdio.h>
#include <ctype.h>

int lire_fin_ligne() {
    char *ligne;
    char c;
    scanf("%m[^\n]%c", &ligne, &c);

    int ligne_length = 0;
    for (int i = 0; ligne[i] != c; ligne_length++)
    {
        if (isspace(ligne[i]) == 0) {
            ligne_length += 1;
        }
    }
    return ligne_length;
}

#ifdef TESTS

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

#endif