#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
 
 
using namespace std;
//DSU
struct dsu
{
    vector<int> parent;
    vector<int> sz;
    
    dsu(int n)
    {
        parent=vector<int>(n);
        for(int i=0;i<n;i++)parent[i]=i;
        sz=vector<int>(n,1);
    }
    
    int find_(int x)
    {
        int root=x;
        while(root!=parent[root])
            root=parent[root];
        
        //Path compression
        while(parent[x]!=root)
        {
            int p=parent[x];
            parent[x]=root;
            x=p;
        }
        return root;
    }
    bool union_(int x,int y)
    {
        int X=find_(x);
        int Y=find_(y);
        // x and y are already in the same set
        if(X==Y)
            return false;
        // x and y are not in same set, so we merge them
        if(sz[X]<sz[Y])
            swap(X, Y);
        // merge yRoot into xRoot
        parent[Y]=X;
        sz[X]+=sz[Y];
        return true;
    }
};
 
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> edges(m);//array of all edges in a graph
    for(int i=0;i<m;i++)
    {
        int w,x,y;
        cin>>w>>x>>y;
        edges[i]={w,{x,y}};
    }
    sort(edges.begin(), edges.end());
    dsu uf(n);
    int mst_w=0;
    for(auto e:edges)
    {
        int w=e.first;
        int x=e.second.first;
        int y=e.second.second;
        if(uf.find_(x)==uf.find_(y))
            continue;
        //else-(x,y) is an edge that belongs to a minimum spanning tree
        mst_w+=w;
        uf.union_(x,y);
    }
    cout<<mst_w;
    return 0;
}