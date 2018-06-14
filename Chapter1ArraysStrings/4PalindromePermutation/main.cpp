/* 
1.4 Palindrome Permutation 
Given a string, write a function to check if it is a permutation of a plaindrome.
*/

#include <cstdlib> // size_t
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool IsPermutationOfPalindrome(const std::string& input){
    
}

int main(){
    cout << "Enter the string to check if it is a permutation of a palindrome: ";
    string input;
    getline(cin, input);


    if (IsPermutationOfPalindrome(input)){
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }

    return 0;
}