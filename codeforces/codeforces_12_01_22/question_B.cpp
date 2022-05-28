//
// Created by Yuval on 1/12/2022.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> results;
    for(int i = 0; i <t; i++ ){
        int n;
        cin >> n;
        int res = -1;
        map<int,pair<int,int>> c;
        for(int j = 0; j<n; j++){
            int x;
            cin >> x;
            if(c.count(x) == 0){
                c[x] = make_pair(j,j);
            } else{
                if(c[x].first == c[x].second){
                    c[x].second = j;
                    continue;
                }
                if(j - c[x].second < c[x].second - c[x].first){
                    c[x].first = c[x].second;
                    c[x].second = j;
                }
            }
        }
        int tmp;
        for(auto it = c.begin(); it != c.end(); it++){
            if(it->second.first == it->second.second) continue;
            tmp = it->second.first + n - it->second.second;
            if(tmp > res){
                res = tmp;
            }
        }
        results.push_back(res);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}


