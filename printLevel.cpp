#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node* right;

        Node(int val){
            data = val;
            left = right = nullptr;
        }
};

class Tree {
    public:
        Node *root;

        Tree(){
            root = nullptr;
        }
};

void printLevel_aux(Node* x, int k){
    if(!x)
        return;
    else{
        if(k == 0){
            cout << x->data << "  ";
        }
        printLevel_aux(x->left, k - 1);
        printLevel_aux(x->right, k - 1);
    }
}

void printLevel(Tree* t, int k){
    printLevel_aux(t->root, k);
    cout << endl;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node(3);
    t->root->left = new Node(5);
    t->root->right = new Node(7);
    t->root->right->left = new Node(1);
    t->root->right->left->left = new Node(4);
    t->root->right->left->right = new Node(9);

    printLevel(t, 1);
}