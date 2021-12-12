#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

double mean(double sum, int num);
double median(double array[], int num);
double stanDeviation(double avg, int num, double array[]);
void bubbleSort(double array[], int size);

int main(){
    string fileName;
    int count = 0;
    double next(0), sum = 0, avg(0), array[1000];
    cout << "Enter filename: ";
    cin >> fileName;
    ifstream inStream(fileName);
    if (inStream.fail()){
        cout << "Input file opening failed. \n";
        exit(1);
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    
    while (inStream >> next){
        sum = sum + next;
        array[count] = next;
        count ++;
    }
    cout << "Mean = " << mean(sum, count) << endl;
    cout << "Median = " << median(array, count) << endl;
    cout << "Stddev = " << stanDeviation(mean(sum, count), count, array) << endl;

    inStream.close();
    return 0;
}

double mean(double sum, int num){
    double avg(0);
    avg = sum / num;
    return avg;
}

void bubbleSort(double array[], int size){
    for (int i = size - 1; i >= 0; i--){
        for (int j = 1; j <= i; j++){
            if (array[j - 1] > array[j]){
                double temp;
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

double median(double array[], int num){
    bubbleSort(array, num);
    double median;
    if (num % 2 == 0){
        median = (array[(num - 1)/ 2] + array[num / 2]) / 2;
    }
    else{
        median = array[num / 2];
    }
    return median;
}

double stanDeviation(double avg, int num, double array[]){
    double stanDevia(0);
    for (int i = 0; i < num; i ++){
        stanDevia += pow(array[i] - avg, 2);
    }
    return sqrt(stanDevia / (num - 1));
}
