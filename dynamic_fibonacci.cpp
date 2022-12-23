#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamic_fib(int n){
    vector<int> fib = {0, 1};

    for(int i = 2; i < n; i++)
        fib.push_back(fib.at(i - 1) + fib.at(i - 2));

    return fib;
}

void print(const vector<int>& arr){
    for(int elem : arr)
        cout << elem << " ";
    cout << endl;
}

int main(){
    vector<int> fib = dynamic_fib(14);
    print(fib);
    return 0;
}
