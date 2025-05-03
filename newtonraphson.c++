#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, fx, dfx, error;
    double tolerance = 0.0001;
    int max_iterations = 100;
    int i = 0;

    cout << "Enter initial guess: ";
    cin >> x;

    while (i < max_iterations) {
        fx = x * x * x - x - 2; // f(x) = x^3 - x - 2
        dfx = 3 * x * x - 1;    // f'(x) = 3x^2 - 1

        if (abs(dfx) < 1e-10) {
            cout << "Derivative too small!" << endl;
            return 0;
        }

        double x_new = x - fx / dfx;
        error = abs(x_new - x);

        if (error < tolerance) {
            cout << "Root is: " << x_new << endl;
            cout << "Iterations: " << i + 1 << endl;
            break;
        }

        x = x_new;
        i++;
    }

    if (i >= max_iterations) {
        cout << "Method failed to converge!" << endl;
    }

    return 0;
}