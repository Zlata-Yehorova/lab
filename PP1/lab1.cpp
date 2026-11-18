#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>
using namespace std;

void username() {
    cout << "Author: Zlata Yehorova" << endl;
    cout << "Calculation of a mathematical expression by given x.\nVariant 166" << endl;
}// function to output name 

bool isindomain(double x) {
    return x > 3.0 and x != 4.0 and x != 10.0;
}// function to check domain
double f(double x) {
    return sin(24.0 / 60.0) + (2.0 * numbers::pi / (64.0 * numbers::e)) * (6.0 / ((x - 10.0) * (x - 4.0))) + 9.0 * cos(x - 13.0) + 1.0 / sqrt(x - 3.0);
}//function to calculate the value of the function

int main() {
    username();
    double x;
    cout << "Enter x (x > 3, x != 4, x != 10): ";
    cin >> x;

    if (cin.fail()) {
        cout << "wrong input" << endl;
    }
    else {
        bool range = isindomain(x);
        cout << "***** do calculations ... ";
        double result=f(x);

        cout << "done" << endl;
        cout << "for x = " << fixed << setprecision(5) << x << endl;

        if (range)
        {
            cout << "result = " << setprecision(9) << result << endl;
        }
        else
        {
            cout << "result = undefined";
        }
    }
}
