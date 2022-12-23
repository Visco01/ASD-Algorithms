#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <list>

using namespace std;

class Node {
    public:
        char* color;
        Node *p;
        Node *left;
        Node* right;

        Node(char val){
            color = new char();
            *color = val;
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

//Complessità: Theta(n)
tuple<int, int> countSameColor_aux(Node* x, int& res){
    if(!x)
        return {0, 0};
    else{
        int blank_sx, blank_dx, black_sx, black_dx;
        tie(black_sx, blank_sx) = countSameColor_aux(x->left, res);
        tie(black_dx, blank_dx) = countSameColor_aux(x->right, res);

        int blank = blank_dx + blank_sx;
        int black = black_dx + black_sx;

        //w sta per white
        if(*(x)->color == 'w'){
            blank += 1;
        }else{
            black += 1;
        }

        if(blank == black)
            res++;

        return {black, blank};
    }
}

int countSameColor(Tree* t){
    int res = 0;
    int c, c1;
    tie(c, c1) = countSameColor_aux(t->root, res);
    return res;
}

int main(){
    Tree *t = new Tree();
    t->root = new Node('b');
    t->root->left = new Node('b');
    t->root->right = new Node('w');
    t->root->right->left = new Node('b');
    t->root->left->right = new Node('w');
    cout << countSameColor(t) << endl;
    return 0;
}