#ifndef GUARD_SetOfStacks_h
#define GUARD_SetOfStacks_h

#include <vector>

#include "Stack.h"

template <class T>
class SetOfStacks{
public:
    SetOfStacks() : stack_pointers(), capacity(0), top_stack_index(-1) { }
    SetOfStacks(int n) : stack_pointers(), capacity(n), top_stack_index(-1) { }

    void push(T val){
        if (!stack_pointers.empty()){
            if (stack_pointers[top_stack_index]->height < capacity){
                stack_pointers[top_stack_index]->push(val);
            } else {
                stack_pointers.push_back(new Stack<T>(val));
                ++top_stack_index;
            }
        } else {
            stack_pointers.push_back(new Stack<T>(val));
            ++top_stack_index;
        }   
    }

    T pop(){
        if(!stack_pointers.empty()){
            T return_value = stack_pointers[top_stack_index]->pop();
            if (stack_pointers[top_stack_index]->height == 0){
                delete stack_pointers[top_stack_index];
                --top_stack_index;
                stack_pointers.pop_back();
            }
            return return_value;
        } else {
            return T();
        }
    }

    bool isEmpty(){
        return !stack_pointers.empty();
    }

    T peek(){
        if(!stack_pointers.empty()){
            return stack_pointers[top_stack_index]->peek();
        }
    }

    T pop_at(int n){
        if(n <= top_stack_index){
            T ret_value = stack_pointers[n]->pop();
            if (stack_pointers[n]->height == 0){
                auto iterator_pos = stack_pointers.begin() + n;
                delete stack_pointers[n];
                --top_stack_index;
                stack_pointers.erase(iterator_pos);
            }
            return ret_value;
        } else {
            return T();
        }
    }

    void print(){
        if(!stack_pointers.empty()){
            for (int i = top_stack_index; i != -1; --i){
                stack_pointers[i]->print();
            }
        }
    }


private:
    std::vector< Stack<T>* > stack_pointers;
    int capacity;
    int top_stack_index;
};

#endif