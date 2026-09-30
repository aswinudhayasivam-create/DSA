#include<iostream>
using namespace std;

struct Triplet {
    int row, col, value;
};

int toSparse(int mat[][20], int rows, int cols, Triplet sparse[]) {
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] != 0) {
                sparse[k++] = { i, j, mat[i][j] };
            }
        }
    }
    return k; 
}

void printSparse(Triplet sparse[], int k) {
    cout << "Row\tCol\tValue\n";
    for(int i = 0; i < k; i++)
        cout << sparse[i].row << "\t" << sparse[i].col << "\t" << sparse[i].value << endl;
}

int addSparse(Triplet a[], int na, Triplet b[], int nb, Triplet result[]) {
    int i = 0, j = 0, k = 0;
    while(i < na && j < nb) {
        if(a[i].row == b[j].row && a[i].col == b[j].col) {
            int sum = a[i].value + b[j].value;
            if(sum != 0) result[k++] = { a[i].row, a[i].col, sum };
            i++; j++;
        }
        else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        }
        else {
            result[k++] = b[j++];
        }
    }
    while(i < na) result[k++] = a[i++];
    while(j < nb) result[k++] = b[j++];
    return k;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and coloums : ";
    cin >> rows >> cols;

    int matA[20][20], matB[20][20];

    cout << "Enter elements of matrix A : ";
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> matA[i][j];

    cout << "Enter elements of matrix B : ";
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> matB[i][j];

    Triplet sparseA[400], sparseB[400], sparseC[400];
    int na = toSparse(matA, rows, cols, sparseA);
    int nb = toSparse(matB, rows, cols, sparseB);

    cout << "\nSparse matrix A : \n";
    printSparse(sparseA, na);
    cout << "\nSparse matrix B : \n";
    printSparse(sparseB, nb);

    int nc = addSparse(sparseA, na, sparseB, nb, sparseC);
    cout << "\nSparse matrix C (A + B) : \n";
    printSparse(sparseC, nc);
    
    return 0;
}