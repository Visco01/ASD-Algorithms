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

class MaxHeap {
    public:
        vector<int> v;
        int heapSize = 0;

        /*MaxHeap(vector<int> in_v, int in_heapSize){
            v = in_v;
            heapSize = in_heapSize;
        }*/
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

void print(vector<int> v){
    for(int elem : v){
        cout << elem << " ";
    }
    cout << endl;
}

void print_heap(MaxHeap heap){
    for (int i = 0; i < heap.v.size(); i++)
    {
        cout << heap.v.at(i) << " ";
    }
    cout << endl;
}

Node* tree_max(Node* x){
    if(!x)
        return nullptr;
    else{
        while(x->right){
            x = x->right;
        }
        return x;
    }
}

Node* tree_prev(Node* x){
    if(x->left)
        return tree_max(x->left);
    else{
        Node *y = x->p;
        while(y && x == y->left){
            x = y;
            y = x->p;
        }
        return y;
    }
}

int build_heap_from_bst(Tree* t, MaxHeap& heap){
    Node *x = tree_max(t->root);
    while(x){
        heap.v.push_back(x->data);
        heap.heapSize++;
        x = tree_prev(x);
    }
    cout << endl;
    return heap.heapSize;
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
    print(v);
    t = build_bst(v);
    print_bst(t->root, 0);
    MaxHeap heap{};
    cout << build_heap_from_bst(t, heap) << endl;
    print_heap(heap);
}