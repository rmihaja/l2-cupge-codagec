#include <stdio.h>

int main()
{
    int int_name = 0;
    printf("Ecrivez: Bonjour, je suis ...\n");
    scanf("Bonjour, je suis %d", &int_name);
    // printf("Je vous ai compris!\n");
    printf("Bonjour, %d", int_name);

    printf("%c", getchar());
    return 0;
}

