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

int t_balanced_aux(Node* x, int& t){
    if(!x)
        return 0;
    else{
        int sx = t_balanced_aux(x->left, t);
        int dx = t_balanced_aux(x->right, t);
        int h_max = max(sx, dx);
        t = abs(sx - dx);
        return h_max + 1;
    }
}

int t_balanced(Tree* tree){
    int t = 0;
    int h = t_balanced_aux(tree->root, t);
    return t;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node(3);
    t->root->left = new Node(5);
    t->root->right = new Node(7);
    t->root->right->left = new Node(1);
    t->root->right->left->left = new Node(4);
    t->root->right->left->right = new Node(9);

    cout << "min t: " << t_balanced(t) << endl;
    return 0;
}