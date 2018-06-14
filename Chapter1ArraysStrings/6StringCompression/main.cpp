/* 
1.5 One Away 
Given two strings, write a function to check if they are one edit away
(insert, remove, or replace a char).
*/

#include <cstdlib> // size_t
#include <iostream>
#include <string>

using namespace std;

string CompressString(const string& input){
    string result;
    size_t input_size = input.size();
    for (size_t i = 0; i != input_size; ){
        result += input[i];
        int count = 1;
        while (i != input_size - 1 && input[i + count] == input[i]){
            ++count;
        }
        result += to_string(count);
        i += count;
    }
    
    if (result.size() >= input_size){
        return input;
    } else {
        return result;
    }
    
    
}

int main(){
    cout << "Enter a string to compress: ";
    string input;
    cin >> input;

    cout << "COMPRESSED: " << CompressString(input) << endl;
    
    return 0;
}