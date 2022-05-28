//
// Created by Gili on 04/01/2022.
//

//Problem: Given an array and a number K, is there a sub set of arr s.t. the numbers sums to K

#include <vector>

using namespace std;

//original idea O(n^2) time. O(n) space
//Notice in order to use only one row we perfor, the j loop in reverse
// so we won't use the same elements multiple times
bool isSubSetSum1(vector<int> set, int sum)
{
    int n = set.size();

    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    vector<bool> subset (sum + 1, false);

    // If sum is 0, then answer is true
    subset[0] = true;

    // Fill the subset table in bottom up manner
    for (int i = 1; i < n; i++) {
        for (int j = sum; j >= set[i]; j--) {
            subset[j] = subset[j] || subset[j-set[i]];
        }
    }
    return subset[sum];
}

//original idea O(n^2) time. O(n^2) space
//use a 2 dim arr s.t. each row depends on the previous
//// there is a bug:
//bool isSubSetSum2(vector<int> set, int sum)
//{
//    int n = set.size();
//
//    // The value of subset[i][j] will be true if
//    // there is a subset of set[0..j-1] with sum
//    // equal to i
//   vector<vector<bool>> subset (n+1, vector<bool> (sum + 1));
//
//    // If sum is 0, then answer is true
//    for (int i = 0; i <= n; i++)
//        subset[i][0] = true;
//
//    // If sum is not 0 and set is empty,
//    // then answer is false
//    for (int i = 1; i <= sum; i++)
//        subset[0][i] = false;
//
//    // Fill the subset table in bottom up manner
//    for (int i = 1; i <= n; i++) {
//        for (int j = set[i]; j <= sum; j++) {
//            if (j >= set[i - 1])
//                subset[i][j] = subset[i - 1][j]
//                               || subset[i - 1][j - set[i - 1]];
//        }
//    }
//
//    return subset[n][sum];
//}

//the following question is a variation of sub set sum problem:

// divide candies between two, each candy is rated differently
// we want to divide candies as fairs as possible
// we will search for the nearest true to sum/2
void divideCandiesBetweenTwo()
{
    // todo
}

//in this case we will create a two-dimensional array
// s.t. m[b][c] indicates whether or not we can divide candies
//so that b goes to the first kid
//c goes to the second kid
//the rest goes to the third kid

void divideCandiesBetweenThree()
{
    // todo
}

////Notice i did not check this:
//sub set sum problem with using element multiple times
bool isSubSetSumMultipleElements(vector<int> set, int sum)
{
    int n = set.size();

    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    vector<bool> subset (sum + 1, false);

    // If sum is 0, then answer is true
    subset[0] = true;

    // Fill the subset table in bottom up manner
    //loop on j is increasing to allow multiple use of elements
    for (int i = 1; i < n; i++) {
        for (int j = set[i]; j <= sum; j++) {
            subset[j] = subset[j] || subset[j-set[i]];
        }
    }
    return subset[sum];
}

////Notice i did not check this:
//problem: we want to return amount k in minimum number of coins
int CoinChangeProblem(vector<int> coins, int k)
{
    int n = coins.size();

    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    vector<int> change (k + 1, 0);

    // If sum is 0, then answer is 0
    change[0] = 0;

    // Fill the subset table in bottom up manner
    //loop on j is increasing to allow multiple use of elements
    for (int i = 1; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            change[j] = min(change[j], 1+change[j-coins[i]]); // todo check this
        }
    }
    return coins[k];
}
// Driver code
int main()
{
    vector<int> set = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubSetSum1(set, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");

    return 0;
}