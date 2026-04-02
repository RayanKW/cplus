#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

// Function to create and fill matrices in dynamic memory
int create(int n, double **&a, double *&b) {
    try {
        // Allocate memory for matrix A (2D array)
        a = new double*[n];
        for (int i = 0; i < n; i++) {
            a[i] = new double[n];
        }

        // Allocate memory for vector b
        b = new double[n];

        // Fill matrix A and vector b with sample data
        // Using a well-conditioned system for testing
        // You can modify this to accept user input or generate different systems

        cout << "Enter elements of matrix A (" << n << "x" << n << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "A[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
        }

        cout << "Enter elements of vector b (" << n << " elements):\n";
        for (int i = 0; i < n; i++) {
            cout << "b[" << i << "] = ";
            cin >> b[i];
        }

        return 0; // Success
    }
    catch (bad_alloc&) {
        cout << "Memory allocation failed!\n";
        return -1; // Failure
    }
}

// Function to perform Gaussian elimination with row pivoting
// Returns the determinant of matrix A
double gauss(int n, double **a, double *b, double *x) {
    // Create augmented matrix (we'll work with copies to preserve original)
    double **aug = new double*[n];
    for (int i = 0; i < n; i++) {
        aug[i] = new double[n + 1];
        for (int j = 0; j < n; j++) {
            aug[i][j] = a[i][j];
        }
        aug[i][n] = b[i];
    }

    double det = 1.0;
    int swapCount = 0;

    // Forward elimination with partial pivoting
    for (int k = 0; k < n - 1; k++) {
        // Find pivot (maximum element in current column from row k to n-1)
        int maxRow = k;
        double maxVal = fabs(aug[k][k]);

        for (int i = k + 1; i < n; i++) {
            if (fabs(aug[i][k]) > maxVal) {
                maxVal = fabs(aug[i][k]);
                maxRow = i;
            }
        }

        // Check if matrix is singular
        if (maxVal < 1e-10) {
            cout << "Matrix is singular or nearly singular!\n";
            det = 0.0;

            // Clean up
            for (int i = 0; i < n; i++) {
                delete[] aug[i];
            }
            delete[] aug;

            return det;
        }

        // Swap rows if necessary
        if (maxRow != k) {
            swap(aug[k], aug[maxRow]);
            swapCount++;
        }

        // Eliminate below
        for (int i = k + 1; i < n; i++) {
            double factor = aug[i][k] / aug[k][k];

            // Update determinant: each elimination step multiplies det by factor
            // But we'll calculate det later from pivots

            for (int j = k; j <= n; j++) {
                aug[i][j] -= factor * aug[k][j];
            }
        }
    }

    // Calculate determinant (product of diagonal elements)
    for (int i = 0; i < n; i++) {
        det *= aug[i][i];
    }

    // Adjust for row swaps (each swap multiplies determinant by -1)
    if (swapCount % 2 != 0) {
        det = -det;
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = aug[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= aug[i][j] * x[j];
        }
        x[i] /= aug[i][i];
    }

    // Clean up augmented matrix
    for (int i = 0; i < n; i++) {
        delete[] aug[i];
    }
    delete[] aug;

    return det;
}

// Function to free allocated memory
void cleanup(int n, double **a, double *b, double *x) {
    if (a) {
        for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    if (b) {
        delete[] b;
    }

    if (x) {
        delete[] x;
    }
}

// Function to display the system
void displaySystem(int n, double **a, double *b) {
    cout << "\nSystem of Linear Equations:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << a[i][j] << " ";
        }
        cout << "| " << setw(10) << b[i] << "\n";
    }
    cout << endl;
}

// Function to display the solution
void displaySolution(int n, double *x) {
    cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(6) << x[i] << endl;
    }
    cout << endl;
}

// Function to verify the solution
double verifySolution(int n, double **a, double *b, double *x) {
    double maxError = 0.0;
    cout << "Verification (A*x - b):\n";
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        double error = fabs(sum - b[i]);
        maxError = max(maxError, error);
        cout << "Equation " << i << ": " << sum << " - " << b[i]
             << " = " << error << endl;
    }
    return maxError;
}

int main() {
    int n;
    double **a = nullptr;
    double *b = nullptr;
    double *x = nullptr;

    cout << "=== Gaussian Elimination with Row Pivoting ===\n";
    cout << "Enter the dimension of the system (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid dimension!\n";
        return 1;
    }

    // Create and fill matrices
    if (create(n, a, b) != 0) {
        cout << "Failed to create matrices!\n";
        return 1;
    }

    // Allocate solution vector
    x = new double[n];

    // Display the system
    displaySystem(n, a, b);

    // Solve the system
    double det = gauss(n, a, b, x);

    // Display results
    cout << "Determinant of matrix A = " << fixed << setprecision(6) << det << endl;
    displaySolution(n, x);

    // Verify the solution
    double maxError = verifySolution(n, a, b, x);
    cout << "\nMaximum error: " << maxError << endl;

    // Test with different dimensions
    cout << "\n=== Testing with different dimensions ===\n";
    int testSizes[] = {2, 3, 5};

    for (int size : testSizes) {
        cout << "\n--- Testing " << size << "x" << size << " system ---\n";

        double **testA = nullptr;
        double *testB = nullptr;
        double *testX = new double[size];

        // Create a test system (identity matrix for simplicity)
        testA = new double*[size];
        for (int i = 0; i < size; i++) {
            testA[i] = new double[size];
            for (int j = 0; j < size; j++) {
                testA[i][j] = (i == j) ? 2.0 : 1.0; // Diagonally dominant
            }
        }

        testB = new double[size];
        for (int i = 0; i < size; i++) {
            testB[i] = size + i; // Some arbitrary values
        }

        double testDet = gauss(size, testA, testB, testX);
        cout << "Determinant: " << testDet << endl;
        cout << "Solution: ";
        for (int i = 0; i < size; i++) {
            cout << testX[i] << " ";
        }
        cout << endl;

        // Cleanup test matrices
        for (int i = 0; i < size; i++) {
            delete[] testA[i];
        }
        delete[] testA;
        delete[] testB;
        delete[] testX;
    }

    // Clean up
    cleanup(n, a, b, x);

    return 0;
}