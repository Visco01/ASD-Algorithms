#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
Procedimento per creare uno heap:
- scorrere l'array da metà albero al contrario (in quanto l'altra metà sono solo foglie)
- chiamare la max_heapify ogni volta

Procedimento per l'heapSort:
- costruire uno heap
- scorrere l'albero al contrario, swappare l'ultimo elemento con il primo, chiamare la max_heapify, 
    diminuendo la dimensione dell'heap.
*/

class MaxHeap {
    public:
        vector<int> v;
        int heapSize;

        MaxHeap(vector<int> in_v, int in_heapSize){
            v = in_v;
            heapSize = in_heapSize;
        }
};

int left(int i){
    return i * 2;
}

int right(int i){
    return (i * 2) + 1;
}

int parent(int i){
    return i / 2;
}

void max_heapify(MaxHeap& heap, int i){
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < heap.heapSize && heap.v.at(l) > heap.v.at(i))
        max = l;
    if(r < heap.heapSize && heap.v.at(r) > heap.v.at(max))
        max = r;

    if(i != max){
        swap(heap.v.at(i), heap.v.at(max));
        max_heapify(heap, max);
    }
}

void build_max_heap(MaxHeap& heap){
    for(int i = heap.heapSize / 2; i >= 0; i--){
        max_heapify(heap, i);
    }
}

void heapSort(MaxHeap& heap){
    build_max_heap(heap);
    for (int i = heap.heapSize - 1; i > 0; i--){
        swap(heap.v.at(0), heap.v.at(i));
        heap.heapSize--;
        max_heapify(heap, 0);
    }
}

void print_heap(MaxHeap heap){
    for (int i = 0; i < heap.v.size(); i++)
    {
        cout << heap.v.at(i) << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    MaxHeap heap{v, (int)v.size()};
    print(heap);
    heapSort(heap);
    print(heap);
    return 0;
}