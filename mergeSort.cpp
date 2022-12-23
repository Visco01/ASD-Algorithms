#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
VANTAGGI MERGESORT:
- Complessità: θ(nlogn)
- Metodo stabile: i numeri con lo stesso valore rimangono nello stesso ordine di partenza

SVANTAGGI MERGESORT:
- Memoria aggiuntiva richiesta O(n)
- il tempo di calcolo dipende dal numero di elementi ed è indifferente al loro ordine.
*/

/*
Procedimento merge:
- trovare la lunghezza dei sottoarray
- creare e riempire due array temporanei di tali grandezze con i rispettivi valori
- ciclare e confrontare i due array mettendoli in ordine
*/

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

/*
Procedimento mergeSort:
metodo divide-et-impera: 
- trovare posizione mediana dell'array.
- richiamare mergeSort ricorsivamente per la prima metà dell'array e per la seconda metà dell'array.
- richiamare merge per ricomporli in un unico array ordinato.
*/

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

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    print(v);
    mergeSort(v, 0, v.size() - 1);
    print(v);
    return 0;
}
