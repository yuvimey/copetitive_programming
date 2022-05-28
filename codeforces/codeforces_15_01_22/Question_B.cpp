//
// Created by Yuval on 1/15/2022.
//


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
    vector<vector<int>> results = vector<vector<int>>();
    for (int i = 0; i < t; i++) {
        int n,m;
        cin >> n >> m;
        int res = (int)(n/2) + (int)(m/2);
        int center_rows, center_cols;
        if(n%2 == 0) center_rows = 2;
        else center_rows =1;
        if(m%2 == 0) center_cols = 2;
        else center_cols =1;
        vector<int> res_vec;
        int phase = 1;
        int index = 1;
        int ron= center_rows, con=center_cols;
        for(int k= 0; k < m*n; k++ ) {
            if(phase == 1) {
                if (k >= center_cols * center_rows) {
                    res++;
                    phase = 2;
                }
            }
            else if(phase == 2){
                if(index == center_cols*2 + center_rows*2){
                    index = 0;
                    phase = 4;
                    res++;
                }
                index++;
            }
            else if(phase == 3){
                if(index == 4){
                    index = 0;
                    phase = 2;
                    res++;
                    if(con == m){
                        con = 0;
                    }
                    if(ron == n){
                        ron = 0;
                    }
                }
                index++;
            }
            else if(phase == 4){
                if(k >= ron*con + 2*ron + 2*con){
                    if(ron != 0)
                        ron += 2;
                    if(con != 0)
                        con += 2;
                    phase = 3;
                    index = 1;
                }
                else if(index == 8){
                    index = 0;
                    res++;
                }
                index++;
            }
            res_vec.push_back(res);

        }
        results.push_back(res_vec);
    }
    for(int i = 0; i < results.size(); i++){
        for(int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}


