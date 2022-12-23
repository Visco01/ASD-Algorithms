#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <math.h>

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

//Complessità: Theta(n)
int check(Node* x, int h, int& max_h){
    if(!x)
        return 0;
    else{
        if(h > max_h)
            max_h = h;
        return 1 + check(x->left, h + 1, max_h) + check(x->right, h + 1, max_h);
    }
}

bool check_complete_bt(Tree* t){
    int h = 0;
    int n = check(t->root, 0, h);
    if (n == pow(2, h + 1) - 1)
        return true;
    return false;
}

int main(){
    Tree* t = new Tree();
    t->root = new Node(4);
    t->root->left = new Node(2);
    t->root->left->left = new Node(1);
    t->root->left->right = new Node(3);
    t->root->right = new Node(4);
    t->root->right->left = new Node(6);
    t->root->right->right = new Node(8);
    cout << check_complete_bt(t) << endl;
    return 0;
}