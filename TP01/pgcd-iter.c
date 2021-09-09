#include <stdio.h>

int main() {
    int pgcd(int a, int b) {
        while (a != b) {
            if(a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
        return a;
    }

    // ? code avec cviewer
    // int c = pgcd(12, 51);

    // ? code avec crunner
    printf("%d", pgcd(12, 51));

    return 0;
}