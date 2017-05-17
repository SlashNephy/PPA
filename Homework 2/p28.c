#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void selectionsort(double *x, int *y, int n);
int knn_diag(double *d, int n);

// グローバル変数
// 過去の診断データの個数
int n;
// 特徴空間の次元数
int d;
// 患者の心臓病の診断結果の配列 要素数n
int *x;
// 患者の特徴を示す診断データ 要素数n x d
double **y;

int main() {
    int i, j;
    // k近傍法
    const int k = 3;

    scanf("%d", &n);
    scanf("%d", &d);

    x = (int *)malloc(sizeof(int) * n);
    y = (double **)malloc(sizeof(double *) * n);
    for (i=0; i<n; i++) {
        y[i] = (double *)malloc(sizeof(double) * d);
    }
    for (i=0; i<n; i++) {
        for (j=0; j<d; j++) {
            scanf("%lf", &y[i][j]);
        }
        scanf("%d", &x[i]);
    }

    // 自動診断の対象となる患者データ
    double *t = (double *)malloc(sizeof(double) * d);
    for (i=0; i<d; i++) {
        scanf("%lf", &t[i]);
    }

    printf(knn_diag(t, k) == 1 ? "You have a heart disease!\n" : "You are healthy!\n");

    free(x);
    free(y);
    free(t);
    return 0;
}

// x基準で昇順の選択ソートし yの配列も並び替える
void selectionsort(double *x, int *y, int n) {
    int i, j, k;
    double t;

    for (i=0; i<n-1; i++) {
        k = i;
        for (j=i+1; j<n; j++) {
            if (x[j] < x[k]) {
                k = j;
            }
        }

        if (x[k] < x[i]) {
            t = x[i];
            x[i] = x[k];
            x[k] = t;
            t = y[i];
            y[i] = y[k];
            y[k] = (int)t;
        }
    }
}

int knn_diag(double *t, int k) {
    int i, j;
    double s;
    int r = 0;

    // ユークリッド距離を保管する配列
    double *D = (double *)malloc(sizeof(double) * n);
    for (i=0; i<n; i++) {
        s = 0;
        for (j=0; j<d; j++) {
            s += pow(t[j] - y[i][j], 2);
        }
        D[i] = sqrt(s);
    }

    // ユークリッド距離の配列と診断結果の配列をソートする
    selectionsort(D, x, n);
    for (i=0; i<k; i++) {
        printf("%lf %d\n", D[i], x[i]);
        if (x[i] == 1) {
            r++;
        }
    }

    free(D);
    return r > k / 2 ? 1 : 0;
}
