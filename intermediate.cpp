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

//Complessità: θ(n)
int intermediate_nodes_aux(Node *x, int sum, int& res){
    if(!x)
        return 0;
    else{
        int left = intermediate_nodes_aux(x->left, sum + x->data,  res);
        int right = intermediate_nodes_aux(x->right, sum + x->data, res);
        
        if(left + right + x->data == sum){
            res++;
        }

        return left + right + x->data;
    }
}

int intermediate_nodes(Tree* t){
    int res = 0;
    int sum = intermediate_nodes_aux(t->root, 0, res);
    return res;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node(3);
    t->root->left = new Node(1);
    t->root->right = new Node(3);
    t->root->left->left = new Node(0);
    t->root->left->right = new Node(2);

    cout << intermediate_nodes(t) << endl;
    return 0;
}
