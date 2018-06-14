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
    unordered_map<char, int> char_count;
    size_t input_size = input.size();

    for (size_t i = 0; i != input_size; ++i){
        ++char_count[input[i]];
    }

    int odd_chars = 0;
    for (auto i = char_count.begin(); i != char_count.end(); ++i){
        if (i->second % 2 == 0){
            // nothing to do if char occurs even number of times
        } else if (odd_chars == 1){
            // if more than one char occurs an odd number of times, not a palindrome
            return false;
        } else {
            // first odd char is allowed since it can go in the middle
            ++odd_chars;
        }
    }
    return true;
}

int main(){
    cout << "Enter the string to check if it is a permutation of a palindrome: ";
    string input;
    getline(cin, input);


    if (IsPermutationOfPalindrome(input)){
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }

    return 0;
}