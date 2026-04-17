#include <iostream>
#include <cmath>

using namespace std;

// Function to create matrix A and vector b
int create(int n, double **&a, double *&b) {
    a = new double*[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[n];

    b = new double[n];

    cout << "Enter matrix A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    return 0;
}

// Gauss method with row pivoting
double gauss(int n, double **a, double *b, double *x) {
    double det = 1.0;
    int swap_count = 0;

    for (int k = 0; k < n; k++) {
        // Find pivot row
        int maxRow = k;
        for (int i = k + 1; i < n; i++)
            if (fabs(a[i][k]) > fabs(a[maxRow][k]))
                maxRow = i;

        if (fabs(a[maxRow][k]) < 1e-12) {
            cout << "Matrix is singular.\n";
            return 0;
        }

        // Swap rows
        if (maxRow != k) {
            swap(a[k], a[maxRow]);
            swap(b[k], b[maxRow]);
            swap_count++;
        }

        det *= a[k][k];

        // Elimination
        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j < n; j++)
                a[i][j] -= factor * a[k][j];
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    if (swap_count % 2 != 0)
        det = -det;

    return det;
}

int main() {
    int n;
    cout << "Enter system size n: ";
    cin >> n;

    double **A;
    double *b;
    double *x = new double[n];

    create(n, A, b);

    double determinant = gauss(n, A, b, x);

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "] = " << x[i] << endl;

    cout << "\nDeterminant = " << determinant << endl;

    // Free memory
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
    delete[] b;
    delete[] x;

    return 0;
}