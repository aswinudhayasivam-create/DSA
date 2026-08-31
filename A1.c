#include <stdio.h>
#define MAX 50

struct Term {
    int coeff;
    int exp;
};

// Read a polynomial from the user (terms entered in descending order of exponent)
void inputPoly(struct Term poly[], int *n) {
    printf("Enter number of terms: ");
    scanf("%d", n);
    printf("Enter terms in DESCENDING order of exponent (coeff exp):\n");
    for (int i = 0; i < *n; i++) {
        printf("Term %d - coefficient: ", i + 1);
        scanf("%d", &poly[i].coeff);
        printf("Term %d - exponent: ", i + 1);
        scanf("%d", &poly[i].exp);
    }
}

void displayPoly(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i != n - 1) printf(" + ");
    }
    printf("\n");
}

// Add two polynomials (merge-style, like merging two sorted lists)
int addPoly(struct Term a[], int m, struct Term b[], int n, struct Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i].exp == b[j].exp) {
            int sum = a[i].coeff + b[j].coeff;
            if (sum != 0) {
                result[k].coeff = sum;
                result[k].exp = a[i].exp;
                k++;
            }
            i++; j++;
        }
        else if (a[i].exp > b[j].exp) {
            result[k++] = a[i++];
        }
        else {
            result[k++] = b[j++];
        }
    }
    while (i < m) result[k++] = a[i++];
    while (j < n) result[k++] = b[j++];

    return k; // number of terms in result
}

int main() {
    struct Term poly1[MAX], poly2[MAX], result[MAX];
    int m, n, k;

    printf("--- Polynomial 1 ---\n");
    inputPoly(poly1, &m);

    printf("\n--- Polynomial 2 ---\n");
    inputPoly(poly2, &n);

    k = addPoly(poly1, m, poly2, n, result);

    printf("\nPolynomial 1: ");
    displayPoly(poly1, m);

    printf("Polynomial 2: ");
    displayPoly(poly2, n);

    printf("Sum        : ");
    displayPoly(result, k);

    return 0;
}