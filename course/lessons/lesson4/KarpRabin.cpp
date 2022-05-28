//
// Created by Gili on 03/01/2022.
//

#include <vector>
#include <string>

using namespace std;

vector<int> KarpRabin(string const & s, string const & t)
{
    const int p = 31; //// p should be number of letters in language
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); //p_pow hold all powers we use during hash calculation
    p_pow[0] = 1; //first power is 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
    {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    //calc hash values of prefix from 0 to i, will be used to calc hash of window
    //Notice the first hash is 0 representing hash of empty string
    vector<long long> h(T+1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }

    //calculate hash value of s
    long long h_s = 0;
    for (int i = 0; i < s; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * p+pow[i]) % m;
    }

    // calculating hash values of segments/window using hash values of prefix
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        //calculating hash value of current window
        //Notice +m is added in order to fix result of modulo to be positive
        long long cur_h = (h[i+S] + m - h[i]) % m;
        //the hash of the window is multiplied by a power of p
        // hence tha hash of p is being multiplied in the same power of p
        if (cur_h == h_s * p_pow[i] % m)
        {
            occurrences.push_back(i);
        }
        return occurrences;
    }
}