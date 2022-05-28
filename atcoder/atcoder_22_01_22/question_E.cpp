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
    vector<bool> results2;
    for(int i = 0; i <t; i++ ){
        int k;
        cin >> k;
        int y = k/2;
        if( k%2 == 0 && (y%2 == 0 || y==1)){
            results2.push_back(false);
            continue;
        }
        results2.push_back(true);
        results.push_back(k);
    }
    int indx = 0;
    for(int i = 0; i < results2.size(); i++){
        if(results2[i] == false){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(results[indx]%2 == 1) {
            for (int i = 0; i < results[indx]; i++) {
                if (i % 2 == 0) {
                    cout << int(i / 2) + 1 << " ";
                    continue;
                }
                cout << results[indx] - int(i / 2) << " ";
            }
            indx++;
            cout << endl;
            continue;
        }
        for (int i = 0; i < results[indx]; i++) {
            if (i < results[indx]/2) {
                cout << results[indx]/2 + i + 1 << " ";
                continue;
            }
            cout <<  int(fabs(results[indx]/2 - i)) + 1 << " ";
        }
        indx++;
        cout << endl;
    }
    return 0;
}
