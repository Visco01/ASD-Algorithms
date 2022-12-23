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

void print(vector<int> v){
    for(int elem : v){
        cout << elem << " ";
    }
    cout << endl;
}

Node* tree_minimum(Tree* t){
    Node *x = t->root;
    while(x->left){
        x = x->left;
    }
    return x;
}

Node* tree_succ(Node* x){
    if(x->right){
        return x->right;
    }else{
        Node *y = x->p;
        while(y && x == y->right){
            x = y;
            y = x->p;
        }

        return y;
    }
}

void tree_insert(Tree* t, Node* new_node){
    Node *temp = nullptr;
    Node *x = t->root;

    while(x){
        temp = x;
        if(new_node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    new_node->p = temp;

    if(!temp)
        t->root = new_node;
    else{
        if(new_node->data < temp->data)
            temp->left = new_node;
        else{
            temp->right = new_node;
        }
    }
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

//Complessità: Theta(n*h) + O(h) + Theta(n*h)
// = Theta(n*h) + Theta(n*h)
// Theta(n*h)
void create_bst(Tree* t, vector<int> v){
    for (int i = 0; i < v.size(); i++){
        //O(h)
        tree_insert(t, new Node(v.at(i)));
    }

    //O(h)
    Node *x = tree_minimum(t);
    
    //O(n)
    while(x){
        cout << x->data << "  ";
        //O(h)
        x = tree_succ(x);
    }
    cout << endl;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    Tree* t = new Tree();
    print(v);
    create_bst(t, v);
    return 0;
}