/* 
2.4 Partition

Write code to partition a linked list around a value x, such that all nodes
less than x come before all nodes greater than or equal to x. If x is
contained within the list, the values of x only need to be after the leemnts
less than x. 
e.g. 3 5 8 5 10 2 1 (partition 5)
     3 1 2 10 5 5 8

*/

#include <iostream>

using namespace std;

/************** SINGLY LINKED LIST IMPLEMENTATION ******************/

// forward declaration
template <class T> class node;

template <class T>
class List {
    public:
        List() : head(0) { }
        node<T>* begin(){ return head; }

        node<T>* append(const T& val) {
            if (!head){
                head = new node<T>(val);
                return head;
            } else {
                node<T>* temp = head;
                while (temp->next){
                    temp = temp->next;
                }
                temp->next = new node<T>(val);
                return temp->next;
            }
        }

    private:
        node<T>* head;
};

template <class T>
class node {
    public: 
        node() { }
        node(T val) : element(val), next(0) { }
        T element;
        node<T>* next;
};


/***************** SOLUTION TO THE PROBLEM ***********************/

template <class T>
node<T>* partition(List<T>& linked_list, const T& value){
    // 3 5 8 5 10 2 1
    // 3 1 2 10 5 5 8
    node<T>* left = linked_list.begin();
    
    while (left && left->next){
        node<T>* right = left->next;

        // if left greater than the partition value, look for smaller to swap with
        if(left->element >= value){
            // advance right until smaller element or end found
            while (right && right->element >= value){
                right = right->next;
            }
            // done partitioning if smaller element not found
            if (right == 0){
                return left;
            } else {
                // swap if smaller element found
                T temp = left->element;
                left->element = right->element;
                right->element = temp;
            }
        }
        left = left->next;
    }
    return left;
}

int main(){
    List<int> my_list;

    my_list.append(3);
    my_list.append(5);
    my_list.append(8);
    my_list.append(5);
    my_list.append(10);
    my_list.append(2);
    my_list.append(1);
    my_list.append(4);

    cout << "ORIGINAL LIST: ";
    for (auto i = my_list.begin(); i != 0; i = i->next){
        cout << i->element << ' ';
    }
    cout << endl;

    node<int>* border = partition(my_list, 5);

    cout << "PARTITIONED ON 5: ";
    for (auto i = my_list.begin(); i != 0; i = i->next){
        cout << i->element << ' ';
    }
    cout << endl;

    cout << "BORDER OF SMALLER VS LARGER IS: " << border->element << endl;

    return 0;
}