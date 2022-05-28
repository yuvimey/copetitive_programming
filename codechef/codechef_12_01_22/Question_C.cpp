
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
    vector<int> ands;
    for(int i = 0; i <t; i++ ) {
        int n, a;
        cin >> n >> a;
        nums.push_back(n);
        ands.push_back(a);
    }
    for(int i = 0; i <t; i++ ) {
        if(nums[i] == 1){
            if(ands[i]%2 == 0){
                cout << "Even" << endl;
                continue;
            }
            cout << "Odd" << endl;
            continue;
        }
        if(ands[i]%2 == 1) {
            if (nums[i] % i == 1) {
                cout << "Odd" << endl;
                continue;
            }
            cout << "Odd" << endl;
            continue;
        }
        cout << "Impossible" << endl;
    }

    return 0;
}


