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

//MERGESORT-------------------------------------------
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
//MERGESORT-------------------------------------------

Node* tree_search(Node* x, int k){
    if(!x)
        return nullptr;
    else{
        if(k < x->data)
            return tree_search(x->left, k);
        else if(k > x->data)
            return tree_search(x->right, k);
        else
            return x;
    }
}

Node* tree_minimum(Node* x){
    while(x->left){
        x = x->left;
    }
    return x;
}

/*
Procedimento:
- se x.right esiste, richiamare ricorsivamente.
- altrimenti, posizionarsi sul padre e controllare costantemente che x sia figlio destro del padre, continuare
il ciclo per risalire l'albero.

Complessità O(h)
*/
Node* tree_succ(Node* x){
    if(x->right){
        return tree_minimum(x->right);
    }else{
        Node *y = x->p;
        while(y && x == y->right){
            x = y;
            y = x->p;
        }
        return y;
    }
}

/*
Procedimento tree_insert:
- scorrere l'albero finche non è null.
- se l'albero è la radice, impostarla.
- altrimenti, mettere il nuovo nodo come figlio dell'ultimo nodo trovato.

Complessità: O(h) e non logn in quanto l'albero non è detto che sia bilanciato.
*/
void tree_insert(Tree* t, int k){
    Node *new_node = new Node(k);
    Node *temp = nullptr;
    Node *x = t->root;

    while(x){
        temp = x;
        if(k < x->data)
            x = x->left;
        else
            x = x->right;
    }

    new_node->p = temp;

    if(!temp)
        t->root = new_node;
    else{
        if(k < temp->data)
            temp->left = new_node;
        else{
            temp->right = new_node;
        }
    }
}

/*
transplant: Sposta sottoalbero con radice V nella posizionde del sottoalbero radicato in U
Procedimento:
- Controllare se U è radice. Se si, sostituirlo
- Controllare se U è figlio sinistro o destro del padre, e sostituirlo.
- Controllare se V è null, se no allora impostare il padre.

Complessità costante.
*/
void transplant(Tree* t, Node* U, Node* V){
    if(U && U->p == nullptr){
        t->root = V;
    }else if(U == U->p->left){
        U->p->left = V;
    }else{
        U->p->right = V;
    }

    if(V){
        V->p = U->p;
    }
}

/*
tree_delete.
Procedimento:
- Se x è una foglia, modificare il padre a nullptr
- Se x ha un nodo figlio, collegare il figlio al padre.
- se x ha due figli, trovare il successore e sostituirlo
*/

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
}

/*
Procedimento build_bst
- passare un vettore ODINATO
- dividere a metà il vettore e usare l'elemento in mezzo come pivot.
- ricorsione a sinistra e a destra del noto, usando la prima parte del vettore e la seconda parte escluso il pivot stesso.
*/
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
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    Tree* t;
    print(v);
    mergeSort(v, 0, v.size() - 1);
    print(v);
    t = build_bst(v);
    //sprint_bst(t->root, 0);
    //cout << tree_succ(t->root->left->left)->data << endl;
    tree_delete(t, t->root->left);
    print_bst(t->root, 0);
    return 0;
}
