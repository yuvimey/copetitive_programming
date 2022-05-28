// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
#include <limits>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

// set OK function to desired outcome.
bool OK(double c){
    return (c < 4.5);
}
double binary_search_on_real_numbers(double mn, double mx ){
    double c = 0;
    while (mx-mn > 1e-9) {
        c = (mx+mn)/2;
        if (OK(c)) mn = c; else mx = c;
    }
    return c;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
    ? cout << "Element is not present in array"
    : cout << "Element is present at index " << result << endl;

    double c = binary_search_on_real_numbers(4.0, 5.0);
    cout.precision(10);
    cout << "binary search of real number found: " << c << endl;
    return 0;
}
