// calculate.cpp
// By: Jennie Wu

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Usage: ./calculate int char int
// char can either be: + x or %
int main(int argc, char **argv) {
    // PART 1: Check to see if the number of arguments is correct
    //         Hint: use "if (argc ...)" to check this,
    //         use cerr to output any messages
    if (argc != 4){
        cerr << "Number of arguments is incorrect." << endl;
        exit(1);
    }

    // PART 2: Convert arguments into integers (only those that need it!)
    //         Hint: this means using atoi()
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    int num3;
    string abc = string(argv[2]);

    // PART 3: Check for illegal operations like divide by zero...
    //         use cerr to output any messages
    if ((abc != "+") && (abc != "x") && (abc != "%")){
        cerr << "Bad operation choice." << endl;
        exit(1);
    }

    // PART 4: Do the appropriate calculation,
    //         outputs using both cout and cerr
    if (abc == "+"){
        num3 = num1 + num2;
        cout << num3 << endl;
    }
    else if (abc == "x"){
        num3 = num1 * num2;
        cout << num3 << endl;
    }
    else if (abc == "%"){
        if (num2 == 0){
        cerr << "Cannot divide by zero." << endl;
        exit(1);
        }
        num3 = num1 % num2;
        cout << num3 << endl;
    }

    return 0;
}