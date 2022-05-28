//
// Created by Gili on 04/01/2022.
//

#include <vector>

using namespace std;

//Problem: Given an array with n positive and negative numbers, find the subarray with one or more
// consecutive numbers where the sum of the subarray is maximum.

//naive solution is in O(n^3) time  - check all possible sub arrays - there are O(n^2) - for each one of the calc its sum
//O(n^2) sol - compute all partial sum (meaning s[i] is the sum of elements from 0 to i and loop over s[i]-s[j]

//O(n) sol - m[i] will be the maximum sum of any subsequence that ends at element arr[i]
int MaxSumOnAline(vector<int> arr)
{
    int n = arr.size();
    vector<int> m (n, 0);

    //subsequence ending at arr[0] must be of len 1
    m[0] = 1;

    for (int i = 1; i < n; i++)
    {
        m[i] = max(arr[i], m[i-1]+arr[i]);
    }

    return m[n-1];
}