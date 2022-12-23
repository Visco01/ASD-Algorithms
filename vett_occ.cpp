#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using namespace std;

//O(n)
bool sum_21(vector<int> v){
    vector<int> occ;
    for (int i = 0; i < 21; i++){
        occ.push_back(0);
    }
    int i = 0;
    bool res = false;
    while(i < v.size() && !res){
        if(v.at(i) < 21){
            if(occ.at(21 - v.at(i)) > 0)
                res = true;

            occ.at(v.at(i))++;
        }
        i++;
    }
    return res;
}

int main(){
    vector<int> v = {4, 2, 3, 6, 1, 8, 4, 9, 15};
    cout << sum_21(v) << endl;
    return 0;
}