#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

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

void mergeSort(vector<int> &v, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

int sum_equals_k(vector<int> v, int k){
    mergeSort(v, 0, v.size() - 1);
    int start = 0;
    int end = v.size() - 1;
    bool res = false;
    while (start < end && !res){
        if(v.at(start) + v.at(end) == k)
            res = true;
        else if(v.at(start) + v.at(end) < k)
            start++;
        else
            end--;
    }
    return res;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 10};
    cout << sum_equals_k(v, 14) << endl;
    return 0;
}