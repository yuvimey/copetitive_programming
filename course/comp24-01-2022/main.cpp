#include <iostream>
#include <bits/stdc++.h>

using namespace  std;
int main() {
    int nodes_len;
    int edges_len;
    int node1;
    int node2;
    cin >> nodes_len >> edges_len;
    vector<vector<int>> edges = vector<vector<int>>(nodes_len);
    vector<int> edges_size = vector<int>(nodes_len, 0);
    for(int i=0; i<edges_len; i++) {
        cin >> node1 >> node2;
        node1--;
        node2--;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
        edges_size[node1]++;
        edges_size[node2]++;
    }
    int min_size= *min_element(edges_size.begin(), edges_size.end());
    int max_size = *max_element(edges_size.begin(), edges_size.end());
    if(max_size == edges_len && max_size == nodes_len-1){
        cout << "star topology" << endl;
        return 0;
    }
    if(max_size == 2 && min_size == 2){
        cout << "ring topology" << endl;
        return 0;
    }
    if(max_size == 2 && min_size == 1){
        cout << "bus topology" << endl;
        return 0;
    }
    cout << "unknown topology" << endl;
    return 0;
}
