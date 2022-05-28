#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <vector>
#include <set>
#include <list>

// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN   10000001

// stores smallest prime factor for every number
int spf[MAXN];

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
int getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        int y = spf[x];
        int y_tmp = y;
        while( x % y == 0){
            if ( y == x) return y;
            y = y*y_tmp;
        }
        return (int)y/y_tmp;

    }
    return -1;
}



int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> div1_arr(n,0);
    vector<int> div2_arr(n,0);
  //  cout << "well "<< endl;
   sieve((int)*max_element(a.begin(), a.end())+1);
   //sieve(MAXN);
  //  cout << "weell "<< endl;
    for (int i = 0; i < n; i++) {
     //   cout << "weeelly "<< i << endl;
        int div1 = getFactorization(a[i]);
      //  cout << "weeellyy " << i << endl;
     //   cout << "div1 =  " << div1 << endl;
        if(div1 == 0 || div1 == a[i] || div1 == 1 || div1== -1){
            div1_arr[i] = -1;
            div2_arr[i] = -1;
        }
        else{
            div1_arr[i] = div1;
            div2_arr[i] = (int) a[i]/div1;
        }
     //   cout << "weeellyyy " << i << endl;
    }
   // cout << "weeell "<< endl;
    cout << endl;
    for(int j = 0; j < n; j++){
        cout << div1_arr[j] << " ";
    }
    cout << endl;
    for(int j = 0; j < n; j++){
        cout << div2_arr[j] << " ";
    }
    cout << endl;
}