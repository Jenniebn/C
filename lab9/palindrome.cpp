
// PLACE THE NECESSARY include, etc... STATEMENTS HERE
//
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// DECLARE THE FUNCTIONS HERE:
// 
void cleanUp(string& str);
bool isPalindrome(string str);

int main() {
    string p;
    cout << "Enter sentence:\n";
    getline(cin, p);
    
    cleanUp(p);
    bool answer = isPalindrome(p);
   
    if (answer) {
        cout << "It is a palindrome.\n";
    } else {
        cout << "It is not a palindrome.\n";
    }

    return 0;
}

// DEFINE THE FUNCTIONS HERE:
//

void cleanUp(string& str){
    string clean = "";
    for (int i = 0; i < str.size(); i++){
		if (isalpha(str[i])){
			clean += tolower(str[i]);
		}
    }
    str = clean;
}

bool isPalindrome(string str){
    if (str.size() <= 1){
        return true;
    }
    else{if (str[0] == str[str.size() - 1]){
            return isPalindrome(str.substr(1, str.size() - 2));
        }
        else{
            return false;
        }
    }
}