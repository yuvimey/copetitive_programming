#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using  namespace std;
vector<bool> is_collider_on;

map<int, set<int>> factor_map;


// stores smallest prime factor for every number
vector<int> spf;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

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

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n ,m;
    cin >> n >> m;
    is_collider_on = vector<bool>(n, false);
    spf = vector<int>(n+3);
    sieve(n+3);
    string pm;
    vector<string> res;
    int coll_num;
    for(int i=0; i<m; i++){
        cin >> pm >> coll_num;
        coll_num = coll_num - 1;
        if( pm == "-" && !is_collider_on[coll_num]){
            res.push_back("Already off");
            continue;
        }
        if(pm == "+" && is_collider_on[coll_num]){
            res.push_back("Already on");
            continue;
        }
        bool conflict = false;
        int conflicted_fac = 1;
        set<int> prime_fac = getFactorization(coll_num+1);
        if( pm == "-"){
            is_collider_on[coll_num] = false;
            for(auto it = prime_fac.begin(); it != prime_fac.end() ; it++){
                if(factor_map.count(*it) == 0){
                    factor_map[*it] = set<int>();
                }
                factor_map[*it].erase(coll_num+1);
            }
            res.push_back("Success");
            continue;
        }
        for(auto it = prime_fac.begin(); it != prime_fac.end() ; it++){
            if(factor_map.count(*it) != 0 && factor_map[*it].size() != 0){
                conflict = true;
                conflicted_fac = *it;
                break;
            }
        }
        if(conflict){
            int conflicted_coll;
            conflicted_coll = *factor_map[conflicted_fac].begin();
            res.push_back("Conflict with " + to_string(conflicted_coll));
            continue;
        }
        is_collider_on[coll_num] = true;
        for(auto it = prime_fac.begin(); it != prime_fac.end() ; it++){
            if(factor_map.count(*it) == 0){
                factor_map[*it] = set<int>();
            }
            factor_map[*it].insert(coll_num+1);
        }
        res.push_back("Success");
    }

    for(int i=0; i<m; i++){
        cout << res[i] << endl;
    }

    return 0;
}
