#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x0, x1, x2, fx0, fx1, error;
    double tolerance = 0.0001;
    int max_iterations = 100;
    int i = 0;

    cout << "Enter two initial guesses x0 and x1: ";
    cin >> x0 >> x1;

    while (i < max_iterations) {
        fx0 = x0 * x0 * x0 - x0 - 2; 
        fx1 = x1 * x1 * x1 - x1 - 2;

        if (abs(fx1 - fx0) < 1e-10) {
            cout << "Slope too small!" << endl;
            return 0;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        error = abs(x2 - x1);

        if (error < tolerance) {
            cout << "Root is: " << x2 << endl;
            cout << "Iterations: " << i + 1 << endl;
            break;
        }

        x0 = x1;
        x1 = x2;
        i++;
    }

    if (i >= max_iterations) {
        cout << "failed !" << endl;
    }

    return 0;
}