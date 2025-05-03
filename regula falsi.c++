#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, fa, fb, fc, error;
    double tolerance = 0.0001;
    int max_iterations = 100;
    int i = 0;

    cout << "Enter interval [a, b]: ";
    cin >> a >> b;

    fa = a * a * a - a - 2; 
    fb = b * b * b - b - 2;

    if (fa * fb >= 0) {
        cout << "No root in this interval!" << endl;
        return 0;
    }

    while (i < max_iterations) {
        c = (a * fb - b * fa) / (fb - fa); 
        fc = c * c * c - c - 2;

        error = abs(fc);
        if (error < tolerance) {
            cout << "Root is: " << c << endl;
            cout << "Iterations: " << i + 1 << endl;
            break;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        i++;
    }

    if (i >= max_iterations) {
        cout << " failed" << endl;
    }

    return 0;
}