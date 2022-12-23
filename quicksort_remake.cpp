#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

pair<int, int> partition(vector<int>& v, int start, int end){
    int min = start;
    int eq = start;
    int max = end;
    int pivot = v.at(end);

    while(eq < max){
        if(v.at(eq) < pivot){
            swap(v.at(min), v.at(eq));
            min++;
            eq++;
        }
        else if (v.at(eq) > pivot)
        {
            max--;
            swap(v.at(eq), v.at(max));
        }
        else
        {
            eq++;
        }
    }

    swap(v.at(max), v.at(end)); // RIPRISTINARE IL PIVOT;
    max++;

    return make_pair(min, max);
}

pair<int, int> rand_partition(vector<int>& v, int start, int end){
    int pivot = rand() % v.size();
    swap(v.at(pivot), v.at(end));
    return partition(v, start, end);
}

void quickSort(vector<int>& v, int start, int end){
    if(start < end){
        pair<int, int> result;
        result = partition(v, start, end);
        quickSort(v, start, result.first - 1);
        quickSort(v, result.second + 1, end);
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