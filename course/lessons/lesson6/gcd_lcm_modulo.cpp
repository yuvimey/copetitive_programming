// C++ program to demonstrate
// Basic Euclidean Algorithm
// Time Complexity: O(Log min(a, b))
#include "bits/stdc++.h"
using namespace std;

int power(long long x, unsigned int y, int p);

// Function to return
// gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

// C++ program to find multiplicative modulo inverse using
// find x for a*x = 1 mod m
// Works when m and a are coprime
// Time Complexity: O(log m)
void modInverse_coprime(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        cout << "Modular multiplicative inverse is " << res << endl;
    }
}

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
// find x for a*x = 1 mod m
// Time Complexity: O(log m)
void modInverse_prime(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m) << endl;
    }
}

/* Iterative Function to calculate (x^y) mod p in O(log y) */
int power(long long x, unsigned int y, int p)
{
    int res = 1;	 // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}



// Driver Code
int main()
{
    int a = 10, b = 15;
    cout << "GCD(" << a << ", "
         << b << ") = " << gcd(a, b)
         << endl;
    a = 35, b = 10;
    cout << "LCM(" << a << ", "
         << b << ") = " << lcm(a, b)
         << endl;

    int x, y;
    a = 10;
    b = 35;
    int g = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b
         << ") = " << g << endl;

    int m = 11;
    a = 3;
    modInverse_coprime(a, m);

    m = 11;
    a = 3;
    modInverse_prime(a, m);

    x = 2;
    y = 5;
    int p = 13;
    cout << "Power is " << power(x, y, p) << endl;
    return 0;


}

// This code is contributed
// by Nimit Garg
