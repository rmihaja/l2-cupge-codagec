#include <stdio.h>

int main()
{
    int u(int n)
    {
        if (n == 0)
            return 1;
        else // ? n > 0
            return 3 * u(n - 1) - 1;
    }

    printf("(a) Calcul et affichage de u10 : %d\n", u(10));

    int v(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else // ? n > 1
            return v(n - 1) + v(n - 2);
    }

    printf("(b) Calcul et affichage de u10 : %d", v(10));

    return 0;
}
