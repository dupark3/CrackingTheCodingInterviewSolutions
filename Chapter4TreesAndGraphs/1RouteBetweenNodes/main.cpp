#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
    friend class Graph;
public:
    Node() : element(0), children() { }
    Node(int n) : element(n), children() { }
private:
    int element;
    vector<Node*> children;
};

class Graph{
public:
    Graph() : nodes() { }
    Graph(int n){
        Node* new_node = new Node(n);
        nodes.push_back(new_node);
    }

    void link_new_node(int new_value, int parent){
        for (int i = 0; i != nodes.size(); ++i){
            if (nodes[i]->element == parent){
                Node* new_node = new Node(new_value);
                nodes.push_back(new_node);
                nodes[i]->children.push_back(new_node);
            }
        }
    }

    void BFS(int root){
        for (int i = 0; i != nodes.size(); ++i){
            if (nodes[i]->element == root){
                queue<Node*> my_queue;
                my_queue.push(nodes[i]);
                while (!my_queue.empty()){
                    cout << my_queue.front()->element << " ";
                    for (int j = 0; j != my_queue.front()->children.size(); ++j){
                        my_queue.push(my_queue.front()->children[j]);
                    }
                    my_queue.pop();
                }
                cout << endl;
                break;
            }
        }
    }
private:
    vector<Node*> nodes;
};


int main(){
        // 5 -> 3 -> 2 -> 1
        // 5 -> 4

    Graph my_graph(5);
    my_graph.link_new_node(3, 5);
    my_graph.link_new_node(4, 5);
    my_graph.link_new_node(0, 4);
    my_graph.link_new_node(9, 4);
    my_graph.link_new_node(8, 4);
    my_graph.link_new_node(2, 3);
    my_graph.link_new_node(1, 2);

    my_graph.BFS(5);

    return 0;
}