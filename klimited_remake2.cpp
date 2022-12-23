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


void klimited_aux(Node* x, int k, bool& res, int somma){
    if(!x)
        return;
    else
	    somma += x->data; 
	if (somma > k) res = false;
	else {
 	   klimited_aux(x->left, k, res, somma);
   	   klimited_aux(x->right, k, res, somma);
    }
}


bool klimited(Node* x, int k){
    bool res = true;
    int somma = 0;
    klimited_aux(x, k, res, somma);
    return res;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node(3);
    t->root->left = new Node(2);
    t->root->right = new Node(1);
    t->root->left->left = new Node(-1);
    t->root->left->right = new Node(40);
    t->root->right->right = new Node(2);
    t->root->right->left = new Node(2);
    cout << klimited(t->root, 10) << endl;
    return 0;
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