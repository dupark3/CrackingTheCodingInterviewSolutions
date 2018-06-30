#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

/* adjacency list representation of a directed graph:

    8 -> 5 -> 4 
      -> 3 -> 4

*/

using namespace std;

class Node{
friend class List;
public:
    Node() : element(0), next(0) { }
    Node(int val) : element(val), next(0) { }

private:
    int element;
    Node* next;
};

class List{
friend class Graph;
public:
    List() : head(0) { }
    List(int n): head(new Node(n)) { }

    void insert(int n){
        if (head){
            Node* new_node = head;
            while(new_node->next){
                new_node = new_node->next;
            }
            new_node->next = new Node(n);
        } else {
            head = new Node(n);
        }
    }

    void remove(int n){
        if (head){
            Node* pointer = head;
            
            while(pointer->next && pointer->next->element != n){
                pointer = pointer->next;
            }
            
            if(pointer->next && pointer->next->element == n){
                Node* delete_this = pointer->next;
                pointer->next = pointer->next->next;
                delete delete_this;
            }
        }
    }

    Node* search(int n){
        Node* pointer = head;
        while (pointer){
            if (pointer->element == n){
                return pointer;
            } else {
                pointer = pointer->next;
            }
        }
        return pointer;
    }

private:
    Node* head;
};

// directed graph
class Graph {
public:
    Graph() { }
    
    void insert_vertex(int root, int new_value){
        Node* root_node = adjacency_list[new_value].search(root);
        if (!root_node){
            adjacency_list[new_value].insert(root);

        }
    }

private:
    unordered_map<int, List> adjacency_list;

};



int main() {
    Graph directed_graph;
    directed_graph.insert_vertex(5, 8);

    return 0;
}