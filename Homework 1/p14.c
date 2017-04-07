#include <stdio.h>

float SMA(float data[], int t, int N) {
    int i;
    float j = 0;

    for (i=0; i<N; i++) {
        j += data[t - i];
    }
    return j / N;
}

int main() {
    int i;
    float data[1245];

    for (i=0; i<1245; i++) {
        scanf("%f", data[i]);
    }

    for (i=20; i<1245; i++) {
        printf("%d %f %f %f\n", i, data[i], SMA(data, i, 5), SMA(data, i, 20));
    }

    return 0;
}
