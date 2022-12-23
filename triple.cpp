#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

void merge(vector<int> &v, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> left, right;

    for (int i = 0; i < n1; i++){
        left.push_back(v.at(p + i));
    }
    for (int i = 0; i < n2; i++){
        right.push_back(v.at(q + i + 1));
    }

    int i, j, k;
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
        k++;
        i++;
    }

    while(j < n2){
        v.at(k) = right.at(j);
        k++;
        j++;
    }
}

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

/*
Complessità: T(n) = θ(nlogn) + O(2n)
                  = θ(nlogn) + O(n)
                  = θ(nlogn)
*/
bool triple(vector<int> &v){
    mergeSort(v, 0, v.size() - 1);
    int i, j;
    i = j = 0;
    bool found = 0;
    while (i < v.size() && j < v.size() && !found)
    {
        if(v.at(i) * 3 == v.at(j)){
            found = true;
        }else if(v.at(i) * 3 > v.at(j)){
            j++;
        }else{
            i++;
        }
    }

    return found;
}

int main(){
    vector<int> v = {4, 1, 4, 6, 3, 8, 4, 7, 10};
    print(v);
    cout << "Esistono x e y tali che x*3 = y?:    " << triple(v) << endl;
    print(v);
}