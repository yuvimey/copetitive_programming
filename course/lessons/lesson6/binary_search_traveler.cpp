/**
A traveler with budget πΊ wants to buy souvenirs. There are π items.
The cost of the πβth item is ππ
.
If the traveler buys π items with indices π₯1, β¦ , π₯π, then the cost of item π₯π
is ππ₯π + π₯π
β π, for every 1 β€ π β€ π.
The traveler wants to maximize the number of different souvenirs he buys.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int n, S;
int a[N];
ll b[N];

ll res(int k)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] + (i + 1) * (ll) k;
    }
    sort(b, b + n);
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += b[i];
    }
    return ans;
}

class Main
{
public:
    void solve(istream &in, ostream &out)
    {
        in >> n >> S;
        for (int i = 0; i < n; i++)
        {
            in >> a[i];
        }
        int l = 0, r = n + 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (res(m) <= S)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        out << l << ' ' << res(l) << '\n';
    }
};


//input:
//n S
//a_1 a_2 ... a_n

// output
//


int main()
{
    ios::sync_with_stdio(0);
    Main solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}