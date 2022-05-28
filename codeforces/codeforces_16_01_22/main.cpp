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
    vector<string> results;
    for(int i = 0; i <t; i++ ){
        string s;
        cin >> s;
        vector<char> chars;
        sort(s.begin(),s.end());
        results.push_back(s);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
