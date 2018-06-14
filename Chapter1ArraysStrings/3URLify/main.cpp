/* 1.3 Write a method to replace all spaces in a string with '%20'
e.g. "Mr John Smith    " size 13
     "Mr%20John%20Smith"  */

#include <cstdlib> // size_t
#include <iostream>
#include <string>

using namespace std;

string URLify(const string& input){
    string result;

    size_t original_size = input.size();
    for (size_t i = 0; i != original_size; ++i){
        if (input[i] != ' '){
            result.append(1, input[i]);
        } else {
            result.append("%20");
        }
    }

    return result;
}

void URLify_in_place(string& input){
    size_t input_size = input.size();
    size_t number_of_spaces = 0;
    for (size_t i = 0; i != input_size; ++i){
        if (input[i] == ' '){
            ++number_of_spaces;
        }
    }

    // need twice as much space extra to add %20 in place of a space
    size_t result_size = input_size + (number_of_spaces * 2);
    input.reserve(result_size);

    // if space found, replace space, then advance by 3 to ignore the addded %20
    for (size_t i = 0; i != result_size; ){
        if (input[i] == ' '){
            input.erase(i, 1);
            input.insert(i, "%20");
            i += 3;
        } else {
            ++i;
        }
    }
}

int main(){
    cout << "Enter the string to URLify by replacing spaces with '%20': ";
    string input;
    getline(cin, input);

    // make a copy and return the result
    cout << "RESULT: " << URLify(input) << endl;
    
    // do it in place by passing it as a reference
    URLify_in_place(input);
    cout << "RESULT (in place): " << input << endl;

    return 0;
}