//
// Created by Gili on 03/01/2022.
//

#include <stdlib.h>

long long ComputeHash(string const &s)
{
    //for string "abc" the hash returned wil be:
    // a * p^2 + b * p^1 + c * p^0 = 1 * p^2 + 2 * p^1 + 3 * p^0

    const int p = 31; //p should be number of letters in pur abc
    const int m = 1e9 + 9; //m should b large prime number
    long long hash_value = 0;
    long long p_pow = 1;

    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}



//hasing Algorithm – Linear Time hasing O(n)
class smartHash {
public:
    // for double polynomial hash do:
    //const int M1 = 1e9 + 7, M2 = 988244353;
    //H1 = rand() % 1000 + 5; H2 = rand() % 1000 + 5;
    // and use two different hashes,
    //check (h1(s1)=h1(s2) && h2(s1)=h2(s2))

    //needs srand(12323); in main.
    const int p = rand() % 1000;
    const int m = 1e9 + 7;
    int max_size;
    vector<ll> p_pow;

    smartHash(int max_size) : max_size(max_size) {
        p_pow = vector<ll>(max_size);
        p_pow[0] = 1;
        for(int i=1;i<max_size;i++) {
            p_pow[i] = (p_pow[i - 1] * p) % m;
        }
    }
    //"abc" - > (a*p^2 + b*p + c) % m
    ll computeHash(const string& s) {
        ll hash_value = 0;
        int n=s.size();
        for(int i=0;i<n;i++) {
            char c = s[i];
            hash_value = (hash_value + (c - 'a' + 1) * p_pow[n-i-1]) % m;
        }
        return hash_value;
    }

    //compute hash of window using prefix hash
    //[s,e]
    ll computeHash(vector<ll>& h, int s, int e) {
        int len=e-s+1;
        ll promoted_s= (h[s] * p_pow[len]) % m;
        ll hash_value = (h[e + 1] + m - promoted_s) % m;
        return hash_value;
    }

    //com[ute prefix hash:
    //"abc" - >{0, a, a*p + b ,a*p^2 + b*p + c }
    vector<ll> substringHashes(const string& s) {
        int n = s.size();
        vector<ll> h(n + 1, 0);

        for(int i=0;i<n;i++) {
            h[i + 1] = (h[i] * p + (s[i] - 'a' + 1)) % m;
        }
        //{0,h(s0),h(s0s1),h(s0s1s2),..,h(s)}
        return h;
    }
};