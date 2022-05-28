#include <vector>
#include <iostream>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

// Bipartite Matching algorithm from the lecture.
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

int main() {
    int C;
    vector<int> res;
    cin >> C;
    for (int i = 0; i < C; i++) {
        int next_key = 0;
        int X, Y;
        cin >> X >> Y;
        int P, W;
        vector<vector<int>> mat = vector<vector<int>>(X, vector<int>(Y, 0));
        vector<vector<int>> row_keys = vector<vector<int>>(X, vector<int>(Y, 0));
        vector<vector<int>> col_keys = vector<vector<int>>(X, vector<int>(Y, 0));
        cin >> P;
        for (int j = 0; j < P; j++) { // getting input
            int x, y;
            cin >> x >> y;
            mat[x - 1][y - 1] = 1;
        }
        cin >> W;
        for (int j = 0; j < W; j++) {
            int x, y;
            cin >> x >> y;
            mat[x - 1][y - 1] = 2;
        }
        int key = 0;
        int sentry_set;
        for (int r = 0; r < X; r++) { //setting a specific key to the points that
            sentry_set = 0;           //can be guarded by the same sentry along the column. (col sentry key)
            for (int c = 0; c < Y; c++) {
                if (mat[r][c] == 1) {
                    col_keys[r][c] = key;
                    sentry_set = 1;
                }
                if (mat[r][c] == 2) {
                    if (sentry_set != 0) {
                        sentry_set = 0;
                        key++;
                    }
                }
            }
            if (sentry_set != 0) {
                key++;
            }
        }
        for (int c = 0; c < Y; c++) { //setting a specific key to the points that
            sentry_set = 0;           //can be guarded by the same sentry along the row. (row sentry key)
            for (int r = 0; r < X; r++) {
                if (mat[r][c] == 1) {
                    row_keys[r][c] = key;
                    sentry_set = 1;
                }
                if (mat[r][c] == 2) {
                    if (sentry_set != 0) {
                        sentry_set = 0;
                        key++;
                    }
                }
            }
            if (sentry_set != 0) {
                key++;
            }
        }
        VVI edges = VVI(key, VI(key, 0));
        for (int c = 0; c < Y; c++) {
            for (int r = 0; r < X; r++) {
                if (mat[r][c] == 1) {
                    edges[row_keys[r][c]][col_keys[r][c]] = 1; //setting an edge between a row sentry key and a col sentry
                }                                              //key if they are guarding the same point.
            }
        }
        VI mr, mc;
        int result = BipartiteMatching(edges, mr, mc); //in this case of bipartite matching, if an edge is satiated
        res.push_back(result);                               //then there is an overlap a point between the two sentries
                                                            //(row and col) that suggest that you can use only one of the sentries.
                                                            // the algorithm finds the maximal overlap and there for the minimal
                                                            // amount of sentries needed.
    }
    for(int i = 0; i < C; i++){
        cout << res[i] << endl;
    }
    return 0;
}