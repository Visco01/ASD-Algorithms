#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <limits>

using namespace std;

/*
Dato un albero binario con radice r, scrivere un algoritmo efficiente che verifichi se l’albero radicato in r è 
un albero binario di ricerca. L’algoritmo restituisce 1 se l’albero binario è di ricerca, 0 altrimenti.
Analizzare la complessità dell’algoritmo.

[Suggerimento: Può essere utile fare in modo che l’algoritmo calcoli anche il massimo e il 
minimo delle chiavi presenti nell’albero.]
*/

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

void merge(vector<int> &v, int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> left, right;

    for (int i = 0; i < n1; i++){
        left.push_back(v.at(p + i));
    }
    for (int i = 0; i < n2; i++){
        right.push_back(v.at(q + i + 1));
    }

    i = j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if(left.at(i) <= right.at(j)){
            v.at(k) = left.at(i);
            i++;
        }else{
            v.at(k) = right.at(j);
            j++;
        }
        k++;
    }

    while(i < n1){
        v.at(k) = left.at(i);
        i++;
        k++;
    }

    while(j < n2){
        v.at(k) = right.at(j);
        j++;
        k++;
    }
}

void mergeSort(vector<int> &v, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
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
}

/*
Complessità: θ(n) in quanto i nodi vengono visitati tutti una volta sola
*/

tuple<int, int> checkBSTaux(Node* x, char side){
    if(!x)
        if(side == 'l'){
            return {true, numeric_limits<int>::min()};
        }else{
            return {true, numeric_limits<int>::max()};
        }
        
    else{
        int bst_left, bst_right, left_value, right_value;
        tie(bst_left, left_value) = checkBSTaux(x->left, 'l');
        tie(bst_right, right_value) = checkBSTaux(x->right, 'r');

        if(bst_left && bst_right && x->data >= left_value && x->data <= right_value){
            return {true, x->data};
        }else{
            return {false, x->data};
        }
    }
}

bool checkBST(Node* root){
    int res, value;
    tie(res, value) = checkBSTaux(root, 'l');
    return res;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    Tree* t;
    mergeSort(v, 0, v.size() - 1);
    t = build_bst(v);
    print_bst(t->root, 0);
    cout << "è un bst?: " << checkBST(t->root) << endl;

    Tree *t1 = new Tree();
    t1->root = new Node(3);
    t1->root->left = new Node(100);
    cout << "è un bst?: " << checkBST(t1->root) << endl;
    return 0;
}
