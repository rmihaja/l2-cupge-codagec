#include <stdio.h>

int main()
{
    char c;
    printf("Entrez un caractère :\n");
    scanf("%c", &c);
    
    if(48 <= c && c < 58) {
        printf("C'est un chiffre");
    }
    
    if(97 <= c && c < 123) {
        printf("C'est une lettre");
    }
    
    if(65 <= c && c < 91) {
        printf("C'est un lettre majuscule");
    }
    return 0;
}
