
using namespace std;

template <class T>
class Node {

    public: 
        Node() { }
        Node(T val) : element(val), down(0), min_when_at_top(0) { }
    
        T element;
        bool min_when_at_top;
        Node<T>* down;
};


template <class T>
class Stack {
public:
    Stack() : top(0) { }
    Stack(T val) : top(new Node<T>(val)) { }
    
    T pop() {
        if (top){
            // if we are about to pop the min, delete the top of the min_node stack
            if (top->min_when_at_top){
                Node<T>* new_min = min_node->down;
                delete min_node;
                min_node = new_min;
            }

            // delete the top of the stack and update the top pointer to the one below 
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
            // add to the top of the stack
            Node<T>* new_top = new Node<T>(val);
            new_top->down = top;
            top = new_top;

            // update min_node if added value is a new min
            if (val < min_node->element){
                top->min_when_at_top = true;
                Node<T>* new_min = new Node<T>(val);
                new_min->down = min_node;
                min_node = new_min;
            }

        } else {
            // adding to an empty stack
            top = new Node<T>(val);
            min_node = new Node<T>(val);
            min_node->min_when_at_top = true;
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
        if (min_node){
            return min_node->element;
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
    Node<T>* min_node;
};