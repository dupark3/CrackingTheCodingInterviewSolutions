/*
3.5 Sort Stack

Write a program to sort a stack such that the smallest items are on the top.
You can use an additional temporary stack, but you may not copy the elements
into any other data structure. The stack supports push, pop, peek, and
isEmpty.

*/

#include <iostream>

#include "SortStack.h"

using namespace std;

int main(){
    SortStack<int> my_stack;
    
    if (my_stack.isEmpty()){
        cout << "sort stack is empty\n";
    }
    
    cout << my_stack.pop() << endl;
    cout << my_stack.peek() << endl;
    return 0;
}