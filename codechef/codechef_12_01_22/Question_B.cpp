
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
    vector<int> nums;
    for(int i = 0; i <t; i++ ) {
        int n;
        cin >> n;
        nums.push_back(n);
    }
    for(int i = 0; i <t; i++ ) {
        for(int r=0; r< nums[i]; r++){
            for(int c=0; c< nums[i]; c++){
                cout << 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}


