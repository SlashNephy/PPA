#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ld(char *x, int m, char *y, int n);
int min3(int a, int b, int c);
void reverse(char *x);

// c(i,j)のキャッシュ
int **c;
// c(i,j)で選択された操作
char **o;

int main() {
    // ループ変数
    int i, j, k;
    // 文字列X, Y
    char X[100], Y[100];
    // 文字列X, Yの文字数m, n
    int m, n;
    // 実際に適用された操作t
    char *O;
    // 操作数l
    int l;

    scanf("%s %s", X, Y);

    m = strlen(X);
    n = strlen(Y);

    // 配列を確保 / 初期化
    c = (int **)malloc(sizeof(int *) * (m + 1));
    o = (char **)malloc(sizeof(char *) * (m + 1));
    O = (char *)malloc(sizeof(char) * (m * n + m + n + 1));
    for (i=0; i<m+1; i++) {
        c[i] = (int *)malloc(sizeof(int) * (n + 1));
        o[i] = (char *)malloc(sizeof(char) * (n + 1));
        for (j=0; j<n+1; j++) {
            c[i][j] = -1;
        }
    }

    ld(X, m, Y, n);

    // 逆順に辿っていく
    for (i=m,j=n,k=0; i>=0 && j>=0; k++) {
        if (i == 0 && j == 0) {
            break;
        }
        O[k] = o[i][j];
        if (O[k] == 'R' || O[k] == '=') {
            i--;
            j--;
        } else if (O[k] == 'D') {
            i--;
        } else if (O[k] == 'I') {
            j--;
        }
    }
    // Oを正順に並び替える
    reverse(O);
    l = strlen(O);

    // j=0: X, j=1: Y, j=2: Oの出力
    for (j=0; j<3; j++) {
        for (i=0,k=0;; i++) {
            // Oの出力
            if (j == 2) {
                printf("%c", O[i]);
                if (i == l - 1) {
                    break;
                }
                continue;
            }
            // 文字数を超えたらbreak
            if ((j == 0 && k == m) || (j == 1 && k == n)) {
                break;
            }

            switch (O[i]) {
                case '=':
                case 'R':
                    printf("%c", j == 0 ? X[k] : Y[k]);
                    k++;
                    break;
                case 'D':
                    if (j == 0) {
                        printf("%c", X[k]);
                        k++;
                    } else {
                        printf(" ");
                    }
                    break;
                case 'I':
                    if (j == 0) {
                        printf(" ");
                    } else {
                        printf("%c", Y[k]);
                        k++;
                    }
                    break;
            }
        }
        printf("\n");
    }

    free(c);
    free(o);
    free(O);
    
    return 0;
}

int ld(char *x, int m, char *y, int n) {
    int cr, d, i;

    if (c[m][n] == -1) {
        if (m == 0 || n == 0) {
            c[m][n] = m > n ? m : n;

            if (c[m][n] == m) {
                o[m][n] = 'D';
            } else if (c[m][n] == n) {
                o[m][n] = 'I';
            }
        } else {
            cr = ld(x, m-1, y, n-1) + (x[m-1] != y[n-1] ? 1 : 0);
            d = ld(x, m-1, y, n) + 1;
            i = ld(x, m, y, n-1) + 1;
            c[m][n] = min3(cr, d, i);

            if (c[m][n] == cr) {
                o[m][n] = x[m-1] != y[n-1] ? 'R' : '=';
            } else if (c[m][n] == d) {
                o[m][n] = 'D';
            } else if (c[m][n] == i) {
                o[m][n] = 'I';
            }
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

void reverse(char *x) {
    int i;
    int n = strlen(x);
    char *t = (char *)malloc(sizeof(char) * n);

    for (i=0; i<n; i++) {
        t[i] = x[n-i-1];
    }
    for (i=0; i<n; i++) {
        x[i] = t[i];
    }

    free(t);
}
