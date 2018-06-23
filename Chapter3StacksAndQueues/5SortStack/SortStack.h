#ifndef GUARD_SortStack_h
#define GUARD_SortStack_h

template <class T> class SortStack;

template <class T>
class Node{

friend class SortStack<T>;
public:
    Node();
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
            
            // 5 4 2 1  << 3
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
    

private:
    Node<T>* top;
};

#endif