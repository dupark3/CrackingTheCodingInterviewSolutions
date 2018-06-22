#ifndef GUARD_Stack_h
#define GUARD_Stack_h

#include <iostream>

// forward decl
template <class T> class SetOfStacks;

template <class T>
class Node {

    public: 
        Node() { }
        Node(T val) : element(val), down(0){ }
    
        T element;
        Node<T>* down;
};


template <class T>
class Stack {

friend class SetOfStacks<T>;

public:
    Stack() : top(0), height(0) { }
    Stack(T val) : top(new Node<T>(val)), height(1) { }
    
    T pop() {
        if (top){
            // delete the top of the stack and update the top pointer to the one below 
            T ret = top->element;
            Node<T>* new_top = top->down;
            delete top;
            top = new_top;

            --height;

            return ret;
        } else {
            return T();
        }
    }

    void push(const T& val) {
        if (top){
            // add to the top of the stack
            Node<T>* new_top = new Node<T>(val);
            new_top->down = top;
            top = new_top;
        } else {
            // adding to an empty stack
            top = new Node<T>(val);
            top->down = 0;
        }
        ++height;
    }

    T peek() {
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
        Node<T>* iterator = top;
        while (iterator){
            std::cout << iterator->element << " ";
            iterator = iterator->down;
        }
        std::cout << std::endl;
    }

private:
    Node<T>* top;
    int height;
};

#endif