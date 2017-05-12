#include <stdio.h>

double resistance(int N, int r_x, int r_y, int r_z);

int main() {
    int N, r_x, r_y, r_z;
    scanf("%d", &N);
    scanf("%d", &r_x);
    scanf("%d", &r_y);
    scanf("%d", &r_z);

    printf("%.3lf\n", resistance(N, r_x, r_y, r_z));

    return 0;
}

double resistance(int N, int r_x, int r_y, int r_z) {
    if (N == 1) {
        return r_x + r_y + r_z;
    }
    double R = resistance(N - 1, r_x, r_y, r_z);
    return r_x + r_y * R / (r_y + R) + r_z;
}
