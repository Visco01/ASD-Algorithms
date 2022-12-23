#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

/*
VANTAGGI QUICKSORT
- Algoritmo in loco
- La complessità è IN MEDIA O(nlogn)

SVANTAGGI QUICKSORT
- nel caso peggiore la complessità raggiunge O(n^2)
- non è stabile (vedi merge sort)
*/

/*
Procedimento partition:
- impostare gli indici in modo da dividere l'array in: elementi più piccoli del pivot, uguali e maggiori al pivot.
- scorrere gli array e scambiare le posizioni, incrementare o decrementare gli indici.
- ritornare i due indici di massimo e minimo.
*/

tuple<int, int> partition(vector<int> &v, int start, int end){
    int pivot = v.at(end);
    int eq = start;
    int min = start;
    int max = end;

    while(eq < max){
        if(v.at(eq) < pivot){
            swap(v.at(eq), v.at(min));
            eq++;
            min++;
        }
        else if (v.at(eq) == pivot){
            eq++;
        }else{
            max--;
            swap(v.at(eq), v.at(max));
        }
    }

    swap(v.at(max), v.at(end));
    return {min, max + 1};
}

tuple<int, int> rand_partition(vector<int> &v, int start, int end){
    int pivot = rand() % v.size();
    swap(v.at(pivot), v.at(end));
    return partition(v, start, end);
}

/*
Procedimento quickSort:
- Partizionare e ordinare l'array
- applicare ricorsivamente il quickSort in due sottoarray
*/

void quickSort(vector<int> &v, int start, int end){
    if(start < end){
        int min, max;
        tie(min, max) = partition(v, start, end);
        quickSort(v, start, min - 1);
        quickSort(v, max + 1, end);
    }
}

void print(vector<int> v){
    for(int elem : v){
        cout << elem << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    print(v);
    quickSort(v, 0, v.size() - 1);
    print(v);
    return 0;
}