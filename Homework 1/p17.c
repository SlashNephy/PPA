#include <stdio.h>

int board[3][3] = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
int o = 100;
int x = 10000;
const char marks[2] = "ox";

void show() {
    int i, j, k;

    for (i=0; i<3; i++) {
        if (i != 0) {
            printf("-+-+-\n");
        }

        for (j=0; j<3; j++) {
            if (j != 0) {
                printf("|");
            }

            k = board[i][j];
            if (k == o || k == x) {
                printf("%c", k == o ? marks[0] : marks[1]);
            } else {
                printf("%d", board[i][j]);
            }
        }
        printf("\n");
    }
}

int exist(int target) {
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == target) {
                return 1;
            }
        }
    }

    return 0;
}

void update(int target, char mark) {
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == target) {
                board[i][j] = (mark == marks[0]) ? o : x;
                return;
            }
        }
    }
}

int check() {
    int i, j, k, l, m, n;

    m = 0;
    n = 0;
    for (i=0; i<3; i++) {
        k = 0;
        l = 0;
        for (j=0; j<3; j++) {
            k += board[i][j];
            l += board[j][i];

            if (i == j) {
                m += board[i][i];
            }
            if (i + j == 2) {
                n += board[i][j];
            }
        }

        if (k == 3 * o || l == 3 * o || k == 3 * x || l == 3 * x) {
            return 1;
        }
    }

    if (m == 3 * o || n == 3 * o || m == 3 * x || n == 3 * x) {
        return 1;
    }

    return 0;
}

int even() {
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] > 0 && board[i][j] < 10) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int i, j;

    while (1) {
        for (i=0; i<2; i++) {
            show();

            while (1) {
                printf("%c> ", marks[i]);
                scanf("%d", &j);
                printf("\n");

                if (j < 0 || j > 10 || ! exist(j)) {
                    printf("ERROR\n");
                    continue;
                }
                
                update(j, marks[i]);

                if (check()) {
                    show();
                    printf("%c win!\n", marks[i]);

                    return 0;
                } else if (even()) {
                    show();
                    printf("even.\n");

                    return 0;
                }

                break;
            }
        }
    }
}
