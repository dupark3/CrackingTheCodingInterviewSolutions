#include "threestacks.h"

using namespace std;


void ThreeStacks::push_first_stack(int val){
    if (first_stack_top < second_stack_begin || shift_down_second_stack()){
        int_array[first_stack_top++] = val;
    } else {
        cout << "ERROR: ARRAY IS FULL, CAN'T PUSH " << val << ".\n";
    }
}

void ThreeStacks::push_second_stack(int val){
    cout << "Pushing second for " << val << endl;
    if (second_stack_top < third_stack_begin || shift_down_third_stack() || shift_up_second_stack()){
        int_array[second_stack_top++] = val;
    } else {
        cout << "ERROR: ARRAY IS FULL, CAN'T PUSH " << val << ".\n";
    }
}

void ThreeStacks::push_third_stack(int val){
    if (third_stack_top < array_size || shift_up_second_stack()){
        int_array[third_stack_top++] = val;
    } else {
        cout << "ERROR: ARRAY IS FULL, CAN'T PUSH " << val << ".\n";
    }
}

int ThreeStacks::pop_first_stack(){
    if (first_stack_top > first_stack_begin){
        int val = int_array[first_stack_top - 1];
        int_array[--first_stack_top] = 0;
        return val;
    } else {
        cout << "ERROR: FIRST STACK EMPTY" << endl;
        return int();
    }
}

int ThreeStacks::pop_second_stack(){
    if (second_stack_top > second_stack_begin){
        int val = int_array[second_stack_top - 1];
        int_array[--second_stack_top] = 0;
        return val;
    } else {
        cout << "ERROR: SECOND STACK EMPTY" << endl;
        return int();
    }
}


int ThreeStacks::pop_third_stack(){
    if (third_stack_top > third_stack_begin){
        int val = int_array[third_stack_top - 1];
        int_array[--third_stack_top] = 0;
        return val;
    } else {
        cout << "ERROR: THIRD STACK EMPTY" << endl;
        return int();
    }
}

bool ThreeStacks::shift_down_second_stack(){
    cout << "Shifting down second stack" << endl;
    if (second_stack_top + 1 < third_stack_begin){
        for (int i = second_stack_top + 1; i != second_stack_begin; ){
            int_array[i] = int_array[--i];
        }
        ++second_stack_top;
        ++second_stack_begin;
        return true;
    } else if (shift_down_third_stack()){
        return shift_down_second_stack();
    } else {
        // second and third stack full, can't shift second down
        return false;
    }
}

bool ThreeStacks::shift_down_third_stack(){
    cout << "Shifting down third stack" << endl;
    if (third_stack_top + 1 < array_size){
        for (int i = third_stack_top + 1; i != third_stack_begin; ) {
            int_array[i] = int_array[--i];
        }
        ++third_stack_top;
        ++third_stack_begin;
        return true;
    } else {
        return false;
    }
}

bool ThreeStacks::shift_up_second_stack(){
    if (second_stack_begin - 1 > first_stack_top){
        for (int i = second_stack_begin - 1; i != second_stack_top; ){
            int_array[i] = int_array[++i];
        }
        --second_stack_top;
        --second_stack_begin;
        return true;
    } else {
        return false;
    }
}

bool ThreeStacks::shift_up_third_stack(){
    if (third_stack_begin - 1 > second_stack_top || shift_up_second_stack()){
        for (int i = third_stack_begin - 1; i != third_stack_top; ) {
            int_array[i] = int_array[++i];
        }
        --third_stack_top;
        --third_stack_begin;
        return true;
    } else {
        return false;
    }
}

void ThreeStacks::print_stack(){
    for (int i = 0; i != array_size; ++i){
        cout << int_array[i] << " ";
    }
    cout << endl;
}

void ThreeStacks::print_positions(){
    cout << "First stack begin : " << first_stack_begin << endl
         << "First stack top   : " << first_stack_top << endl
         << "Second stack begin: " << second_stack_begin << endl
         << "Second stack top  : " << second_stack_top << endl
         << "Third stack begin : " << third_stack_begin << endl
         << "Third stack top   : " << third_stack_top << endl;
}