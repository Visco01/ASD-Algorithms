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


vector<int> reverse_counting_sort(vector<int> a, int n, int k){
    vector<int> c, b;

    //Inizializzazione vettore delle occorrenze
    for(int i = 0; i <= k; i++){
        c.push_back(0);
    }

    for(int i = 0; i < n; i++){
        c.at( a.at(i) )++;
        b.push_back(0);
    }

    for(int i = k - 2; i >= 0; i--){
        c.at(i) = c.at(i) + c.at(i + 1);
    }

    for(int i = n - 1; i >= 0; i--){
        b.at( c.at( a.at(i) ) - 1 ) = a.at(i);
        c.at( a.at(i) )--;
    }

    return b;
}



int main(){
    vector<int> counting = {12, 3, 4, 18, 15, 5, 1, 7}; //da 0 a 20;
    counting = counting_sort(counting, counting.size(), 20);
    print(counting);
    counting = reverse_counting_sort(counting, counting.size(), 20);
    print(counting);
    return 0;
}
