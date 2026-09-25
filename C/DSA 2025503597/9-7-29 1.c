#include <stdio.h>

typedef struct {
    int coef, expo;
} TERM;

typedef struct {
    TERM t[100];
    int nT;
} POLY;

POLY createPoly() {
    POLY p;
    p.nT = 0;
    return p;
}

void printPoly(POLY p) {
    if (p.nT == 0) {
        printf("0");
        return;
    }
    for (int i = 0; i < p.nT; i++) {
        if (i > 0 && p.t[i].coef >= 0) {
            printf("+");
        }
        printf("%dx^%d", p.t[i].coef, p.t[i].expo);
    }
}

POLY attachTerm(POLY p, TERM t) {
    int i = p.nT - 1;
    while (i >= 0) {
        if (p.t[i].expo == t.expo) {
            p.t[i].coef += t.coef;
            return p;
        }
        i = i - 1;
    }

    i = p.nT - 1;
    while ((i >= 0) && (p.t[i].expo < t.expo)) {
        p.t[i+1] = p.t[i];
        i = i - 1;
    }

    p.t[i+1] = t;
    p.nT = p.nT + 1;
    return p;
}

int main() {
    TERM t1 = {2, 12}, t2 = {7, 12}, t3 = {3, 7};
    POLY p;

    p = createPoly();
    p = attachTerm(p, t1);
    p = attachTerm(p, t2);
    p = attachTerm(p, t3);

    printf("\nP1 = ");
    printPoly(p);
    printf("\n");

    return 0;
}
