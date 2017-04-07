#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(char arr[], int n) {
    int i;

    for (i=0; arr[i] != '\0' && i<n; i++) {}
    return i;
}

void zerofill(char arr[], char arr2[]) {
    switch (count(arr, 3)) {
        case 1:
            arr2[0] = '0';
            arr2[1] = '0';
            arr2[2] = arr[0];
            break;
        case 2:
            arr2[0] = '0';
            arr2[1] = arr[0];
            arr2[2] = arr[1];
            break;
        case 3:
            arr2[0] = arr[0];
            arr2[1] = arr[1];
            arr2[2] = arr[2];
            break;
    }
}

void copy(char arr[], char arr2[], int n) {
    int i;

    for (i=0; i<n; i++) {
        arr2[i] = arr[i];
    }
}

void sort_asc(char arr[], char arr2[], int n) {
    int i, j;
    char t;

    copy(arr, arr2, n);

    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (arr2[j - 1] < arr2[j]) {
                t = arr2[j];
                arr2[j] = arr2[j - 1];
                arr2[j - 1]= t;
            }
        }
    }
}

void sort_desc(char arr[], char arr2[], int n) {
    int i, j;
    char t;

    copy(arr, arr2, n);

    for (i=0; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (arr2[j - 1] > arr2[j]) {
                t = arr2[j];
                arr2[j] = arr2[j - 1];
                arr2[j - 1]= t;
            }
        }
    }
}

int main() {
    int i;
    char x[3], n[3], bigger[3], smaller[3];

    scanf("%s", &x);
    zerofill(x, n);

    while (1) {
        sort_asc(n, bigger, 3);
        sort_desc(n, smaller, 3);

        sprintf(x, "%d", atoi(bigger) - atoi(smaller));
        zerofill(x, n);

        printf("%3d - %3d = %3d\n", atoi(bigger), atoi(smaller), atoi(x));

        if (strcmp(n, "495") == 0) {
            break;
        }
    }

    return 0;
}
