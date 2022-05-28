//
// Created by Yuval on 1/24/2022.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace  std;
int main() {
    int n;
    cin >> n;
    vector<int> next_student = vector<int>(n);
    vector<int> checked = vector<int>(n, -1);
    for(int i=0; i<n; i++) {
        int p;
        cin >> p;
        next_student[i] = p - 1;
    }
    for(int i=0; i<n; i++) {
        if(checked[i] != -1) continue;
        checked[i] = -3;
        int next = next_student[i];
        while(checked[next] == -1){
            checked[next] = -3;
            next = next_student[next];
        }
        int start_of = next;
        if(checked[next] == -3){
            while(checked[next] == -3){
                checked[next] = next;
                next = next_student[next];
            }
        }
        next = i;
        while(checked[next] == -3){
            checked[next] = checked[start_of];
            next = next_student[next];
        }
    }
    for(int i = 0; i< checked.size(); i++){
        cout << checked[i]+1 << " ";
    }
    cout << endl;
    return 0;
}

