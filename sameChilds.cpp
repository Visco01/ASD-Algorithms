#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <list>

using namespace std;

class Node {
    public:
        int data;
        Node *p;
        Node *left_child;
        Node* right_sib;

        Node(int val){
            data = val;
            left_child = right_sib = p = nullptr;
        }
};

class Tree {
    public:
        Node *root;

        Tree(){
            root = nullptr;
        }
};

bool childs(Node* x){
    x = x->left_child;
    if(!x){
        return false;
    }else{
        int temp = x->data;
        while (x && x->data == temp)
        {  
            temp = x->data;
            x = x->right_sib;
        }
        if(x && x->data != temp)
            return false;
        else
            return true;
    }
}


void sameChildsAux(Node* x, int& res){
    if(!x)
        return;
    else{
        res += childs(x);
        sameChildsAux(x->left_child, res);
        sameChildsAux(x->right_sib, res);
    }
}

int sameChilds(Tree* t){
    int res = 0;
    sameChildsAux(t->root, res);
    return res;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node(6);
    t->root->left_child = new Node(2);
    t->root->left_child->right_sib = new Node(2);
    t->root->left_child->p = t->root;
    t->root->left_child->right_sib->p = t->root;
    t->root->left_child->left_child = new Node(1);
    t->root->left_child->left_child->p = t->root->left_child;
    t->root->left_child->left_child->right_sib = new Node(3);
    t->root->left_child->left_child->right_sib->p = t->root->left_child;
    t->root->left_child->right_sib->left_child = new Node(4);
    t->root->left_child->right_sib->left_child->p = t->root->left_child->right_sib;

    cout << sameChilds(t) << endl;
    return 0;
}