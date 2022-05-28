//
// Created by Yuval on 1/12/2022.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> nums;
    set<int> m;
    int num = -1;
    bool picked_prev = false;
    int prev = -1;
    for(int i = 0; i <t; i++ ){
        int a;
        cin >> a;
        if(prev > a && !picked_prev){
            num = prev;
            picked_prev = true;
        }
        if(prev != -1 && a != prev) m.insert(prev);
        prev = a;
        nums.push_back(a);
    }
    if(!picked_prev) num = prev;
    for(int i = 0; i< nums.size(); i++){
        if(nums[i] != num)
            cout << nums[i] << " ";
    }
    return 0;
}
