#include <iostream>
using namespace std;

int main(){
    int row, col, countc = 0, countr = 0;   
    cout << "Enter number of rows and columns:" << endl;
    cin >> row >> col;

    while ((row != 0) || (col != 0))
    {
        while ((countc < col) && (countr < row))
        {
            cout << "X.";
            countc = countc + 1;
            if ((countc == col) && (countr != row))
            {
            cout << endl;
            countc = 0;
            countr = countr + 1;
            }
            else if ((countc == col) && (countr == row))
            {
            cout << endl;
            }
        }
        cout << "Enter number of rows and columns:" << endl;
        cin >> row >> col;
        countc = 0;
        countr = 0;
    }
    return 0;
}