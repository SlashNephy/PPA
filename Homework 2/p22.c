#include <stdio.h>
#include <stdlib.h>

int selectionsort(int *x, int n);

int main() {
    int i, n;

    scanf("%d", &n);

    int *x = (int *)malloc(sizeof(int) * n);
    if (x == NULL) {
        printf("メモリの確保に失敗\n");
        return 1;
    }
    for (i=0; i<n; i++) {
        scanf("%d", &x[i]);
    }

    int j = selectionsort(x, n);
    for (i=0; i<n; i++) {
        printf(i < n - 1 ? "%d " : "%d\n", x[i]);
    }
    printf("%d\n", j);

    free(x);
    return 0;
}

int selectionsort(int *x, int n) {
    int i, j, k, l;
    int m = 0;

    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            if (x[i] > x[j]) {
                l = x[i];
                x[i] = x[j];
                x[j] = l;

                printf("SWAP(%d,%d)\n# ", i, j);
                for (k=0; k<n; k++) {
                    printf(k < n - 1 ? "%d " : "%d\n", x[k]);
                }
            }
            m++;
        }
    }
    return m;
}
