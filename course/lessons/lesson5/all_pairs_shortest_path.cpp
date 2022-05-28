#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>
#include <math.h>
#include <set>
#include <queue>
#include <limits.h>

using namespace std;
//O(n^3)

vector<vector<int>> r;
void floyd_warchal(){
    int n,m;
    int u,v,w;

    cin >> n>>m;
    r=vector<vector<int>>(n);
    for(int i=0;i<n;i++){
        r[i]=vector<int>(n,INT_MAX);
    }
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        r[u][v]=w;
    }
    for(int i=0;i<n;i++){
        r[i][i]=0;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                r[i][j]=min(r[i][j] , r[i][k]+r[k][j]);
            }
        }
        

    }
    //negative cycle iff exist i s.t r[i][i]<0
    //return val for specific source and target:

    int source,target;
    cin>>source>>target;

    if(r[source][target] ==INT_MAX)
        cout<< "infinity"; // no path
    for(int k=0; k<n; k++) {
        if(r[k][k]<0 && r[source][k]<INT_MAX && r[k][target]<INT_MAX){
            cout<< "-infinity"; // not well defined
        }
    }
    cout<< r[source][target];
}

int main(){
    floyd_warchal();
    return 0;
}