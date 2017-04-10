#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if ((a + b) % 2 != 0 || (b - a) % 2 != 0) {
        printf("ERROR\n");
    } else {
        printf("%d %d\n", (a + b) / 2, (b - a) / 2);
    }

    return 0;
}
