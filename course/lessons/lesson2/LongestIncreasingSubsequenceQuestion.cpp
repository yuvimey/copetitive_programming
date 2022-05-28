//
// Created by Gili on 04/01/2022.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

//O(n*log(n))
int longestIncreasingSubsequence1(vector<int> arr)
{
    //at index j we will save the smallest element that
    // end a subsequence at len j

    set<int> st;
    set<int>::iterator it;

    int n = arr.size();

    st.clear();
    for (int i = 0; i < n; i++)
    {
        // insert arr[i] into a binary tree
        st.insert(arr[i]);
        //perform search on binary tree - O(log n)
        it = st.find(arr[i]);
        //check if arr[i] is the last element in the tree
        it++;
        if (it != st.end())
        {
            // if arr[i] was inserted in the middle of the tree, remove its ancestor
            st.erase(it);
        }
    }
    return st.size();
}

//O(n^2)
int longestIncreasingSubsequence2(vector<int> arr)
{
    int n = arr.size();
    // longest[i] will hold the length of the longest
    //increasing subsequence, q, of set[i,...,n-1]
    // s.t. s[i] is the first element of q
    vector<int> longest (n + 1, 0);

    for( int i = n-1; i >=0; i--)
    {
        //each subsequence starting at s[i] is at least 's[i]' -> at least of len 1
        longest[i] = 1;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[i])
            {
                //check if taking the longest subsequence starting at s[j] and concatenating
                // s[i] in the first index will give as a longer subsequence starting at s[i] then currently found
                longest[i] = max(longest[i], longest[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, longest[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout <<"Length of lis1 is "<< longestIncreasingSubsequence1(arr);
    cout <<"Length of lis2 is "<< longestIncreasingSubsequence2(arr);
    return 0;
}