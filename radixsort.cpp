#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& a){
    for(int elem : a){
        cout << elem << " ";
    }
    cout << endl;
}

vector<int> counting_sort(vector<int> a, int n, int k){
    vector<int> c, b;

    //Inizializzazione vettore delle occorrenze
    for(int i = 0; i <= k; i++){
        c.push_back(0);
    }

    for(int i = 0; i < n; i++){
        c.at( a.at(i) )++;
        b.push_back(0);
    }

    for(int i = 1; i <= k; i++){
        c.at(i) = c.at(i) + c.at(i - 1);
    }

    for(int i = n - 1; i >= 0; i--){
        b.at( c.at( a.at(i) ) - 1 ) = a.at(i);
        c.at( a.at(i) )--;
    }

    return b;
}



int main(){
    vector<int> radix = {326, 453, 608, 835, 751, 435, 704, 690};
    cout << radix.at(0)[0] << endl;
    return 0;
}
