
//max group of esges that not touching each other
//In a bipartite graph, the number of edges in maximum matching is equal to the number of vertices in a minimum vertex cover.



// This code performs maximum bipartite matching.
//
// Running time: O(|E| |V|) -- often much faster in practice
//
// INPUT: w[i][j] = edge between row node i and column node j
// OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
// mc[j] = assignment for column node j, -1 if unassigned
// function returns number of matches made

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
        if (w[i][j] && !seen[j]) {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}
int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
    mr = VI(w.size(), -1);//אל מי הצומת האיי מזווג. מינוס 1 אם אין זיווג
    mc = VI(w[0].size(), -1);
    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen))
            ct++;
    }
    return ct;
}

int main(){
    int row_nodes,column_nodes;
    int m;//num of edges;
    int u,v;
    cin>>row_nodes>>column_nodes;
    VVI g=VVI(row_nodes);
    for(int i=0;i<row_nodes;i++){
        g[i]=VI(column_nodes,0);
        
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;
    }

    VI mr;
    VI mc;

    int count;
    count=BipartiteMatching(g,mr,mc);
    cout<<"number of matches made: "<<count;


}
