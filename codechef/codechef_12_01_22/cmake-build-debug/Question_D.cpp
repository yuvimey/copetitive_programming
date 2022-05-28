
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
    vector<int> n_arr;
    vector<int> m_arr;
    for(int i = 0; i <t; i++ ){
        int m, n;
        cin >> m >> n;
        n_arr.push_back(n);
        m_arr.push_back(m);
    }
    for(int i = 0; i <t; i++ ){
        int m = m_arr[i];
        for(int j = 0; j < n_arr[i]; j++){
            if(j > m-1){

            }
            int val = j*m;
            int res = int((j*m_arr[i]-1)+(j-(j*(j-1)/2))/m_arr[i]);
            cout << res << " ";
        }
        cout << endl;
    }

    return 0;
}


