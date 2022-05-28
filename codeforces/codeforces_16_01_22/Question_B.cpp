//
// Created by Yuval on 1/12/2022.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<string> results;
    for(int i = 0; i <t; i++ ){
        string x;
        cin >> x;
        string y = to_string(x[0] + x[1] - 48*2) + x.substr(2,x.length()+1);
        for(int j=0; j<x.length() -1; j++){
            if( x[j] != '0' && x[j+1] != '0') {
                int val = x[j] + x[j + 1] - 48 * 2;
                if (val >= 10) {
                    y = x.substr(0, j);
                    y += to_string(val);
                    if (j < x.length() - 2) {
                        y += x.substr(j + 2, x.length() + 1);
                    }
                }
            }
        }
        results.push_back(y);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
