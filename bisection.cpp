#include <iostream>
#include <cmath>
using namespace std;

// Define the function for which we want to find the root
double f(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

int main() {
    double a, b, c, tolerance;

    // Input interval [a, b]
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    // Input tolerance
    cout << "Enter the tolerance: ";
    cin >> tolerance;

    // Check if the interval is valid
    if (f(a) * f(b) >= 0) {
        cout << "Bisection method cannot be applied on this interval." << endl;
        return 0;
    }

    // Bisection Method
    while ((b - a) >= tolerance) {
        // Find midpoint
        c = (a + b) / 2;

        // Check if midpoint is the root
        if (f(c) == 0.0) {
            break;
        }
        // Decide the new interval based on the sign of f(c)
        else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    // Output the result
    cout << "The approximate root is: " << c << endl;

    return 0;
}
