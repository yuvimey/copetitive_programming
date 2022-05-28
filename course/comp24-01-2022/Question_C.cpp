//
// Created by Yuval on 1/24/2022.
//
//
// Created by Yuval on 1/24/2022.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace  std;

struct dsu
{
    vector<int> parent;
    vector<int> sz;
    vector<int> min_gold;

    dsu(int n, vector<int> v)
    {
        parent=vector<int>(n);
        for(int i=0;i<n;i++)parent[i]=i;
        sz=vector<int>(n,1);
        min_gold = v;
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
        if(min_gold[X] > min_gold[Y]){
            min_gold[X] = min_gold[Y];
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> gold = vector<int>(n);
    for(int i=0; i<n; i++) {
        int g;
        cin >> g;
        gold[i] = g;
    }
    dsu uf(n, gold);
    for(int i=0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        uf.union_(x-1,y-1);
    }
    long long sum = 0;
    set<int> used_parents = {};
    for(int i = 0; i < n; i++){
        int X = uf.find_(i);
        if(used_parents.count(X) != 0) continue;
        sum += (long long)uf.min_gold[X];
        used_parents.insert(X);
    }
    cout << sum << endl;
    return 0;
}


