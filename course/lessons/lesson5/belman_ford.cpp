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
// A C++ program for Bellman-Ford's single source

//--------------------------------------------------------------------------------------------
//O(mn)
const int MAXVAL=1024;
int d[MAXVAL];
void belman_ford(){
    int n,m;
    int u,v,w;
    pair<int,int> help;
    vector<vector<pair<int,int>>> adj;

    cin >> n>>m;

    adj=vector<vector<pair<int,int>>>(n);

    for(int i=0;i<MAXVAL;i++){
        d[i] = INT_MAX; 
    }

    d[0] = 0;

    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        help=make_pair(v,w);
        adj[u].push_back(help);


    }

    int change=0;
    for(int i=0; i<=n-1; i++) { //n iterations. the last iter is for check if there is a cycle
        change=0;
        for (pair<int,int> edge:adj[i]){
            if(d[edge.first] >d[i]+edge.second){
                d [edge.first]=d[i]+edge.second;
                change=1;
            }
        }
    }
    if(change){
        //there is a cycle
    }


}


int main(){
    belman_ford();
    return 0;
}

