#include <iostream>
#include <vector>
#include <cstdlib>

/*
Heap: albero binario quasi completo, tutte le foglie addossate a sinistra.
heap.heapsize != heap.length

Max-Heap: v[parent(i)] >= v[i]
Altezza di un Heap è sempre logn
In un Heap, le foglie partono dall'indice n/2+1
In un Heap, ci sono al massimo (n/2^h+1) nodi di altezza h
In un Heap, n/2 elementi sono foglie

Complessità heapSort: O(nlogn)
*/

using namespace std;

class MaxHeap {
    public:
        vector<int> v;
        int heapSize;

        MaxHeap(vector<int> in_v, int in_heapSize){
            v = in_v;
            heapSize = in_heapSize;
        }
};

int parent(int i){
    return i / 2;
}

int left(int i){
    return i * 2;
}

int right(int i){
    return i * 2 + 1;
}

/*
Serve per mantenere la proprietà di Heap l'albero radicato in i
PRE-CONDIZIONE: gli alberi radicati in left(i) e right(i) devono essere degli Heap

Procedimento max_heapify:
- trovare l'elemento massimo tra i, i.left, i.right.
- scambiare i con il massimo
- ricorsione in indice massimo

Caso Peggiore: O(logn) -> altezza dell'albero.
*/

void max_heapify(MaxHeap& heap, int i){
    int l = left(i);
    int r = right(i);
    int max = i;

    if(l < heap.heapSize && heap.v.at(l) > heap.v.at(i)){
        max = l;
    }
    if(r < heap.heapSize && heap.v.at(r) > heap.v.at(max)){
        max = r;
    }

    if(i != max){
        swap(heap.v.at(i), heap.v.at(max));
        max_heapify(heap, max);
    }
}

void print(MaxHeap heap){
    for (int i = 0; i < heap.v.size(); i++)
    {
        cout << heap.v.at(i) << " ";
    }
    cout << endl;
}

void print_heap(MaxHeap heap){
    for (int i = 0; i < heap.heapSize; i++)
    {
        cout << heap.v.at(i) << " ";
    }
    cout << endl;
}

/*
Procedimento build Max-Heap:
- Ciclare l'array a partire da n/2 in quanto le foglie sono già dei max-Heap, arrivando alla prima posizione.
- Richiamare la max_heapify su ogni nodo.

Complessità: O(n)
*/

void build_maxheap(MaxHeap& heap){
    heap.heapSize = heap.v.size();
    for (int i = heap.heapSize / 2; i >= 0; i--){
        max_heapify(heap, i);
    }
}

/*
Procedimento heapSort:
- Costruisco max_heap
- ciclo l'heap al contrario, Prelievo il massimo, lo metto alla fine e diminuisco la heapSize
- richiamo la max_heapify in posizione i
*/

void heapSort(MaxHeap& heap){
    build_maxheap(heap);
    for (int i = heap.v.size() - 1; i >= 1; i--){
        swap(heap.v.at(0), heap.v.at(i));
        heap.heapSize--;
        max_heapify(heap, 0);
    }
}

/*
IMPLEMENTAZIONE CODE DI PRIORITA'
Struttura dati per mantenere un insieme dinamico degli elementi. Ciascuno ha una chiave o peso dell'elemento.
*/

//Semplicemente ritorna il massimo dell'heap. Complessità: θ(1)
int heap_maximum(MaxHeap heap){
    if(heap.heapSize > 0)
        return heap.v.at(0);
    else
        return -100;
}

//Estrae il massimo dall'heap e lo elimina, generando un nuovo heap. Complessità: θ(logn) -> max_heapify
int heap_extract_max(MaxHeap& heap){
    if(heap.heapSize > 0){
        int max = heap.v.at(0);
        swap(heap.v.at(0), heap.v.at(heap.heapSize - 1));
        heap.heapSize--;
        max_heapify(heap, 0);
        return max;
    }
    return -100;
}

/*
Procedimento increase_key:
- incrementa la chiave di un dato elemento.
- scorre l'albero fino alla radice se ci sono elementi da scambiare con il padre, in quanto egli deve essere >= figlio

Complessità: O(logn), in quanto può scorrere al massimo l'altezza dell'albero.
*/

void heap_increase_key(MaxHeap& heap, int i, int key){
    if(key > heap.v.at(i)){
        heap.v.at(i) = key;
        while(i >= 0 && heap.v.at(i) > heap.v.at(parent(i))){
            swap(heap.v.at(i), heap.v.at(parent(i)));
            i = parent(i);
        }
    }
}

//Complessità: O(logn) -> increase_key
void heap_insert(MaxHeap& heap, int key){
    if(heap.heapSize < heap.v.size()){
        heap.heapSize++;
        heap.v.at(heap.heapSize - 1) = numeric_limits<int>::min();
        heap_increase_key(heap, heap.heapSize - 1, key);
    }else{
        cout << "raggiunto il massimo del vettore" << endl;
    }
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    MaxHeap heap{v, (int)v.size()};
    print(heap);
    heapSort(heap);
    print(heap);
    build_maxheap(heap);
    cout << "Extract Max: " << heap_extract_max(heap) << endl;
    cout << "Extract Max: " << heap_extract_max(heap) << endl;
    print_heap(heap);
    heap_insert(heap, 12);
    heap_insert(heap, 5);
    heap_insert(heap, 44);
    print_heap(heap);
    heapSort(heap);
    print(heap);
    return 0;
}