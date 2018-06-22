/* 
3.1 Three In One
Describe how you could use a single array to implement three stacks.

*/

#include <iostream>

using namespace std;

/************** STACK IMPLEMENTATION ******************/

template <class T>
class Node {
    public: 
        Node() { }
        Node(T val) : element(val), next(0) { }
        T element;
        Node<T>* next;
};


template <class T>
class Stack {
    public:
        Stack();

    private:
        Node<T>* top;
};



/***************** SOLUTION TO THE PROBLEM ***********************/


int main(){

    return 0;
}