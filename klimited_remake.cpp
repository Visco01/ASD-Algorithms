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

int klimited_aux(Node* x, int k, bool& res){
    if(!x)
        return 0;
    else{
        int sx = klimited_aux(x->left, k, res);
        int dx = klimited_aux(x->right, k, res);
        int tot = max(dx, sx);
        if(tot + x->data > k)
            res = false;

        return tot + x->data;
    }
}

bool klimited(Node* x, int k){
    bool res = true;
    int tot = klimited_aux(x, k, res);
    return res;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node(3);
    t->root->left = new Node(2);
    t->root->right = new Node(1);
    t->root->left->left = new Node(-1);
    t->root->left->right = new Node(4);
    t->root->right->right = new Node(2);
    t->root->right->left = new Node(2);
    cout << klimited(t->root, 10) << endl;
    return 0;
}