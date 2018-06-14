/* 1.3 Write a method to replace all spaces in a string with '%20'
e.g. "Mr John Smith    " size 13
     "Mr%20John%20Smith"  */

#include <cstdlib> // size_t
#include <iostream>
#include <string>
#include <map>

using namespace std;

void URLify(string& input){
    
}

int main(){
    cout << "Enter the string to URLify by replacing spaces with '%20': ";
    string input;
    getline(cin, input);

    // pass input string as reference in order to replace chars in place
    URLify(input) 
    cout << "RESULT: " << input << endl;
    
    return 0;
}