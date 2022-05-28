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
        long long n,k;
        cin >> n >> k;
        vector<long long> run;
        vector<long long> ram;
        for(int j = 0; j < n; j++){
            long long a;
            cin >> a;
            run.push_back(a);
        }
        for(int j = 0; j < n; j++){
            long long b;
            cin >> b;
            ram.push_back(b);
        }
        long long last_k = -1;
        while(k != last_k) {
            last_k = k;
            for (int j = 0; j < n; j++) {
                if (run[j] <= k && run[j] > 0) {
                    k += ram[j];
                    run[j] = -1;
                }
            }
        }
        results.push_back(k);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
