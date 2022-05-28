

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

// Min Cost Max Flow taken from the lectures.
struct MinCostMaxFlow {
    int N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;

    MinCostMaxFlow(int N) :
            N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
            found(N), dist(N), pi(N), width(N), dad(N) {}

    void AddEdge(int from, int to, L cap, L cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(int s, int k, L cap, L cost, int dir) {
        L val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k]) {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }

    L Dijkstra(int s, int t) {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;

        while (s != -1) {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++) {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }

        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }

    pair<L, L> GetMaxFlow(int s, int t) {
        L totflow = 0, totcost = 0;
        while (L amt = Dijkstra(s, t)) {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first) {
                if (dad[x].second == 1) {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                } else {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    L r, c;
    cin >> r >> c;
    VVL mat1(r, VL(c));
    VVL mat2(c, VL(r));
    L zero_count = 0;
    L sum_all = 0;
    for (int i = 0; i < r; i++) { //getting input
        for (int j = 0; j < c; j++) {
            cin >> mat1[i][j];
            mat2[j][i] = mat1[i][j];
            if(mat1[i][j] == 0){ // counting zeroes
                zero_count++;
            }
            sum_all += mat1[i][j];
        }
    }

    VL rows(r);
    VL cols(c);
    for (int i = 0; i < r; i++) {
        rows[i] = *max_element(mat1[i].begin(), mat1[i].end()); //logging the tallest pile for each row.
    }
    for (int i = 0; i < c; i++) {
        cols[i] = *max_element(mat2[i].begin(), mat2[i].end()); //logging the lallest pile for each column.
    }

    L N;
    N = r + c + 2;
    MinCostMaxFlow mcmf(N); // creating a graph
    L sum = 0;
    L count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(rows[i] == cols[j] && mat1[i][j] != 0){
                mcmf.AddEdge(i, r + j, rows[i], 0); //adding edge between row and column if their tallest pile is the same height
            }                                               // the edge weight is the height of the pile.
        }
    }
    for(int i = 0; i < r; i++){
        mcmf.AddEdge(N-2, i, rows[i], 0);         //adding edge from source to each row.
    }
    for(int i = 0; i < c; i++){
       // mcmf.AddEdge(N-1, r + i, cols[i], 0);
        mcmf.AddEdge(r + i, N-1, cols[i], 0);   // adding edge from each column to destination.
    }


    mcmf.GetMaxFlow(N-2, N-1);      //running the max flow algorithm.
                                        //The max flow algorithm guarantees maximal matching of rows to columns
                                        //with priority for matching rows and columns with taller max height piles.


     // sum_all - the crates that are initially in the warehouse.
    // sum - the crates that are left in the warehouse after the heist.
    for(int i=r; i < r + c; i++){
        if(cols[i-r] != 0) count += 1;
        sum += cols[i-r]; // add up all the max heights of each column.
    }
    for(int i=0; i < r; i++){
        if(mcmf.flow[N-2][i] == 0){ // if there is no flow to a row from the source then there is no matching with column
            if(rows[i] != 0) count += 1; // meaning there are separate piles for the row and for the column.
            sum += rows[i]; // therefore the max of row needs to be added to the sum.
        }
    }
    sum += (r*c - count - zero_count); //all the piles that are not empty and are not the max pile are assigned 1.
    L return_val = sum_all - sum;

    cout << return_val << endl;

    return 0;
}

// END CUT