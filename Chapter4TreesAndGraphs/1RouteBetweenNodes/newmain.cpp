#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    Node() : element(0), next(0) { }
    Node(int val) : element(val), next(0) { }

private:
    int element;
    Node* next;
};

class List{
public:
    List() : head(0) { }

private:
    Node* head;
};

class Graph {
public:
    Graph() { }
    
    void insert_vertex(int new_value, int root){

    }

private:
    vector< vector<int> > adjacency_list;

};



int main() {

    return 0;
}