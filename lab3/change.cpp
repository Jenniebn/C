#include <iostream>
#include <string>
using namespace std;

void compute_coins(int amount);
string quarterAmount(int qAmount);
string dimeAmount(int dAmount);
string pennyAmount(int pAmount);

string quarterAmount(int qAmount){
    if (qAmount > 1){
        return " quarters";
    }
    else{
        return " quarter";
    }
}

string dimeAmount(int dAmount){
    if (dAmount > 1){
        return " dimes";
    }
    else{
        return " dime";
    }
}

string pennyAmount(int pAmount){
    if (pAmount > 1){
        return " pennies";
    }
    else{
        return " penny";
    }
}

void compute_coins(int amount){
    int quarter, dime, penny, oriAmount;
    string comma = ", ", period = ".";
    oriAmount = amount;

    if ((amount > 0) && (amount < 100)){
        quarter = amount / 25;
        amount -= quarter * 25;
        dime = amount / 10;
        amount -= dime * 10;
        penny = amount;
        
        if (oriAmount > 1){
            cout << oriAmount << " cents can be given in ";
        }
        else{
            cout << oriAmount << " cent can be given in ";
        }
        if ((quarter != 0) && (dime != 0) && (penny != 0)){
            cout << quarter << quarterAmount(quarter) + comma 
                 << dime << dimeAmount(dime) + comma 
                 << penny << pennyAmount(penny) + period << endl;
        }
        else if ((quarter == 0) && (dime != 0) && (penny != 0)){
            cout << dime << dimeAmount(dime) + comma 
                 << penny << pennyAmount(penny) + period << endl;
        }
        else if ((quarter != 0) && (dime == 0) && (penny != 0)){
            cout << quarter << quarterAmount(quarter) + comma 
                 << penny << pennyAmount(penny) + period << endl;
        }
        else if ((quarter != 0) && (dime != 0) && (penny == 0)){
            cout << quarter << quarterAmount(quarter) + comma 
                 << dime << dimeAmount(dime) + period << endl;
        }
        else if ((quarter != 0) && (dime == 0) && (penny == 0)){
            cout << quarter << quarterAmount(quarter) + period << endl;
        }
        else if ((quarter == 0) && (dime != 0) && (penny == 0)){
            cout << dime << dimeAmount(dime) + period << endl;
        }
        else if ((quarter == 0) && (dime == 0) && (penny != 0)){
            cout << penny << pennyAmount(penny) + period << endl;
        }
    }
    else{
        cout << "Amount is out of bounds. Must be between 1 and 99." << endl;
    }
}

int main(){
    int change;
    cout << "Enter number of cents (or zero to quit):" << endl;
    cin >> change;

    while (change != 0){
        compute_coins(change);
        cout << "Enter number of cents (or zero to quit):" << endl;
        cin >> change;
    }

    return 0;
}