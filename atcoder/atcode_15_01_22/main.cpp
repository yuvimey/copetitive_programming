
//
// Created by Yuval on 1/12/2022.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    map<int,vector<int>> occ;
    vector<int> res = vector<int>();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(occ.count(x) == 0){
            occ[x] = vector<int>();
        }
        occ[x].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int x,k;
        cin >> x >> k;
        if(occ.count(x) == 0){
            res.push_back(-1);
            continue;
        }
        if(occ[x].size() < k){
            res.push_back(-1);
        }
        else{
            res.push_back(occ[x][k-1] + 1);
        }
    }
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}


