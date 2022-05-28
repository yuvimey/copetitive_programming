#include <iostream>
#include <vector>
#include<string>
#include<iterator>
#include<set>
#include <bits/stdc++.h>
using namespace std;

void main(){
    int n;
    vector<vector<int>> adj;

    vector<int> side(n, -1);//בסוף כל קודקוד יקבל מספר צד- 1 או 0 בתנאי שהגרף דו צדדי
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;//xor
                        q.push(u);
                    } 
                    else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    cout << (is_bipartite ? "YES" : "NO") << endl;

}
