#include <stdio.h>

int tmax(int n);
int tmin(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d %d\n", tmax(n), tmin(n));

    return 0;
}

int tmax(int n) {
    if (n == 2) {
        return 1;
    }
    return tmax(n / 2) * 2 + n - 1;
}

int tmin(int n) {
    if (n == 2) {
        return 1;
    } 
    return tmin(n / 2) * 2 + n / 2;
}
