#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ld(char *x, int m, char *y, int n);
int min3(int a, int b, int c);

int **c;

int main() {
    int i, j, k, l, m, n;
    char X[100], Y[100];

    scanf("%s %s", X, Y);
    m = strlen(X);
    n = strlen(Y);

    c = (int **)malloc(sizeof(int *) * (m + 1));
    for (i=0; i<m+1; i++) {
        c[i] = (int *)malloc(sizeof(int) * (n + 1));
    }

    for (i=0; i<m+2; i++) {
        if (i == 0) {
            printf("    ");
            for (j=0; j<n; j++) {
                printf(j != n-1 ? "%c " : "%c\n", Y[j]);
            }
        } else {
            if (i == 1) {
                printf("  ");
                k = 0;
            } else {
                printf("%c ", X[k-1]);
            }

            for (l=0; l<n+1; l++) {
                c[k][l] = ld(X, k, Y, l);
                printf(l != n ? "%d " : "%d\n", c[k][l]);
            }
            k++;
        }
    }

    free(c);

    return 0;
}

int ld(char *x, int m, char *y, int n) {
    if (m == 0 || n == 0) {
        return m > n ? m : n;
    }
    if (c[m][n] != 0) {
        return c[m][n];
    }

    return min3(
        ld(x, m-1, y, n-1) + (x[m-1] != y[n-1] ? 1 : 0),
        ld(x, m-1, y, n) + 1,
        ld(x, m, y, n-1) + 1
    );
}

int min3(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}
