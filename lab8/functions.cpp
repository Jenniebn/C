// Place your member function and program function definitions here:
//  1. The 2 Constructors
//  2. Member function getAString
//  3. Member function cleanUp
//  4. Member function countLetters 
//  5. Program function compareCounts
// See lab description for details
//
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

AString::AString(){
    StringValue = "";
}

AString::AString(string str){
    StringValue = str;
}

void AString::getAString(){
    cout << "Enter string value: ";
    getline(cin, StringValue);
}

void AString::cleanUp(){
    string clean = "";
	for (int i = 0; i < StringValue.size(); i++){
		if (isalpha(StringValue[i])){
			clean += tolower(StringValue[i]);
		}
	}
    StringValue = clean;
}

void AString::countLetters(int array[]){
    for (int n = StringValue.size() - 1; n > 0; n--){
        for (int m = 0; m < n; m++){
            if (StringValue[m] > StringValue[m + 1]){
                int temp = StringValue[m + 1];
                StringValue[m + 1] = StringValue[m];
                StringValue[m] = temp;
            }
        }
    }
    for (int i = 0; i < StringValue.size(); i++){
        ++ (array[StringValue[i] - 'a']);
    }
}

bool compareCounts(int arr1[], int arr2[]){
    for (int i = 0; i < 26; i++){
        if (arr1[i] != arr2[i]){
            return true;
        }
    }
    return false;
}
