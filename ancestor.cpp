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

Node* tree_search(Node* x, int k){
    bool flag = false;
    while (x && !flag)
    {
        if(k < x->data)
            x = x->left;
        else if(k > x->data)
            x = x->right;
        else
            flag = true;
    }
    return x;
}

bool ancestor(Tree* t, int k1, int k2){
    return tree_search(tree_search(t->root, k1), k2);
}

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    Tree* t;
    t = build_bst(v);
    print_bst(t->root, 0);
    cout << ancestor(t, 2, 4) << endl;
    return 0;
}