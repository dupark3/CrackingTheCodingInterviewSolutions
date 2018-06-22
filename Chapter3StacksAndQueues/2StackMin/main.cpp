/* 
3.1 Three In One
Describe how you could use a single array to implement three stacks.

*/

#include <iostream>

#include "StackMin.h"

using namespace std;

int main(){
    Stack<int> my_stack;

    if (my_stack.isEmpty()){
        cout << "Empty stack\n";
    }
    
    my_stack.push(1);
    my_stack.push(4);
    my_stack.push(2);
    my_stack.push(-7);
    my_stack.push(10);
    my_stack.push(15);
    my_stack.push(0);

    my_stack.print();

    cout << "Min is : " << my_stack.min() << endl;

    cout << my_stack.pop() << endl;
    cout << my_stack.pop() << endl;

    my_stack.print();

    cout << "Min is : " << my_stack.min() << endl;

    return 0;
}