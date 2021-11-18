#include <stdio.h>

int main()
{
    // ASCII starts at 48 for numbers 
    printf("\nAffichage des chiffres:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%c | %d\n", 48 + i, 48 + i);
    }

    // ASCII starts at 97 for letters
    printf("\nAfichage des lettres:\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c | %d\n", 97 + i, 97 + i);
    }
            
    printf("\nDifférence des lettres:\n");
    printf("'z' - 'a' : %d\n", 'z' - 'a');
    printf("'Z' - 'A' : %d\n", 'Z' - 'A');
    
    // ASCII starts at 65 for capital letters
    printf("\nAfichage des lettres majuscules:\n");
    for (int i = 0; i < 26; i++)
    {    
        printf("%c | %d\n", 65 + i, 65 + i);
    }

    return 0;
}
