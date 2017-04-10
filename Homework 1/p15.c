#include <stdio.h>

int count(char arr[], int n) {
    int i;

    for (i=0; arr[i] != '\0' && i<n; i++) {}
    return i;
}

int even(int i, int n) {
    return (i + ((n % 2) == 0 ? 0 : 1)) % 2 == 0 ? 1 : 0;
}

int main() {
    int i, j, n;
    char numbers[100], t[3];
    int x = 0;

    scanf("%s", numbers);
    n = count(numbers, 100);

    for (i=0; i<n; i++) {
        if (even(i, n)) {
            sprintf(t, "%d", 2 * (numbers[i] - '0'));
            for (j=0; j<count(t, 3); j++) {
                x += t[j] - '0';
            }
        } else {
            x += numbers[i] - '0';
        }
    }

    printf(x % 10 == 0 ? "true\n" : "false\n");

    return 0;
}
