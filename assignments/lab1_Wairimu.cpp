#include <iostream>
#include <cmath>
using namespace std;

int create(int n, double **&a, double *&b)
{
    a = new double*[n];
    for(int i = 0; i < n; i++)
        a[i] = new double[n];

    b = new double[n];

    cout << "Enter matrix A:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter vector b:" << endl;
    for(int i = 0; i < n; i++)
        cin >> b[i];

    return 0;
}

double gauss(int n, double **a, double *b, double *x)
{
    double det = 1;

    for(int k = 0; k < n; k++)
    {
        int maxRow = k;
        for(int i = k + 1; i < n; i++)
            if(abs(a[i][k]) > abs(a[maxRow][k]))
                maxRow = i;

        if(maxRow != k)
        {
            swap(a[k], a[maxRow]);
            swap(b[k], b[maxRow]);
            det = -det;
        }

        det *= a[k][k];

        for(int i = k + 1; i < n; i++)
        {
            double factor = a[i][k] / a[k][k];

            for(int j = k; j < n; j++)
                a[i][j] -= factor * a[k][j];

            b[i] -= factor * b[k];
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        x[i] = b[i];
        for(int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];

        x[i] /= a[i][i];
    }

    return det;
}

int main()
{
    int n;
    cout << "Enter size n: ";
    cin >> n;

    double **a;
    double *b;
    double *x =  new double[n];

    create(n, a, b);

    double det = gauss(n, a, b, x);

    cout << "Solution:" << endl;
    for(int i = 0; i < n; i++)
        cout << "x" << i+1 << " = " << x[i] << endl;

    cout << "Determinant = " << det << endl;

        // Free memory - exactly as you suggested
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    delete[] b;
    delete[] x;

    return 0;
    return 0;
}