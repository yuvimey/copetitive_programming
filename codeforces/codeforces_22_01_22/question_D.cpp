//
// Created by Yuval on 1/19/2022.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;

set<int> not_bad;

bool check_good(int n){
    int count = 0;
    if(n == 0){
        return false;
    }
    while(n != 0){
        if(n%2 == 1){
            count++;
        }
        n = n/2;
    }
    if(count %2 == 0){
        return true;
    }
    return false;
}
void create_not_bad(int n){
    int i = 0;
    int num = 2;
    while(i< n){
        bool good = true;
        num++;
        for(auto it = not_bad.begin(); it != not_bad.end(); it++ ){
            good = check_good(num ^ *it);
            if(!good)
                break;

        }
        if(good && check_good(num)) {
            for(auto it = not_bad.begin(); it != not_bad.end(); it++ ){
                not_bad.insert(num ^ *it);
            }
            not_bad.insert(num);
            i++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    vector<int> vals;
    for(int i = 0; i <t; i++ ){
        int k;
        cin >> k;
        vals.push_back(k);
    }
    int mx = *max_element(vals.begin(),vals.end());
    create_not_bad(mx);
    for(int i = 0; i < vals.size(); i++){
        auto it = not_bad.begin();
        for(int j = 0; j < vals[i]; j++){
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
    return 0;
}


