#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

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
  else if(r < heap.heapSize && heap.v.at(r) > heap.v.at(max))
    max = r;

  if(max != i){
    swap(heap.v.at(i), heap.v.at(max));
    max_heapify(heap, max);
  }
}

void build_max_heap(MaxHeap& heap){
  for(int i = heap.heapSize / 2; i >= 0; i--){
    max_heapify(heap, i);
  }
}

//O(1)
int heap_maximum(const MaxHeap& heap){
  if(heap.heapSize < 1){
    throw std::overflow_error( "received negative value" );
  }else{
    return heap.v.at[0];
  }
}

//O(logn)
int heap_extract_max(MaxHeap& Heap){
  if(heap.heapSize < 1){
    throw std::overflow_error( "received negative value" );
  }else{
    int max = heap.v.at(0);
    heap.v.at(0) = heap.v.at(heap.heapSize - 1);
    heap.heapSize--;
    max_heapify(heap, 0);
    return max;
  }
}

//O(logn)
void heap_increase_key(MaxHeap& heap, int i, int key){
  if(key < heap.v.at(i)) throw std::overflow_error( "received negative value" );
  heap.v.at(i) = key;
  while(i > 0 && heap.v.at(parent(i)) < key){
    swap(heap.v.at(parent(i)), heap.v.at(i));
    i = parent(i);
  }
}

//O(logn)
void max_heap_insert(MaxHeap& heap, int key){
  heap.heapSize++;
  heap.v.at(heap.heapSize - 1) = numeric_limits<int>::min();
  heap_increase_key(heap, heap.heapSize - 1, key);
}

int main(){
  vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
  MaxHeap heap{v, (int)v.size()};
  print(heap);
  // heapSort(heap);
  // print(heap);
  return 0;
}
