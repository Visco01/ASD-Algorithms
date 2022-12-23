#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

void countAR_aux(vector<char> v, int p, int r, int& res){
    if(r == p && v.at(p) == 'a' && v.at(p+1) == 'r'){
        res++;
    }
    if(p < r){
        int q = (p + r) / 2;
        countAR_aux(v, p, q, res);
        countAR_aux(v, q+1, r, res);
    }
}

int countAR(vector<char> v){
    int res = 0;
    countAR_aux(v, 0, v.size() - 1, res);
    return res;
}

int main(){
    vector<char> v = {'b', 'a', 'r', 'c', 'a', 'r', 'a', 'r'};
    cout << countAR(v) << endl;
}