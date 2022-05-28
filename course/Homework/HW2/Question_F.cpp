//
// Created by Yuval on 1/24/2022.
//
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
using namespace std;
using ll = unsigned long long;


#define MAX_SIZE 10000
#define INF 100000
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big?????


struct PT
{
    long long x,y;
    double length() {return sqrt(x*x+y*y);}
    int normalize()
    // normalize the vector to unit length; return -1 if the vector is 0
    {
        double l = length();
        if(fabs(l)<EPS) return -1;
        x/=l; y/=l;
        return 0;
    }
    PT operator-(PT a)
    {
        PT r;
        r.x=x-a.x; r.y=y-a.y;
        return r;
    }
    PT operator+(PT a)
    {
        PT r;
        r.x=x+a.x; r.y=y+a.y;
        return r;
    }
    PT operator*(double sc)
    {
        PT r;
        r.x=x*sc; r.y=y*sc;
        return r;
    }
};


bool operator<(const PT& a,const PT& b)
{
    if(fabs(a.x-b.x)<EPS) return a.y<b.y;
    return a.x<b.x;
}
double dist(PT& a, PT& b)
// the distance between two PTs
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dot(PT& a, PT& b)
// the inner product of two vectors
{
    return(a.x*b.x+a.y*b.y);
}

// ==========================================================
// The Convex Hull
// ==========================================================
int sideSign(PT& p1,PT& p2,PT& p3)// orientation
// which side is p3 to the line p1->p2? returns: 1 left, 0 on, -1 right
{
    double sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y - p3.y)*(p2.x-p3.x);
    if(fabs(sg)<EPS) return 0;
    if(sg>0)return 1;
    return -1;
}
// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
bool better(PT& p1,PT& p2,PT& p3)
// used by convec hull: from p3, if p1 is better than p2
{
    double sg = (p1.y - p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y);
    //watch range of the numbers
    if(fabs(sg)<EPS)
    {
        if(dist(p3,p1)>dist(p3,p2))return true;
        else return false;
    }
    if(sg<0) return true;
    return false;
}


//convex hull nlogn
void vex2(vector<PT> vin,vector<PT>& vout)
// vin is not pass by reference, since we will rotate it
{
    vout.clear();
    int n=vin.size();
    sort(vin.begin(),vin.end());
    PT stk[MAX_SIZE];
    int pstk, i;
    // hopefully more than 2 PTs
    stk[0] = vin[0];
    stk[1] = vin[1];
    pstk = 2;
    for(i=2; i<n; i++)
    {
        if(dist(vin[i], vin[i-1])<EPS) continue;
        while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
            pstk--;
        stk[pstk] = vin[i];
        pstk++;
    }
    for(i=0; i<pstk; i++) vout.push_back(stk[i]);
    // turn 180 degree
    for(i=0; i<n; i++)
    {
        vin[i].y = -vin[i].y;
        vin[i].x = -vin[i].x;
    }
    sort(vin.begin(), vin.end());
    stk[0] = vin[0];
    stk[1] = vin[1];
    pstk = 2;
    for(i=2; i<n; i++)
    {
        if(dist(vin[i], vin[i-1])<EPS) continue;
        while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
            pstk--;
        stk[pstk] = vin[i];
        pstk++;
    }
    for(i=1; i<pstk-1; i++)
    {
        stk[i].x= -stk[i].x; // don’t forget rotate 180 d back.
        stk[i].y= -stk[i].y;
        vout.push_back(stk[i]);
    }
}

// ==========================================================
// Areas
// ==========================================================
double trap(PT a, PT b)
{
    return (0.5*double((b.x - a.x)*(b.y + a.y)));
}


// Given three colinear PTs p, q, r, the function checks if
double triarea(PT a, PT b, PT c)
{
    return fabs(trap(a,b)+trap(b,c)+trap(c,a));
}
double height(PT a, PT b, PT c)
// height from a to the line bc
{
    double s3 = dist(c, b);
    double ar=triarea(a,b,c);
    return(2.0*ar/s3);
}
// ====================================================
// PTs and Lines
// ====================================================
// A C++ program to check if a given PT lies inside a given polygon
// Refer https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// for explanation of functions onSegment(), orientation() and doIntersect()

// Given three collinear PTs p, q, r, the function checks if
// PT q lies on line segment 'pr'
bool onSegment(PT p, PT q, PT r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}


// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
void show(PT& p)
{
    cout<<"("<<p.x<<", "<<p.y<<") ";
}




void closestpt( PT p1, PT p2, PT p3, PT &r )
// the closest PT on the line p1->p2 to p3
{
    if( fabs( triarea( p1, p2, p3 ) ) < EPS )
    { r = p3; return; }
    PT v = p2-p1;
    v.normalize();
    double pr; // inner product
    pr = (p3.y-p1.y)*v.y + (p3.x-p1.x)*v.x;
    r = p1+v*pr;
}








struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt &p) const { return x * p.y - y * p.x; }
    long long dot(const pt &p) const { return x * p.x + y * p.y; }
    long long cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
    long long dot(const pt &a, const pt &b) const { return (a - *this).dot(b - *this); }
    long long sqrLen() const { return this->dot(*this); }
};

bool lexComp(const pt &l, const pt &r) {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

vector<pt> seq;
pt translation;
int n;

bool pointInTriangle(pt a, pt b, pt c, pt point) {
    long long s1 = abs(a.cross(b, c));
    long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
    return s1 == s2;
}

void prepare(vector<pt> &points) {
    n = points.size();
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (lexComp(points[i], points[pos]))
            pos = i;
    }
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;
    seq.resize(n);
    for (int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
    translation = points[0];
}

bool pointInConvexPolygon(pt point) {
    point = point - translation;
    if (seq[0].cross(point) != 1 &&
        sgn(seq[0].cross(point)) != sgn(seq[0].cross(seq[n - 1])))
        return false;
    if (seq[n - 1].cross(point) != 0 &&
        sgn(seq[n - 1].cross(point)) != sgn(seq[n - 1].cross(seq[0])))
        return false;

    if (seq[0].cross(point) == 0)
        return seq[0].sqrLen() >= point.sqrLen();

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pos = mid;
        if (seq[pos].cross(point) >= 0)
            l = mid;
        else
            r = mid;
    }
    int pos = l;
    return pointInTriangle(seq[pos], seq[pos + 1], pt(0, 0), point);
}







int main ()
{
    ios_base::sync_with_stdio(false);
    int x, y;
    int L;
    cin >> L;
    vector<PT> large;
    for(int i=0; i< L; i++) {
        cin >> x >> y;
        large.push_back(PT{x,y});
    }
    vector<PT> vex_large = vector<PT>();
    vex2(large, vex_large);
    int S;
    cin >> S;
    int count = 0;
    for(int i=0; i< vex_large.size(); i++) {
        seq.push_back(pt{vex_large[i].x,vex_large[i].y} );
    }
    prepare(seq);
    for(int i=0; i< S; i++)
    {
        cin >> x >> y;
        if(pointInConvexPolygon(pt{x,y})){
            count++;
        }

    }

    cout << count << endl;
    return 0;
}
