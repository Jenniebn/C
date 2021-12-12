/*
/ Skeleton file for arrays.cpp for CS16, 2021, UCSB
/ Copyright © 2021 by Zachary Sisco. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);

    print_array(array, size);
    cout << "Max = " << maxArray(array, size) << endl;
    cout << "Min = " << minArray(array, size) << endl;
    cout << "Sum = " << sumArray (array, size) << endl;
    evensArray (array, size);
    primesArray (array, size);
    AllSearches (array, size);
    cout << "correct";
    return 0;
}

// PUT MISSING FUNCTION DEFINITIONS HERE

void print_array(int arr[], int asize){
    for (int i = 0; i < asize; i++){
        cout << arr[i];
        if (i != (asize - 1)){
            cout << ", ";
        }
    }
    cout << endl;
}

int maxArray(int arr[], int asize){
    int max = arr[0];
    for (int i = 0; i < asize; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int minArray (int arr[], int asize){
    int min = arr[0];
    for (int i = 0; i < asize; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int sumArray (int arr[], int asize){
    int sum = 0;
    for (int i = 0; i < asize; i++){
        sum += arr[i];
    }
    return sum;
}

void evensArray (int arr[], int asize){
    cout << "Evens: ";
    for (int i = 0; i < asize; i++){
        if ((arr[i] % 2) == 0){
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl;
}

void primesArray (int arr[], int asize){
    cout << "Primes: ";
    bool flag = 0;
    for (int i = 0; i < asize; i++){
        if (arr[i] > 1){
            for (int j = 2; j < arr[i]; j++){
                if ((arr[i] % j) == 0){
                    flag = 1;
                }
            }
        }
        if ((flag == 0) && (arr[i] > 1)){
        cout << arr[i] << ", ";
        }
        flag = 0;
    }
    cout << "end" << endl;
}

int SeqSearch (int arr[], int array_size, int target){
    bool found = false;
    int index = 0;
    for (int i = 0; i < array_size; i++){
        if (arr[i] == target){
            found = true;
            break;
        }
        else{
            index ++;
        }
    }
    if (found){
        return index;
    }
    else{
        return -1;
    }
}

void AllSearches (int arr[], int array_size){
    cout << "Searches:" << endl;
    int result = 0;
    for (int i = 0; i < NSEARCHES; i++){
        result = SeqSearch (arr, array_size, SEARCHES[i]);
        cout << "Looking for " << SEARCHES[i] << ". ";
        if (result == -1){
            cout << "Not Found!" << endl;
        }
        else{
            cout << "Found at index: " << result << endl;
        }
    }
}