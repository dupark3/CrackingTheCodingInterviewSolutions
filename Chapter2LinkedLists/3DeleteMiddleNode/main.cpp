/* 
2.3 Delete Middle Node
Implement an algorithms to delete a node in the middle of a singly linked list
given only acces to that node.
*/

#include <cstdlib> // size_t
#include <iostream>
#include <unordered_map>

using namespace std;

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

int main(){
    List<int> my_list;
    my_list.append(5);
    my_list.append(7);

    node<int>* middle_node = my_list.append(10);

    my_list.append(13);
    my_list.append(15);

    cout << "ORIGINAL LIST: ";
    for (auto i = my_list.begin(); i != 0; i = i->next){
        cout << i->element << ' ';
    }
    cout << endl;

    return 0;
}