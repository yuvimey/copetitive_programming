// A C++ program to print topological
// sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;


//------------------------------------------------------------------

int n,m;
Graph g(1024);
int flag, visible[1024];
int od[1024]; // the final order
int p; //position
list<int>::iterator i;
void dfs(int a) {
    if(visible[a]==1) 
        flag = 1;
    if(visible[a]) 
        return;
    visible[a] = 1; // gray
    for ( i = g.adj[a].begin(); i != g.adj[a].end(); ++i){
        dfs(*i);
    }
    visible[a] = 2; // black
    od[p] = a; p--;
}

int main(){
    cin>>n>>m;
    
    int v,u;
    for(int i=0;i<m;i++){
        cin>>v>>u;
        g.addEdge(v,u);
    }
    for(int i=0; i<n; i++) visible[i]=0; //white
    flag=0; p=n-1;
    for(int i=0; i<n; i++) 
        if(!visible[i])
            dfs(i);
    if(flag)   
        cout<<"there is a cycle";

}