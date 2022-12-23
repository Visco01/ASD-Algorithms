#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

/*

Sia BST+ la struttura dati che si ottiene aggiungendo ad ogni nodo x di un albero binario di ricerca un nuovo attributo diff 
che contiene la differenza fra il numero di nodi nel sottoalbero sinistro e quelli nel sottoalbero destro di x.
Modificando la procedura Tree-insert si definisca una procedura BST+-insert per l’inserimento di una nuova chiave in un BST+.
Il prototipo della procedura è:

BST+-insert(TreeConDiff t, NodeConDiff z)
Si assuma che il nodo z sia così inizializzato: z.p = z.left = z.right = NULL
z.key = k (nuova chiave)
z.diff = 0

SOLUZIONE A RIGA 135
*/

class Node {
    public:
        int data;
        int diff; //differenza tra il numero di nodi nel sottoalbero sinistro e quello destro
        Node *p;
        Node *left;
        Node* right;

        Node(int val){
            data = val;
            diff = 0;
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

void print(vector<int> v){
    for(int elem : v){
        cout << elem << " ";
    }
    cout << endl;
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
        cout << "Livello: " << l << "  Valore: " << x->data << "  Diff: " << x->diff;
        if(x->p){
            cout << "  Figlio di: " << x->p->data << endl;
        }else{
            cout << endl;
        }
        print_bst(x->left, l + 1);
        print_bst(x->right, l + 1);
    }
}

void bstplus_insert(Tree* t, Node* z){
    Node *temp = nullptr;
    Node *x = t->root;

    while(x){
        temp = x;
        if(z->data < x->data){
            x->diff++;
            x = x->left;
        }else{
            x->diff--;
            x = x->right;
        }
    }

    z->p = temp;

    if(!temp){
        t->root = z;
    }else{
        if(z->data < temp->data){
            temp->left = z;
        }else{
            temp->left = z;
        }
    }
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    Tree* t;
    mergeSort(v, 0, v.size() - 1);
    t = build_bst(v);

    //-----------------------------------------
    Node *z = new Node(7);
    //print_bst(t->root, 0);
    bstplus_insert(t, z);
    print_bst(t->root, 0);
    return 0;
}