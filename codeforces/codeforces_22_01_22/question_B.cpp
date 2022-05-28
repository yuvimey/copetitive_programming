// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;


// stores smallest prime factor for every number
vector<int> spf;

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve(int n)
{
    spf[1] = 1;
    for (int i=2; i<n; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<n; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<n; i+=2)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<n; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    vector<string> results;
    vector<int> l_arr;
    vector<int> r_arr;
    vector<int> k_arr;
    int max_r;
    for(int i = 0; i <t; i++ ){
        int l, r ,k;
        cin >> l >> r >> k;
        l_arr.push_back(l);
        r_arr.push_back(r);
        k_arr.push_back(k);
        if(max_r < r) max_r = r;
    }
    spf = vector<int>(max_r+ 1, 0);
    sieve(max_r+ 1);
    for(int i = 0; i <t; i++ ){
        int l = l_arr[i];
        int r = r_arr[i];
        int k = k_arr[i];
        map<int,int> m;
        int max = 0;
        int max_val = 1;
        for(int j = l; j < r+1; j++ ){
            vector<int> tmp = getFactorization(j);
            set<int> s = {};
            for(int q = 0; q < tmp.size(); q++){
                if(s.count(tmp[q]) != 0) continue;
                if(m.count(tmp[q]) == 0) m[tmp[q]] = 0;
                m[tmp[q]]++;
                if( m[tmp[q]] > max && tmp[q] != 1) {
                    max = m[tmp[q]];
                    max_val = tmp[q];
                }
                s.insert(tmp[q]);
            }
        }
        if(r-l+1 - max > k || max_val == 1) results.push_back("NO");
        else results.push_back("YES");

    }
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
