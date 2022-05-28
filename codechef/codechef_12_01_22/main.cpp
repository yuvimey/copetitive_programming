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
        int A1, A2, B1, B2, C1,C2;
        cin >> A1 >> A2 >> B1>>B2>> C1>>C2;
        int res = max(max(A1+A2, B1+B2), C1+C2);
        results.push_back(res);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}


