#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; (i < argc && i < 3); i++)
    {
        printf("%s ", argv[i]);
    }
    return 0;
}
