#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ld(char *x, int m, char *y, int n);
int min3(int a, int b, int c);

// ldの一次キャッシュc
int c[26][26];

int main() {
    // ループ変数
    int i, j, k;
    // 各ワードのldの最小値M
    int M;
    // 最小値Mの出現回数A
    int A;
    // 文字列X, Yの文字数m, n
    int m, n;
    // 辞書サイズv
    int v;

    scanf("%d", &v);

    // v * 25の辞書を作成
    char **V = (char **)malloc(sizeof(char *) * v);
    for (i=0; i<v; i++) {
        V[i] = (char *)malloc(sizeof(char) * 25);
        scanf("%s", V[i]);
    }

    while (1) {
        // スペルチェック対象の文字列x
        char x[25];
        if (scanf("%s", x) == EOF) {
            break;
        }

        // 辞書を総当たりしてM, A, tを求める
        M = -1;
        A = 0;
        int *t = (int *)malloc(sizeof(int) * v);
        for (i=0; i<v; i++) {
            // 毎回キャッシュcを初期化
            for (j=0; j<26; j++) {
                for (k=0; k<26; k++) {
                    c[j][k] = -1;
                }
            }

            m = strlen(x);
            n = strlen(V[i]);

            t[i] = ld(x, m, V[i], n);
            // 初回または新たな最小値が見つかったときは 最小値を更新してカウンタをリセット
            if (M == -1 || t[i] < M) {
                M = t[i];
                A = 1;
            // 同じ最小値が見つかったときは カウンタを進める
            } else if (t[i] == M) {
                A++;
            }
        }

        // 見つかった最小値を与えるV[i]を表示
        for (i=0,j=1; i<v; i++) {
            // i番目のldが最小値のとき
            if (t[i] == M) {
                // 最後の出力なら改行を それ以外では半角スペースを出力
                printf(j != A ? "%s " : "%s\n", V[i]);
                j++;
            }
        }

        free(t);
    }

    free(V);
    return 0;
}

int ld(char *x, int m, char *y, int n) {
    if (c[m][n] == -1) {
        if (m == 0 || n == 0) {
            c[m][n] = m > n ? m : n;
        } else {
            c[m][n] = min3(
                ld(x, m-1, y, n-1) + (x[m-1] != y[n-1] ? 1 : 0),
                ld(x, m-1, y, n) + 1,
                ld(x, m, y, n-1) + 1
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
