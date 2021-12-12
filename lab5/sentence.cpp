#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string sort_string(string sent, int size);
void print_freq(string sent, int size);

int main()
{
    string sentence;
    cout << "Enter sentence: ";
    getline(cin, sentence);
    sentence = sort_string(sentence, sentence.size());
    cout << "Sorted and cleaned-up sentence:" << sentence << endl;
    print_freq(sentence, sentence.size());

	return 0;
}

string sort_string(string sent, int size){
    // Sort in alphabetical order (per ASCII codes)
    // Remove all non-alphabetical characters
    string clean = "";
    int cleanSize = 0;
    for (int i = 0; i < size; i++){
        if (isalpha(sent[i])){
            clean += sent[i];
        }
    }
    cleanSize = clean.size();
    for (int n = cleanSize - 1; n > 0; n--){
        for (int m = 0; m < n; m++){
            if (clean[m] > clean[m + 1]){
                int temp = clean[m + 1];
                clean[m + 1] = clean[m];
                clean[m] = temp;
            }
        }
    }
    return clean;
}

void print_freq(string sent, int size){
    // Show the frequency of every letter in the string
    int count = 0, array[52];
    if (sent != ""){
        for (int i = 0; i < size; i++){
            for (int n = 65; (n >= 65) && (n <= 90); n++){
                char a = n;
                if (a == sent[i]){
                    count ++;
                }
            }
            for (int m = 97; (m >= 97) && (m <= 122); m++){
                char b = m;
                if (b == sent[i]){
                    count ++;
                }
            }
            if (sent[i] != sent[i + 1]){
                array[i] = count;
                count = 0;
                cout << sent[i] << ": " << array[i] << endl;
            }
        }
    }
    else{
        cout << "";
    }
}
