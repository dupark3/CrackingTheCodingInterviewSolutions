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
        Node(T val) : element(val), min_element(), down(0) { }
    
        T element;
        T min_element;
        Node<T>* down;
};


template <class T>
class Stack {
public:
    Stack() : top(0) { }
    Stack(T val) : top(new Node<T>(val)) { }
    
    T pop() {
        if (top){
            T ret = top->element;
            Node<T>* new_top = top->down;
            delete top;
            top = new_top;
            return ret;
        } else {
            return T();
        }
    }

    void push(const T& val) {
        if (top){
            Node<T>* new_top = new Node<T>(val);
            new_top->down = top;
            top = new_top;

            top->min_element = val < top->down->min_element ? 
                               val : top->down->min_element;
        } else {
            top = new Node<T>(val);
            top->min_element = val;
            top->down = 0;
        }
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

    int min(){
        if (top){
            return top->min_element;
        }
    }

    void print(){
        Node<T>* iterator = top;
        while (iterator){
            cout << iterator->element << " ";
            iterator = iterator->down;
        }
        cout << endl;
    }

private:
    Node<T>* top;
};



/***************** SOLUTION TO THE PROBLEM ***********************/


int main(){
    Stack<int> my_stack;
    if (my_stack.isEmpty()){
        cout << "Empty stack\n";
    }
    
    my_stack.push(5);
    my_stack.push(4);
    my_stack.push(2);
    my_stack.push(7);
    my_stack.push(10);
    my_stack.push(15);
    my_stack.push(1);

    my_stack.print();

    cout << "Min is : " << my_stack.min() << endl;

    cout << my_stack.pop() << endl;
    cout << my_stack.pop() << endl;

    my_stack.print();

    cout << "Min is : " << my_stack.min() << endl;

    return 0;
}