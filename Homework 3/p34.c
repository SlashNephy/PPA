#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min3(int a, int b, int c);

int main() {
    // ループ変数
    int i, j;
    // 文字列X, Y
    char X[100], Y[100];
    // 文字列X, Yの長さm, n
    int m, n;

    scanf("%s %s", X, Y);
    m = strlen(X);
    n = strlen(Y);

    printf("    ");
    for (i=0; i<n; i++) {
        printf(i != n-1 ? "%c " : "%c\n", Y[i]);
    }

    int **c = (int **)malloc(sizeof(int *) * (m + 1));
    for (i=0; i<m+1; i++) {
        c[i] = (int *)malloc(sizeof(int) * (n + 1));

        printf("%c ", i == 0 ? ' ' : X[i-1]);
        for (j=0; j<n+1; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = i > j ? i : j;
            } else {
                c[i][j] = min3(
                    c[i-1][j-1] + (X[i-1] != Y[j-1] ? 1 : 0),
                    c[i-1][j] + 1,
                    c[i][j-1] + 1
                );
            }

            printf(j != n ? "%d " : "%d\n", c[i][j]);
        }
    }

    free(c);

    return 0;
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
