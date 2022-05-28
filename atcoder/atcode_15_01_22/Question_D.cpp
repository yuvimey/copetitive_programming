// A Dynamic Programming solution
// for subset sum problem
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

// Returns true if there is a subset of set[]
// with sum equal to given sum
int digits(int n){
    if(n == 1) return 1;
    int i =1;
    int x = 1;
    while(n > x){
        x *= 10;
        i++;
    }
    return i - 1;

}
int rec(int a, int n)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    int d = digits(n);
    int subset[2*d][2*d];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    subset[0][0] = 0;

    // Fill the subset table in bottom up manner
    for (int i = 0; i < 2*d; i++) {
        for (int j = 0; j < 2*d; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }

    /*   // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }*/

    return subset[n][sum];
}

// Driver code
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,a;
    cin >>a >> n;
    cout << rec(a,n) << endl;
}
// This code is contributed by Arjun Tyagi.