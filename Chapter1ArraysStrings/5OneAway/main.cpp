/* 
1.5 One Away 
Given two strings, write a function to check if they are one edit away
(insert, remove, or replace a char).
*/

#include <algorithm> // min
#include <cmath> // abs
#include <cstdlib> // size_t
#include <iostream>
#include <string>

using namespace std;

bool OneAway(const string& input1, const string& input2){
    ssize_t size_diff = input1.size() - input2.size();
    bool one_char_diff = false;

    // replace situation like pale --> bale
    if (size_diff == 0){
        size_t input_size = input1.size();

        for (size_t i = 0; i!= input_size; ++i){
            if (input1[i] == input2[i]){
                ;
            } else if (input1[i] != input2[i] && !one_char_diff) {
                one_char_diff = true;
            } else {
                return false;
            }
        }

        return true;

    // insert or remove situation with one size difference
    } else if (abs(size_diff) == 1) {
        for (size_t i = 0, j = 0; i != input1.size() && j != input2.size(); ++i, ++j){
            if (input1[i] == input2[j]){
            } else if (input1[i] != input2[j] && !one_char_diff){

                one_char_diff = true;
                if (input1[i + 1] == input2[j]){
                    ++i;
                } else if (input1[i] == input2[j + 1]){
                    ++j;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return true;

    } 

    // not one edit distance away otherwise
    else {
        return false;
    }
}

int main(){
    cout << "Enter two strings to check if they are one edit away: ";
    string input1, input2;
    cin >> input1 >> input2;

    if (OneAway(input1, input2)){
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }

    return 0;
}