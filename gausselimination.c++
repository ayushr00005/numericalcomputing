#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    // Create matrix and answer array
    double mat[100][100];
    double ans[100];

    // Input matrix
    cout << "Enter matrix numbers:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    // Input answers
    cout << "Enter answer numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    // Make upper triangular matrix
    for (int k = 0; k < n; k++) {
        // Check if diagonal is zero
        if (mat[k][k] == 0) {
            cout << "Cannot solve!" << endl;
            return 1;
        }

        // Make zeros below diagonal
        for (int i = k + 1; i < n; i++) {
            double factor = mat[i][k] / mat[k][k];
            for (int j = k; j < n; j++) {
                mat[i][j] -= factor * mat[k][j];
            }
            ans[i] -= factor * ans[k];
        }
    }

    // Solve backwards
    double x[100];
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += mat[i][j] * x[j];
        }
        x[i] = (ans[i] - sum) / mat[i][i];
    }

    // Show answers
    cout << "Answers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}