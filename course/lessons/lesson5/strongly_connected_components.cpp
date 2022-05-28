#include <iostream>
#include <vector>
#include<string>
#include<iterator>
#include<set>
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1024;

vector<int> g[MAXN];// רשימת שכנויות
int d[MAXN], low[MAXN], scc[MAXN]; //scc is the result of the function
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;

void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = g[u];
    for (int k=0, m=out.size(); k<m; ++k){
        const int &v = out[k];
        if (d[v] == -1){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if (stacked[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if (d[u] == low[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            stacked[v] = false;
            scc[v] = current_scc;
        }while (u != v);

        current_scc++;
    }
}

int main(){
    for(int i=0;i<MAXN;i++){
        d[i]=-1;
    }
    //מכניסים לגרף g את רשימת השכונויות
    //קוראים לטרגן מכל צומת של הגרף אם הוא עוד לא דיסקוברד. כלומר אם די שווה למינוס 1
    return 0;
    
}
