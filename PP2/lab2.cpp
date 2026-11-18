#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;

void username(){
        cout << "Author: Yehorova Zlata"<< endl;
        cout << "Calculation of a mathematical expression by given x.\nVariant 166" << endl;
}// function to output name 

double s(double x, double eps) noexcept{
    double term = 1.0;
    double sum = 1.0;
    int n = 0;
    while (term >= eps || term <= -eps) {
        term *= -(n*x*x)/(2.0*(2.0*n + 1.0));
        sum += term;
        n+=1;
    }
    return sum;
}
void checkx(double x){
    if (!(isfinite(x) && x >= -1 && x <= 1)){
        throw invalid_argument("x must be in [-1, 1]");
    }
    if (cin.fail()){
        throw invalid_argument("wrong x");
    }
    if (cin.peek() != '\n'){
        throw invalid_argument("wrong x");
    }
}
void checkeps(double eps){
    if (!(isfinite(eps) && eps > 0)){
        throw invalid_argument("epsilon must be more than 0");
    }
    if (cin.fail()){
        throw invalid_argument("wrong eps");
    }
    if (cin.peek() != '\n'){
        throw invalid_argument("wrong eps");
    }

}
int main() {
    username();

    try{
        double x;
        cout << "Enter x in diapason [-1, 1] use point not comma: ";
        cin >> x;
        checkx(x);

        double eps;
        cout << "\nEnter epsilon > 0 for calculation use point not comma: ";
        cin >> eps;
        checkeps(eps);

        cout << "\n***** do calculations ... " ;
        double calculate = s(x, eps);
        cout << "done"<< endl;

        cout<< uppercase << scientific << setprecision (7) << "for x "<< x << endl;
        cout << uppercase << scientific << setprecision (9) << "for eps = " << eps << endl;
        cout << fixed << setprecision(8) << "result " << calculate << endl;
    }
    catch (const invalid_argument& e) {
        cout << "*****error: " << e.what() << endl;
    }  
}
