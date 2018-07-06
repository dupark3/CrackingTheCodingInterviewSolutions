#include <iostream>
#include <vector>

using namespace std;

class Node{
friend class BST;
public:
    Node() : element(0), left(0), right(0) { }
    Node(int val) : element(val) { }
private:
    int element;
    Node* left;
    Node* right;
};

class BST{
public:
    BST() : root(0) { }
    BST(int val) : root(new Node(val)) { }
    void insert(int n){
        if (!root){
            cout << "inserting " << n << " at the root" << endl;
            root = new Node(n);
        } else {
            Node* pointer = root;
            while (true){
                if (n < pointer->element){
                    if (!pointer->left){
                        cout << "inserting " << n << " to the left of " << pointer->element << endl;
                        pointer->left = new Node(n);
                        break;
                    } else {
                        pointer = pointer->left;
                    }
                } else {
                    if (!pointer->right){
                        cout << "inserting " << n << " to the right of " << pointer->element << endl;
                        pointer->right = new Node(n);
                        break;
                    } else {
                        pointer = pointer->right;
                    }
                }
            }
        }
    }

private:
    Node* root;
};

void addMidpoint(BST& tree, vector<int>& array, int begin, int end){
    if (begin != end){
        int mid = begin + ((end - begin) / 2);
        tree.insert(array[mid]);
        if (mid != begin && mid != end){
            addMidpoint(tree, array, begin, mid);
            addMidpoint(tree, array, mid + 1, end);
        }
    }
}

BST createBST(vector<int>& array){
    int mid = array.size() / 2;
    BST tree;
    if (!array.empty()){
        tree.insert(array[mid]);
    }
    if (mid != 0 && mid != array.size()){
        addMidpoint(tree, array, 0, mid);
        addMidpoint(tree, array, mid + 1, array.size());
    }
    return tree;
}



int main(){
    vector<int> array = {1, 4, 5, 6, 9, 10, 11, 13, 19};
    BST result = createBST(array);
    return 0;
}