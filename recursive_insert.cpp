#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

class Node {
    public:
        int data;
        Node *p;
        Node *left;
        Node* right;

        Node(int val){
            data = val;
            left = right = p = nullptr;
        }
};

class Tree {
    public:
        Node *root;

        Tree(){
            root = nullptr;
        }
};

//O(h) in quanto potrebbe essere sbilanciato
void tree_insert_aux(Node* x, Node* z){
    if(z->data < x->data){
        if(x->left){
            tree_insert_aux(x->left, z);
        }else{
            x->left = z;
            z->p = x;
        }
    }else{
        if(x->right){
            tree_insert_aux(x->right, z);
        }else{
            x->right = z;
            z->p = x;
        }
    }
}

void tree_insert(Tree* t, Node* z){
    if(!t->root)
        t->root = z;
    else
        tree_insert_aux(t->root, z);
}

Node* build_bst_aux(vector<int> v, int min, int max, Node* p){
    if(min > max){
        return nullptr;
    }else{
        int pivot = (max + min) / 2;
        Node *root = new Node(v.at(pivot));
        root->p = p;
        root->left = build_bst_aux(v, min, pivot - 1, root);
        root->right = build_bst_aux(v, pivot + 1, max, root);
        return root;
    }
}

Tree* build_bst(vector<int> v){
    Tree* t = new Tree();
    t->root = build_bst_aux(v, 0, v.size() - 1, nullptr);
    return t;
}

void print_bst(Node* x, int l){
    if(!x)
        return;
    else{
        cout << "Livello: " << l << "  Valore: " << x->data;
        if(x->p){
            cout << "  Figlio di: " << x->p->data << endl;
        }else{
            cout << endl;
        }
        print_bst(x->left, l + 1);
        print_bst(x->right, l + 1);
    }
}

int main(){
    vector<int> v = {1, 2, 3, 4, 4, 6, 8, 9, 10};
    Tree* t;
    t = build_bst(v);
    print_bst(t->root, 0);
    tree_insert(t, new Node(7));
    tree_insert(t, new Node(5));
    tree_insert(t, new Node(0));
    print_bst(t->root, 0);
    return 0;
}