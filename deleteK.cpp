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
    while(x && x->data != k){
        if(k < x->data)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

Node* tree_succ(Node* x){
    if(x->right){
        return x->right;
    }else{
        Node *temp = x->p;
        while(temp && x == temp->right){
            x = temp;
            temp = x->p;
        }
        return temp;
    }
}

Node* tree_pred(Node* x){
    if(x->left){
        return x->left;
    }else{
        Node *temp = x->p;
        while(temp && x == temp->left){
            x = temp;
            temp = x->p;
        }
        return temp;
    }
}

void transplant(Tree* t, Node* x, Node* y){
    if(x && !x->p)
        t->root = y;
    else if(x == x->p->left)
        x->p->left = y;
    else{
        x->p->right = y;
    }

    if(y){
        y->p = x->p;
    }
}

Node* tree_minimum(Node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

Node* tree_maximum(Node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

void tree_delete(Tree* t, Node* del){
    if(!del->left)
        transplant(t, del, del->right);
    else if(!del->right)
        transplant(t, del, del->left);
    else{
        Node *y = tree_minimum(del->right);
        if(y->p != del){
            transplant(t, y, y->right);
            y->right = del->right;
            del->right->p = y;
        }
        transplant(t, del, y);
        y->left = del->left;
        y->left->p = y;
    }

    cout << "DELETED " << del->data << endl;
    delete (del);
}

/*
Complessità: O(n): se si sceglie il numero minore, bisogna scorrere tutto l'albero.
*/

void eliminaMaggioriK(Tree* t, int k){
    Node *x = tree_search(t->root, k);
    if(!x)
        return;
    else{
        Node *temp = tree_succ(x);
        while (temp){
            tree_delete(t, temp);
            temp = tree_succ(x);
        }
    }
}

void eliminaNodi(Tree* t, int k) {
    
    if (t == nullptr) return;

    Node* x = tree_maximum(t->root);

    while (x->data != k) {
        Node* pred = tree_pred(x);
        tree_delete(t, x);
        x = pred;
    }
}

int main(){
    //4, 2, 3, 6, 1, 8, 7, 9, 10
    vector<int> v = {1, 2, 3, 3, 6, 7, 8, 9, 10};
    Tree* t;
    t = build_bst(v);
    print_bst(t->root, 0);
    eliminaMaggioriK(t, 7);
    //eliminaNodi(t, 7);
    print_bst(t->root, 0);

    return 0;
}