#ifndef GUARD_threestacks_h
#define GUARD_threestacks_h

#include <iostream>

class ThreeStacks{
public:
    ThreeStacks() : array_size(15), first_stack_top(0), first_stack_begin(0),
                    second_stack_top(15/3), second_stack_begin(15/3),
                    third_stack_top(15/3 * 2), third_stack_begin (15/3 * 2) { 
    }

    void push_first_stack(int val);
    void push_second_stack(int val);
    void push_third_stack(int val);

    int pop_first_stack();
    int pop_second_stack();
    int pop_third_stack();

    bool shift_down_second_stack();
    bool shift_down_third_stack();
    bool shift_up_second_stack();
    bool shift_up_third_stack();

    void print_stack();
    void print_positions();
private:
    const int array_size = 15;
    int int_array[15] = { 0 };

    int first_stack_top;
    int second_stack_top;
    int third_stack_top;

    int first_stack_begin;
    int second_stack_begin;
    int third_stack_begin;
};

#endif