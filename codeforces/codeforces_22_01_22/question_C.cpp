//
// Created by Yuval on 1/12/2022.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<long long> results;
    for(int i = 0; i <t; i++ ){
        int n;
        cin >> n;
        int res= 0;
        int min_val = 0;
        set<int> s;
        vector<int> a;
        for(int j= 0; j < n; j++){
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
            s.insert(tmp);
            if(min_val == tmp){
                while(s.count(min_val) != 0) min_val++;
            }

        }
        results.push_back(0);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
