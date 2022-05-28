#include <bits/stdc++.h>
#include <math.h>

#define PI 3.14159265

double f(double x){
    return sin(x);
}

double ternary_search(double l, double r) {
    double eps = 1e-9; //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); //evaluates the function at m1
        double f2 = f(m2); //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l); //return the maximum of f(x) in [l, r]
}

using namespace std;
int main()
{
    cout.precision(10);
    cout << "sin(x) max is " << ternary_search(0.0, PI + 0.001) << endl;
    return 0;
}