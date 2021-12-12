#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    double terms = 1, pivalue = 4;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    cout << "Enter the number of terms to approximate (or zero to quit):" << endl;
    cin >> n;
    while (n != 0)
    {
        while (terms <= n)
        {
            pivalue = pivalue + pow(-1, terms) * (1 / (2 * terms + 1)) * 4;
            terms += 1;
        }
        cout << "The approximation for Leibniz's Formula is " << pivalue << " using " << n << " terms." << endl;
        cout << "Enter the number of terms to approximate (or zero to quit):" << endl;
        cin >> n;
        terms = 1;
        pivalue = 4;
    }

    return 0;
}