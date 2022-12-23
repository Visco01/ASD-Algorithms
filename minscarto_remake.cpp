#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

void merge(vector<int>& v, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> left, right;

    for (int i = 0; i < n1; i++){
        left.push_back(v.at(p + i));
    }
    for(int i = 0; i < n2; i++){
        right.push_back(v.at(q + i + 1));
    }

    int i, j, k;
    i = j = 0;
    k = p;

    while(i < n1 && j < n2){
        if(left.at(i) < right.at(j)){
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

void mergeSort(vector<int>& v, int p, int r){
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

int minscarto(vector<int> v, int size){
    mergeSort(v, 0, v.size() - 1);
    int sum = 0;
    for (int i = 0; i < v.size(); i+=2){
        sum += (v.at(i + 1) - v.at(i));
    }
    return sum;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 12, 10};
    cout << "Scarto minimo: " << minscarto(v, v.size()) << endl;
    return 0;
}