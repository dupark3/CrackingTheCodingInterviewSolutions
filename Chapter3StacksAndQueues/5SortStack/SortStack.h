#ifndef GUARD_SortStack_h
#define GUARD_SortStack_h

#include <iostream>


template <class T> class SortStack;

template <class T>
class Node{

friend class SortStack<T>;
public:
    Node() : element(T()), below(0) { }
    Node(T val) : element(val), below(0) { }
private:
    T element;
    Node<T>* below;
};

template <class T>
class SortStack{

public:
    SortStack(): top(0) { }
    
    void push(T val){
        if (top){
            SortStack<T> temp_stack;
            
            // pop smaller items until we find the place to push the new value
            // save the smaller items into a temp stack in reverse order
            while(top->element < val){
                temp_stack.simple_push(pop());
            }
            
            // set new top as usual
            Node<T>* new_top = new Node<T>(val);
            new_top->below = top;
            top = new_top;
            
            // load back the temp stack on top of the new val
            while(!temp_stack.isEmpty()){
                simple_push(temp_stack.pop());
            }

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
    

private:
    Node<T>* top;

    void simple_push(T val){
        if (top){
            Node<T>* new_top = new Node<T>(val);
            new_top->below = top;
            top = new_top;
        } else {
            top = new Node<T>(val);
        }
    }
};

#endif