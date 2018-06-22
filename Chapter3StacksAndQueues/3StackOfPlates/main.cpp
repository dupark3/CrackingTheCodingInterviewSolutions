/* 
3.1 Three In One
Describe how you could use a single array to implement three stacks.

*/

#include <iostream>

#include "SetOfStacks.h"
#include "Stack.h"

using namespace std;

int main(){
    // if more than 5 stacks high, build a new stack
    SetOfStacks<int> my_set_of_stacks(5);

    if (my_set_of_stacks.isEmpty()){
        cout << "Empty stack\n";
    }
    
    my_set_of_stacks.push(1);
    my_set_of_stacks.push(4);
    my_set_of_stacks.push(2);
    my_set_of_stacks.push(-7);
    my_set_of_stacks.push(10);
    my_set_of_stacks.push(15);
    my_set_of_stacks.push(0);

    my_set_of_stacks.print();

    cout << "Popping at index 0 : " << my_set_of_stacks.pop_at(0) << endl;
    cout << "Popping at index 1 : " << my_set_of_stacks.pop_at(1) << endl;
    cout << "Popping at index 0 : " << my_set_of_stacks.pop_at(0) << endl;

    cout << "Peeking : " << my_set_of_stacks.peek() << endl;

    my_set_of_stacks.print();


    return 0;
}