#include <stdio.h>
#include <stdlib.h>

int count(double *x, int n, int r);

int main() {
    int i, j, n;

    scanf("%d", &n);

    double *x = (double *)malloc(sizeof(double) * n);
    if (x == NULL) {
        printf("メモリの確保に失敗\n");
        return 1;
    }
    for (i=0; i<n; i++) {
        scanf("%lf", &x[i]);
    }

    for (i=0; i<=20; i++) {
        printf("%2d ", i);
        for (j=0; j<count(x, n, i); j++) {
            printf("*");
        }
        printf("\n");
    }

    free(x);
    return 0;
}

int count(double *x, int n, int r) {
    int i;
    int j = 0;

    for (i=0; i<n; i++) {
        if ((int)(x[i] + 0.5) == r) {
            j++;
        }
    }
    return j;
}
