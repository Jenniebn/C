#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

string extraction(string str, int size);
int comparison(string array[], int size);
string cleanString(string str, int size);

int main(){
    string fileName, line, cleanLine, lastWord[1000], wordEnd;
    int count(0), numRhyme(0);
    double density;
    cout << "Enter filename: ";
    cin >> fileName;
    ifstream inStream(fileName);
    if (inStream.fail()){
        cerr << "Input file opening failed. \n";
        exit(1);
    }

    while (getline(inStream, line)){   
        if (line == ""){
            lastWord[count] = line;
            count ++;
        }
        else{
            cleanLine = cleanString(line, line.size());
            lastWord[count] = extraction(cleanLine, cleanLine.size());
            count ++;
        }
    }

    numRhyme = comparison(lastWord, count);
    inStream.close();
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    density = numRhyme / static_cast<double>(count);

    if (numRhyme == 1){
        cout << "There is " << numRhyme << " pair of rhyming words." << endl;
        cout << "There are " << count << " lines in this poem, so the rhyme-line density is: " << density << endl;
    }
    else if (numRhyme == 0){
        cout << "No rhymes found." << endl;
        cout << "There are " << count << " lines in this poem." << endl;
    }
    else{
        cout << "There are " << numRhyme << " pairs of rhyming words." << endl;
        cout << "There are " << count << " lines in this poem, so the rhyme-line density is: " << density << endl;
    }
    
    return 0;
}

string cleanString(string str, int size){
	string clean = "";
    for (int i = 0; i < size; i++){
		if (isalpha(str[i]) || (str[i] == ' ')){
			clean += str[i];
		}
    }
    return clean;
}

string extraction(string str, int size){
    int index = str.rfind(' ');
    return str.substr(index + 1, size - index - 1); 
}

int comparison(string array[], int size){
    string str1, str2;
    int count(0);
    for (int i = 0; i < size - 1; i++){
        if ((array[i] == "") || (array[i + 1] == "")){
            str1 = "1";
            str2 = "";
        }
        else if ((array[i].size() == 2) && (array[i + 1].size() == 2)){
            str1 = array[i];
            str2 = array[i + 1];
        }
        else if ((array[i].size() == 2) && (array[i + 1].size() != 2)){
            str1 = array[i];
            str2 = array[i + 1].substr(array[i + 1].size() - 2, array[i + 1].size() - 1);
        }
        else if ((array[i].size() != 2) && (array[i + 1].size() == 2)){
            str1 = array[i].substr(array[i].size() - 2, array[i].size() - 1);
            str2 = array[i + 1];
        }
        else{
            str1 = array[i].substr(array[i].size() - 2, array[i].size() - 1);
            str2 = array[i + 1].substr(array[i + 1].size() - 2, array[i + 1].size() - 1);
        }
        
        if (str1 == str2){
            cout << array[i] + " and " + array[i + 1] << endl;
            count ++;
        }
    }
    return count;
}