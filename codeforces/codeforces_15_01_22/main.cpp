
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
    int t;
    cin >> t;
    vector<int> results = vector<int>();
    for (int i = 0; i < t; i++) {
        int n,m,r,c;
        cin >> n >>m >>r>>c;
        int res = -1;
        string x;
        char y;
        for (int j = 0; j < n; j++) {
            cin >> x;
            for (int k = 0; k < m; k++) {
                y = x[k];
                if(y == 'B'){
                    if(res == -1) res = 2;
                    if(j+1 ==r && k+1 == c){
                        res = 0;
                    }
                    else if(j+1 ==r && res == 2){
                        res = 1;
                    }
                    else if(k+1 ==c && res == 2){
                        res = 1;
                    }
                }
            }
        }
        results.push_back(res);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
}


