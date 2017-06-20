#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ld1(char *x, int m, char *y, int n);
int ld2(char *x, int m, char *y, int n);
int min3(int a, int b, int c);

// c(i,j)のキャッシュ
int **c;
// メモ化を実装していないld関数の呼び出し回数
int c1;
// メモ化を実装しているld関数の呼び出し回数
int c2;

int main() {
    int i, j, m, n;

    while (1) {
        char X[100], Y[100];
        if (scanf("%s %s", X, Y) == EOF) {
            return 0;
        }

        c1 = 0;
        c2 = 0;
        m = strlen(X);
        n = strlen(Y);

        c = (int **)malloc(sizeof(int *) * (m + 1));
        for (i=0; i<m+1; i++) {
            c[i] = (int *)malloc(sizeof(int) * (n + 1));
            for (j=0; j<n+1; j++) {
                c[i][j] = -1;
            }
        }

        ld1(X, m, Y, n);
        printf("%d\n", ld2(X, m, Y, n));
        fprintf(stderr, "%d,%d,%d,%d,%d\n", m, n, m * n, c1, c2);

        free(c);
    }
}

// メモ化を実装していないld関数
int ld1(char *x, int m, char *y, int n) {
    c1++;

    if (m == 0 || n == 0) {
        return m > n ? m : n;
    }
    return min3(
        ld1(x, m-1, y, n-1) + (x[m-1] != y[n-1] ? 1 : 0),
        ld1(x, m-1, y, n) + 1,
        ld1(x, m, y, n-1) + 1
    );
}

// メモ化を実装しているld関数
int ld2(char *x, int m, char *y, int n) {
    c2++;

    if (c[m][n] == -1) {
        if (m == 0 || n == 0) {
            c[m][n] = m > n ? m : n;
        } else {
            c[m][n] = min3(
                ld2(x, m-1, y, n-1) + (x[m-1] != y[n-1] ? 1 : 0),
                ld2(x, m-1, y, n) + 1,
                ld2(x, m, y, n-1) + 1
            );
        }
    }
    return c[m][n];
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
