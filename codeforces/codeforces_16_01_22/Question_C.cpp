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
        int n;
        cin >> n;
        int sum = 0;
        vector<int> monst;
        vector<pair<int,int>> st;
        for(int j =0; j< n; j++){
            int k;
            cin >> k;
            monst.push_back(k);
        }
        for(int j =0; j< n; j++){
            int h;
            cin >> h;
            sum += (h*(h+1)/2);
            int start = monst[j] - h + 1;
            int end = monst[j];
            bool standalone = true;
            vector<pair<int,int>> new_st;
            for(int k = 0; k < st.size(); k++){
                if(start < st[k].first){
                    sum += st[k].second - st[k].first + 1;
                    new_st.push_back(make_pair(start,end));
                    standalone = false;
                    break;
                }
                else if(start >= st[k].first && start < st[k].second){
                    sum += st[k].second - st[k].first + 1;
                    new_st.push_back(make_pair(st[k].first,end));
                    standalone = false;
                    break;
                }
                new_st.push_back(make_pair(st[k].first,st[k].first));
            }
            if(standalone){
                new_st.push_back(make_pair(start,end));
            }
            st = new_st;
        }
        results.push_back(sum);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
