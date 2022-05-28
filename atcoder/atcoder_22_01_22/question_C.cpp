//
// Created by Yuval on 1/19/2022.
//
//
// Created by Yuval on 1/19/2022.
//

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
    vector<int> results;
    for(int i = 0; i <t; i++ ){
        int k;
        cin >> k;
        int index = 0;
        while(k % 2 == 0){
            index++;
            k = k/2;
        }
        results.push_back(index);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}

