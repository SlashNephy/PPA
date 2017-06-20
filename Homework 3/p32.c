#include <stdio.h>
#include <string.h>

int ld(char *x, int m, char *y, int n);
int min3(int a, int b, int c);

int main() {
   char X[100], Y[100];

   scanf("%s %s", X, Y);

   printf("%d\n", ld(X, strlen(X), Y, strlen(Y)));

   return 0;
}

int ld(char *x, int m, char *y, int n) {
    if (m == 0 || n == 0) {
        return m > n ? m : n;
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
