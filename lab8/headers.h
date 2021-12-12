#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class AString {
    private:
        string StringValue;
    public:
        AString();
        AString(string str);
        void getAString();
        void cleanUp();
        void countLetters(int array[]);
    // You will need to declare:
    // 1. 2 constructors (see lab description for details)
    // 2. Three (3) member functions (see lab description for details)
    //      called getAString, cleanUp, countLetters
    // 3. One member variable called StringValue
    //
    // IMPORTANT: Figure out first which go in public and which in private.
};

// Declare the program function used in the main routine called compareCounts here:
// type compareCounts(arguments);
bool compareCounts(int arr1[], int arr2[]);