#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z, x_new, y_new, z_new, error;
    double tolerance = 0.0001;
    int max_iterations = 100;
    int i = 0;

    
    x = 0;
    y = 0;
    z = 0;

    cout << "Solving system: 3x + y + z = 7, x + 4y - z = 4, x - y + 5z = 6" << endl;

    while (i < max_iterations) {
        
        x_new = (7 - y - z) / 3.0;        
        y_new = (4 - x + z) / 4.0;        
        z_new = (6 - x + y) / 5.0;        

        error = abs(x_new - x);
        if (abs(y_new - y) > error) error = abs(y_new - y);
        if (abs(z_new - z) > error) error = abs(z_new - z);

        x = x_new;
        y = y_new;
        z = z_new;

        if (error < tolerance) {
            cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;
            cout << "Iterations: " << i + 1 << endl;
            break;
        }

        i++;
    }

    if (i >= max_iterations) {
        cout << "Method failed to converge!" << endl;
    }

    return 0;
}