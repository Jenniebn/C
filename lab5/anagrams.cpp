#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string cleanString(string string, int size);
int anagram(string string1, string string2, int size);
string sort_string(string sent, int size);
string lowerCase(string str, int size);

int main()
{
    string str1 = "", str2 = "", sort1 = "", sort2 = "", lower1 = "", lower2 = "";
	int size = 0, result = 0;
	cout << "Enter first string:" << endl;
	getline(cin, str1);
	cout << "Enter second string:" << endl;
	getline(cin, str2);
	// Clean strings
	lower1 = lowerCase(cleanString(str1, str1.size()), cleanString(str1, str1.size()).size());
	lower2 = lowerCase(cleanString(str2, str2.size()), cleanString(str2, str2.size()).size());
	sort1 = sort_string(lower1, lower1.size());
	sort2 = sort_string(lower2, lower2.size());
	// Check to see if they are anagrams
	if (sort1.size() < sort2.size()){
		size = sort1.size();
	}
	else{
		size = sort2.size();
	}
	result = anagram(sort1, sort2, size);
	// Report if they are or not anagrams
	if (result == -1){
		cout << "The strings are not anagrams." << endl;
	}
	else{
		cout << "The strings are anagrams." << endl;
	}
    return 0;
}

string cleanString(string str, int size){
	string clean = "";
	for (int i = 0; i < size; i++){
		if (isalpha(str[i])){
			clean += str[i];
		}
	}
	return clean;
}

string sort_string(string sent, int size){
    // Sort in alphabetical order (per ASCII codes)
    for (int n = size - 1; n > 0; n--){
        for (int m = 0; m < n; m++){
            if (sent[m] > sent[m + 1]){
                int temp = sent[m + 1];
                sent[m + 1] = sent[m];
                sent[m] = temp;
            }
        }
    }
    return sent;
}

string lowerCase(string str, int size){
	for (int i = 0; i < size; i ++){
		str[i] = tolower(str[i]);
	}
	return str;
}

int anagram(string string1, string string2, int size){
	int a = 0;
	for (int i = 0; i < size; i ++){
		if (string1[i] != string2[i]){
			a = -1;
			break;
		}
	}
	return a;
}
