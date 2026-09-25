#include <stdio.h>

int main()
{
    int p1[100] = {4, 3, 3, 4, 2, 5, 1, 6, 0},
        p2[100] = {4, 3, 5, 4, 2, 5, 1, 6, 0},
        p3[100], i = 1, j = 1, k = 1, n = p1[0], m = p2[0];

    while (i <= n && j <= m)
    {
        if (p1[2 * i] == p2[2 * j]) {
            int t = p1[2 * i - 1] + p2[2 * j - 1];
            if (t) {
                p3[2 * k] = p1[2 * i];
                p3[2 * k - 1] = t;
                k = k + 1;
            }
            i = i + 1;
            j = j + 1;
        }
        else if (p1[2 * i] > p2[2 * j]) {
            p3[2 * k] = p1[2 * i];
            p3[2 * k - 1] = p1[2 * i - 1];
            i = i + 1;
            k = k + 1;
        }
        else {
            p3[2 * k] = p2[2 * j];
            p3[2 * k - 1] = p2[2 * j - 1];
            j = j + 1;
            k = k + 1;
        }
    }

    while (i <= n) {
        p3[2 * k] = p1[2 * i];
        p3[2 * k - 1] = p1[2 * i - 1];
        i = i + 1;
        k = k + 1;
    }

    while (j <= m) {
        p3[2 * k] = p2[2 * j];
        p3[2 * k - 1] = p2[2 * j - 1];
        j = j + 1;
        k = k + 1;
    }

    p3[0] = k - 1;

    for (i = 0; i <= 2 * p3[0]; i++) {
        printf("%5d", p3[i]);
    }
    printf("\n");

    return 0;
}
