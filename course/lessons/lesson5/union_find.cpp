#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <list>
#include <bits/stdc++.h>
#include <tuple>
#include <set>
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
    int N=10;
    int M=10;
    int i;
    int u,v;

    dsu uf(N);
    for(i=0;i<M;i++){
        cin>>u>>v;
        uf.union_(u,v);
    }

    //are two vertex connected?
    if(uf.find_(u)==uf.find_(v))
        cout<<"the vertex are connected";
    else        
        cout<<"the vertex are not connected";
    return 0;
}