#ifndef GUARD_SortStack_h
#define GUARD_SortStack_h

#include <iostream>


template <class T> class Stack;

template <class T>
class Node{

friend class Stack<T>;
public:
    Node() : element(T()), below(0) { }
    Node(T val) : element(val), below(0) { }
private:
    T element;
    Node<T>* below;
};

template <class T>
class Stack{

public:
    Stack(): top(0) { }
    
    void push(T val){
        if (top){
            // set new top
            Node<T>* new_top = new Node<T>(val);
            new_top->below = top;
            top = new_top;
        } else {
            top = new Node<T>(val);
        }
    }

    T pop(){
        if (top){
            T return_value = top->element;
            Node<T>* new_top = top->below;
            delete top;
            top = new_top;
            return return_value;
        } else {
            return T();
        }
    }

    T peek(){
        if (top){
            return top->element;
        } else {
            return T();
        }
    }

    bool isEmpty(){
        return !top;
    }

    void print(){
        Node<T>* temp_pointer = top;
        while(temp_pointer){
            std::cout << temp_pointer->element << " ";
            temp_pointer = temp_pointer->below;
        }
        std::cout << std::endl;
    }

    Stack<T> sort_stack(){
        // origin 
        // result 5 4 3 2 1
        // temp   
        Stack<T> result_stack;
        
        while (!isEmpty()){
            T temp = pop();

            if (result_stack.isEmpty() || result_stack.peek() >= temp){
                result_stack.push(temp);
            } else {
                // if result stack is smaller, we have to pop it into original 
                // stack until we find the place to put this temp in
                while(!result_stack.isEmpty() && result_stack.peek() < temp){
                    push(result_stack.pop());
                }
                result_stack.push(temp);
            }
        }

        return result_stack;


    }

private:
    Node<T>* top;
};

#endif