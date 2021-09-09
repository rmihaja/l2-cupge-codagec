#include <stdio.h>

int main() {
int pgcd(int a, int b) {
    if(a == b) {
        return a;
    } else if(a > b) {
        return pgcd(a - b, b);
    } else {
        // ? cas a < b
        return pgcd (a, b - a);
    }
}

    // ? code avec cviewer
    // int c = pgcd(12, 51);

    // ? code avec crunner
    printf("%d", pgcd(12, 51));

    return 0;
}

