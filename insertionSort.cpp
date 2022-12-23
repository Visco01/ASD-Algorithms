#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
Procedimento: 
- scorrere l'array partendo dalla seconda posizione (il primo elemento è già ordinato).
- prendere l'elemento, confrontarlo con tutto l'array antecedente a quest'ultimo.
- fare un ciclo finche non si trova nella posizione giusta.
- aggiornare la posizione e ripetere il ciclo.
*/

void print(vector<int> v){
    for(int elem : v){
        cout << elem << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& v){
    int key = 0;
    int j = 0;
    for (int i = 1; i < v.size(); i++)
    {
        key = v.at(i);
        j = i - 1;
        while (j >= 0 && v.at(j) > key){
            v.at(j + 1) = v.at(j);
            j--;
        }
        v.at(j + 1) = key;
    }
}

/*
Complessità:
- Caso migliore (array già ordinato, MOLTO raro): θ(n)
- Caso peggiore: θ(n^2)
*/

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    print(v);
    insertionSort(v);
    print(v);
    return 0;
}