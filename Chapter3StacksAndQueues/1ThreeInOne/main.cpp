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
        Node(T val) : element(val), down(0) { }
    
        T element;
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
            } else {
                top = new Node<T>(val);
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

    private:
        Node<T>* top;
};



/***************** SOLUTION TO THE PROBLEM ***********************/

class ThreeStacks{
public:
    ThreeStacks() : array_size(15), first_stack_top(0), first_stack_begin(0),
                    second_stack_top(15/3), second_stack_begin(15/3),
                    third_stack_top(15/3 * 2), third_stack_begin (15/3 * 2) { 
    }

    void push_first_stack(int val){
        if (first_stack_top < second_stack_begin){
            int_array[first_stack_top++] = val;
        } else {
            cout << "ERROR: FIRST STACK FULL, CAN'T PUSH " << val << ".\n";
        }
    }

    void push_second_stack(int val){
        if (second_stack_top < third_stack_begin){
            int_array[second_stack_top++] = val;
        } else {
            cout << "ERROR: SECOND STACK FULL, CAN'T PUSH " << val << ".\n";
        }
    }

    void push_third_stack(int val){
        if (third_stack_top < array_size){
            int_array[third_stack_top++] = val;
        } else {
            cout << "ERROR: THIRD STACK FULL, CAN'T PUSH " << val << ".\n";
        }
    }

    int pop_first_stack(){
        if (first_stack_top != first_stack_begin){
            return int_array[--first_stack_top];
        } else {
            cout << "ERROR: FIRST STACK EMPTY" << endl;
            return int();
        }
    }


    int pop_second_stack(){
        if (second_stack_top != third_stack_begin){
            return int_array[--second_stack_top];
        } else {
            cout << "ERROR: SECOND STACK EMPTY" << endl;
            return int();
        }
    }


    int pop_third_stack(){
        if (third_stack_top != array_size){
            return int_array[--third_stack_top];
        } else {
            cout << "ERROR: THIRD STACK EMPTY" << endl;
            return int();
        }
    }

private:
    const int array_size = 15;
    int int_array[15];

    int first_stack_top;
    int second_stack_top;
    int third_stack_top;

    const int first_stack_begin;
    const int second_stack_begin;
    const int third_stack_begin;
};

int main(){
    ThreeStacks my_stacks;
    cout << my_stacks.pop_first_stack() << endl;
    my_stacks.push_first_stack(5);
    my_stacks.push_first_stack(2);
    my_stacks.push_first_stack(15);
    my_stacks.push_first_stack(9);
    my_stacks.push_first_stack(1);
    my_stacks.push_first_stack(2);
    cout << my_stacks.pop_first_stack() << endl;
    cout << my_stacks.pop_first_stack() << endl;

    my_stacks.push_second_stack(90);
    cout << my_stacks.pop_second_stack() << endl;

    my_stacks.push_third_stack(150);
    my_stacks.push_third_stack(160);
    my_stacks.push_third_stack(170);
    cout << my_stacks.pop_third_stack() << endl;


    return 0;
}