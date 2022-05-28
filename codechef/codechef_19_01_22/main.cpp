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
        int a, b, c;
        cin >> a >> b >> c;
        if( a > 50 || b > 50 || c > 50){
            if(a > 50){
                results.push_back("A");
                continue;
            }
            if(b > 50){
                results.push_back("B");
                continue;
            }
            if(c > 50){
                results.push_back("C");
                continue;
            }
        }else{
            results.push_back("NOTA");
        }

    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
