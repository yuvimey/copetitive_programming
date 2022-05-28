//
// Created by Gili on 04/01/2022.
//
#include "String_Utils.cpp"

//longest palindrome sub string:
// naive O(n^3)
// 1 - using manacher's algorithm, O(n) time', O(1) space
// 2 - dynamic programing O(n^2) time & O(1) space
// 3 - dynamic programing O(n^2) time & o(n^2) space



//using manacher's algorithm, O(n) time', O(1) space
int longestPalindromeSubstring1() {
    string Q = convertToNewString(s);
    vector<int> P(Q.size(),0);
    int c = 0, r = 0;   // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            {
                maxPalindrome = P[i];
                centerIndex = i;
            }
        }
    }
    //indexs: 012345678910
    //Q:      @#a#b#a#a#$
    //P:      00103012100
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);

}


// dynamic programing O(n^2) time & O(1) space
int longestPalindromeSubstring2(char *str)
{
    // This function prints the longest palindrome substring (LPS)
    // of str[]. It also returns the length of the longest palindrome

    int maxLength = 1; // The result (length of LPS)

    int start = 0;
    int len = strlen(str);

    int low, high;

    // One by one consider every character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome
        // with center points as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        // Find the longest odd length palindrome with center
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }

    cout<<"Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}

// dynamic programing O(n^2) time & o(n^2) space
int longestPalindromeSubstring3(string str)
{
    // get length of input string
    int n = str.size();

    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1 are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr( str, start, start + maxLength - 1 );

    // return length of LPS
    return maxLength;
}
