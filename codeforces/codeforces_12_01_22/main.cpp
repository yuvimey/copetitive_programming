#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> results;
    for(int i = 0; i <t; i++ ){
        int n, l;
        cin >> n >> l;
        vector<int> count = vector<int>(l, 0);
        for(int j = 0; j<n; j++){
            int word;
            cin >> word;
            for(int k = 0; k<l; k++){
                int x = word%2;
                if(x == 1){
                    count[k] += 1;
                }
                word = word/2;
            }
        }
        int res = 0;
        for(int j = 0; j<l; j++){
            if(count[j] > n/2){
                res += pow(2,j);
            }
        }
        results.push_back(res);
    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
