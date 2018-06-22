/* 
3.1 Three In One
Describe how you could use a single array to implement three stacks.

*/

#include <iostream>

#include "threestacks.h"

using namespace std;


int main(){
    ThreeStacks my_stacks;
    my_stacks.print_positions();
    my_stacks.print_stack();
    my_stacks.push_first_stack(5);
    my_stacks.push_first_stack(2);
    my_stacks.push_first_stack(15);
    my_stacks.push_first_stack(9);
    my_stacks.push_first_stack(1);
    my_stacks.push_first_stack(2);
    my_stacks.push_first_stack(5);
    my_stacks.push_first_stack(9);
    my_stacks.print_positions();
    my_stacks.print_stack();
    cout << my_stacks.pop_first_stack() << endl;
    cout << my_stacks.pop_first_stack() << endl;


    my_stacks.push_second_stack(90);
    my_stacks.push_second_stack(91);
    my_stacks.push_second_stack(92);
    my_stacks.print_positions();
    my_stacks.print_stack();
    cout << my_stacks.pop_second_stack() << endl;

    my_stacks.push_third_stack(150);
    my_stacks.push_third_stack(160);
    my_stacks.print_positions();
    my_stacks.print_stack();
    cout << my_stacks.pop_third_stack() << endl;
    my_stacks.print_positions();
    my_stacks.print_stack();

    return 0;
}