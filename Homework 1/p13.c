#include <stdio.h>

float max(float arr[], int n) {
    int i;
    float t = arr[0];

    for (i=0; i<n; i++) {
        t = t > arr[i] ? t : arr[i];
    }
    return t;
}

float min(float arr[], int n) {
    int i;
    float t = arr[0];
    
    for (i=0; i<n; i++) {
        t = t < arr[i] ? t : arr[i];
    }
    return t;
}

void pop(float value, float arr[], int n, float arr2[]) {
    int i;
    int j = 0;
    int already_poped = 0;

    for (i=0; i<n; i++) {
        if (arr[i] == value && already_poped != 1) {
            already_poped = 1;
            continue;
        }
        arr2[j++] = arr[i];
    }
}

float mean(float arr[], int n) {
    int i;
    float t = 0;

    for (i=0; i<n; i++) {
        t += arr[i];
    }
    return t / n;
}

int main() {
    int i;
    float t[7], t2[6], t3[5];

    for (i=0; i<7; i++) {
        scanf("%f", &t[i]);
    }

    pop(max(t, 7), t, 7, t2);
    pop(min(t, 7), t2, 6, t3);

    printf("%.2f\n", mean(t3, 5));

    return 0;
}
