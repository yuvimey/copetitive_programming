// This code performs maximum bipartite matching.
//
// Running time: O(|E| |V|) -- often much faster in practice
//
// INPUT: w[i][j] = edge between row node i and column node j
// OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
// mc[j] = assignment for column node j, -1 if unassigned
// function returns number of matches made
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
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
    mr = VI(w.size(), -1);
    mc = VI(w[0].size(), -1);
    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

// BEGIN CUT
// The following code solves SPOJ problem #4110: Fast Maximum Flow (FASTFLOW)
using namespace std;
int main() {
    int C;
    vector<int> res;
    cin >> C;
    for(int i = 0; i < C; i++) {
        int next_key = 0;
        int X, Y;
        cin >> X >> Y;
        int P, W;
        vector<vector<int>> mat = vector<vector<int>>(X, vector<int>(Y,0));
        cin >> P;
        for (int j = 0; j < P; j++) {
            int x, y;
            cin >> x >> y;
            mat[x-1][y-1] = 1;
        }
        cin >> W;
        for (int j = 0; j < W; j++) {
            int x, y;
            cin >> x >> y;
            mat[x-1][y-1] = 2;
        }
        vector<vector<pair<int,int>>> keys = vector<vector<pair<int,int>>>(X, vector<pair<int,int>>(Y,make_pair(-1,-1)));
        vector<pair<int,int>> first_vertices;
        map<int,int> first_vertices_map;
        int counter = 0;
        for (int r = 0; r < X; r++) {
            for (int c = 0; c < Y; c++) {
                if(mat[r][c] == 1){
                    counter++;
                    keys[r][c].first = key;
                }
                if(mat[r][c] == 2){
                    if(counter != 0) {
                        first_vertices_map[key] = first_vertices.size();
                        first_vertices.push_back(make_pair(key, counter));
                    }
                    counter = 0;
                    key = get_new_key();
                }
            }
            if(counter != 0) {
                first_vertices_map[key] = first_vertices.size();
                first_vertices.push_back(make_pair(key, counter));
                key = get_new_key();
                counter = 0;
            }
        }
        counter = 0;
        key = get_new_key();
        for (int c = 0; c < Y; c++) {
            for (int r = 0; r < X; r++) {
                if(mat[r][c] == 1){
                    counter++;
                    keys[r][c].second = key;
                }
                if(mat[r][c] == 2){
                    if(counter != 0) {
                        first_vertices_map[key] = first_vertices.size();
                        first_vertices.push_back(make_pair(key, counter));
                    }
                    counter = 0;
                    key = get_new_key();
                }
            }
            if(counter != 0) {
                first_vertices_map[key] = first_vertices.size();
                first_vertices.push_back(make_pair(key, counter));
                key = get_new_key();
                counter = 0;
            }
        }
        NUM = 2*next_key;
        int N = NUM+ 3;
        mat.clear();
        MinCostMaxFlow mcmf(N);
        vector<pair<int,int>> first_vertices_in(first_vertices);
        for (int c = 0; c < Y; c++) {
            for (int r = 0; r < X; r++) {
                if(keys[r][c].first != -1){
                    mcmf.AddEdge(keys[r][c].first , get_second_key(keys[r][c].second) , 1, 0);
                    mcmf.AddEdge(keys[r][c].second , get_second_key(keys[r][c].first) , 1, 0);
                    first_vertices_in[first_vertices_map[keys[r][c].first]].second++;
                    first_vertices_in[first_vertices_map[keys[r][c].second]].second++;
                }
            }
        }
        for (int j=0; j < first_vertices.size(); j++) {
            mcmf.AddEdge(NUM + 1, first_vertices[j].first, first_vertices_in[j].second, 1);
            mcmf.sentry_set[first_vertices[j].first] = false;
            mcmf.AddEdge(first_vertices[j].first, get_second_key(first_vertices[j].first), first_vertices[j].second, 0);
            mcmf.AddEdge(get_second_key(first_vertices[j].first), NUM + 2, first_vertices[j].second, 0);

          //  mcmf.brother[first_vertices[j].first] = get_second_key(first_vertices[j].first);
        }

        mcmf.GetMaxFlow(NUM + 1, NUM + 2);
        int result = mcmf.get_cost();
        res.push_back(result);
        second_keys.clear();
    }
    for(int i = 0; i < C; i++){
        cout << res[i] << endl;
    }
    return 0;
}