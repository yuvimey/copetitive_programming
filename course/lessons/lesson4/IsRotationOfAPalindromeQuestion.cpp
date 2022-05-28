//
// Created by Gili on 04/01/2022.
//

// a simple solution is to concatenate the string to itself and
//to check for every index if the next window of len n is a palindorme
//this sol is O(n^2)

//sol in O(n) using manachers algorithm for longest substring

#include <bits/stdc++.h>
using namespace std;

// Function to check if we have found
// a palindrome of same length as the input
// which is a rotation of the input string
bool checkPal(int x, int len)
{
    if (x == len)
        return true;
    else if (x > len) {
        if ((x % 2 == 0 && len % 2 == 0)
            || (x % 2 != 0 && len % 2 != 0))
            return true;
    }
    return false;
}

// Function to find the longest palindromic
// substring using Manacher's Algorithm
bool longestPal(string s, int len)
{
    string Q = convertToNewString(s);
    vector<int> P(Q.size(),0);
    int c = 0, r = 0;   // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        // If currentRightPosition i is
        // within centerRightPosition R
        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // Attempt to expand palindrome centered
        // at currentRightPosition i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        //// added code to manchares algorithm to find if s is rotation of palindrome
        // Check for palindrome
        bool ans = checkPal(P[i], len);
        if (ans) {
            return true;
        }

        // If palindrome centered at currentRightPosition i
        // expand beyond centerRightPosition R,
        // adjust centerPosition C based on expanded palindrome
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    return false;
}

// Driver code
//int main()
//{
//    string s = "aaaad";
//    int len = s.size();
//    s += s;
//    s = reform(s);
//    cout << longestPal(s, len);
//
//    return 0;
//}