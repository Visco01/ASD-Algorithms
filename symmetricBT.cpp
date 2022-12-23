#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
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

bool isSymmetric(Node* n1, Node* n2){
    if(!n1 && !n2)
        return true;
    else if(!n1 || !n2)
        return false;
    else if(n1->data != n2->data)
        return false;
    else{
        return isSymmetric(n1->left, n2->right) && isSymmetric(n1->right, n2->left);
    }
}

int main()
{   
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->right->left = new Node(9);
    root->right->right = new Node(8);

    Tree* t = new Tree();
    t->root = root;

    cout << isSymmetric(t->root, t->root) << endl;

    return 0;
}