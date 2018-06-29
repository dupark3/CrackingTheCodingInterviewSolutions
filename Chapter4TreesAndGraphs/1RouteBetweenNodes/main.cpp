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

    bool route_in_between(int x, int y){
        queue<Node*> my_queue_x;
        queue<Node*> my_queue_y;
        for (int i = 0; i != nodes.size(); ++ i){
            if (nodes[i] && nodes[i]->element == x){
                my_queue_x.push(nodes[i]);
            }
            if (nodes[i] && nodes[i]->element == y){
                my_queue_y.push(nodes[i]);
            }
        }

        while(!my_queue_x.empty() && !my_queue_y.empty()){
            for (int j = 0; j != my_queue_x.front()->children.size(); ++j){
                cout << " x loop" << endl;
                my_queue_x.push(my_queue_x.front()->children[j]);
                if (my_queue_x.front() && my_queue_x.front()->element == y){
                    return true;
                }
            }
            my_queue_x.pop();
            cout << " in between" << endl;

            for (int k = 0; k != my_queue_y.front()->children.size(); ++k){
                cout << " y loop" << endl;
                my_queue_y.push(my_queue_y.front()->children[k]);
                if(my_queue_y.back() && my_queue_y.back()->element == x){
                    return true;
                }
            }
            my_queue_y.pop();

            cout << " while loop done" << endl;
        }

        return false;
    }
private:
    vector<Node*> nodes;
};


int main(){
        // 5 -> 3 -> 2 -> 1
        // 5 -> 4 -> 0
        //      4 -> 9
        //      4 -> 8 -> 10

    /*
                
                    3   2   1
                5
                    4   0
                        9
                        8   10
    */

    Graph my_graph(5);
    my_graph.link_new_node(3, 5);
    my_graph.link_new_node(4, 5);
    my_graph.link_new_node(0, 4);
    my_graph.link_new_node(9, 4);
    my_graph.link_new_node(8, 4);
    my_graph.link_new_node(2, 3);
    my_graph.link_new_node(1, 2);
    my_graph.link_new_node(10, 8);


    my_graph.BFS(5);

    if (my_graph.route_in_between(5, 10)){
        cout << "5 and 10 are connected.\n";
    }
    if (!my_graph.route_in_between(1, 10)){
        cout << "1 and 10 are not connected.\n";
    }

    return 0;
}