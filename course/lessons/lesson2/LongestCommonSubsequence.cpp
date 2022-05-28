//
// Created by Gili on 04/01/2022.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//O(nm)
int LongestCommonSubsequence(string s1, string s2)
{
    int lenS1 = s1.size();
    int lenS2 = s2.size();
    vector<vector<int>> m (lenS1 + 2, vector<int> (lenS2 + 2, 0));

    for (int i = lenS1; i >= 0; i--)
    {
        for (int j = lenS2; j >= 0; j--)
        {
            if (i == lenS1 || j == lenS2)
            {
                //represent empty suffix for ine of the strings
                m[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j])
            {
                //if the current element is equal
                // take the longest common subsequence starting at i+1/j+1 and concatenate the firs element
                m[i][j] = 1 + m[i+1][j+1];
            } else {
                // take the maximum with taking only one between i/j
                m[i][j] = max(m[i][j+1], m[i+1][j]);
            }
        }
    }
    return m[0][0];
}

/* Driver code */
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout<<"Length of LCS is "<< LongestCommonSubsequence(X, Y) ;

    return 0;
}
