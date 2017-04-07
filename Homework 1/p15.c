#include <stdio.h>

int count(char arr[], int n) {
    int i;

    for (i=0; arr[i] != '\0' && i<n; i++) {}
    return i;
}

int main() {
    int i, j;
    char numbers[100], t[2];
    int x = 0;

    scanf("%s", numbers);

    for (i=count(numbers, 100)-1; i>=0; i--) {
        if ((i + 1) % 2 == 0) {
            sprintf(t, "%d", 2 * (numbers[i] - '0'));
            for (j=0; j < count(t, 2); j++) {
                x += t[j] - '0';
            }
        } else {
            x += numbers[i] - '0';
        }
    }

    printf(x % 10 == 0 ? "true\n" : "false\n");

    return 0;
}
