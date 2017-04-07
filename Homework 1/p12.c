#include <stdio.h>

int main() {
    int i, x;
    scanf("%d", &x);

    for (i=1; i<=100; i++) {
        if (i > 1) {
            if (x % 2 == 0) {
                x /= 2;
            } else {
                x = 3 * x + 1;
            }
        }

        printf("%d\n", x);

        if (x == 1) {
            printf("OK\n");
            return 0;
        }
    }

    return 0;
}
