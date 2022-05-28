#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
 
typedef long long ll;
using namespace std;
const int INF=100000000;
typedef pair<int, int> PII;
int n,m;
vector<vector<pair<int, int>>> wg; //adjacency list
vector<int> dist;
vector<int> dad;
void fast_dijkstra(vector<int>& sources)
{
    dist=vector<int>(n,INF);
    dad=vector<int>(n, -1);
    //use priority queue in which top element has the "smallest" priority (min-heap)
    priority_queue<PII, vector<PII>, greater<PII> > Q;
   
    for (int s:sources)
    {
         Q.push(make_pair(0, s)); dist[s] = 0;
    }
    while (!Q.empty()) {
        PII p = Q.top();
        Q.pop(); 
        int here = p.second;
        if (dist[here] != p.first) continue;// we just left it in Q until now instead of delete when we updated dist[here].
        for (auto it : wg[here]) {
            int it_index=it.first;
            int it_w=it.second;
            if (dist[here] + it_w < dist[it_index]) { 
                dist[it_index] = dist[here] + it_w;
                dad[it_index] = here;
                Q.push(make_pair(dist[it_index], it_index));
            }
        }
       
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    wg=vector<vector<pair<int, int>>> (n);
    
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        wg[x].push_back({y,w});
    }
    vector<int> sources={0};
    fast_dijkstra(sources);
    for(int i=0;i<n;i++)
    {
        cout<<"The dist to vertex: "<<i<<" is ";
        if(dist[i]!=INF)
            cout<<dist[i];
        else
            cout<<"INF";
        cout<<endl;
    }
}