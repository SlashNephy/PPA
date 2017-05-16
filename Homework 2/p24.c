#include <stdio.h>
#include <stdlib.h>

int merge(int *array, int p, int q, int r);

int main() {
    int i, n, p, q, r;

    scanf("%d", &n);
    scanf("%d %d %d", &p, &q, &r);

    int *array = (int *)malloc(sizeof(int) * n);
    if (array == NULL) {
        printf("メモリの確保に失敗\n");
        return 1;
    }
    for (i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }

    int j = merge(array, p, q, r);
    if (j == -1) {
        printf("メモリの確保に失敗\n");
        return 1;
    }
    for (i=0; i<n; i++) {
        printf(i < n - 1 ? "%d " : "%d\n", array[i]);
    }
    printf("%d\n", j);

    free(array);
    return 0;
}

int merge(int *array, int p, int q, int r) {
    int a, b, i, j, k, m;
    int l = r - p + 1;
    int n = 0;

    int *T = (int *)malloc(sizeof(int) * l);
    if (T == NULL) {
        return -1;
    }

    for (i=0,a=0,b=0; i<l; i++) {
        j = p + a;
        k = q + 1 + b;
        // どちらの部分配列も空ではない
        if (j<=q && k<=r) {
            // 左の部分配列の値のほうが小さい
            if (array[j] < array[k]) {
                m = array[j];
                a++;
            // 右の部分配列の値のほうが小さい
            } else {
                m = array[k];
                b++;
            }
            n++;
        // 左の部分配列が空
        } else if (j > q) {
            m = array[k];
            b++;
        // 左の部分配列が空
        } else {
            m = array[j];
            a++;
        }
        T[i] = m;
    }

    for (i=0; i<l; i++) {
        array[i+p] = T[i];
    }

    free(T);
    return n;
}
