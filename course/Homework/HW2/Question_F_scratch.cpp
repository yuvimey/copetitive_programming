//
// Created by Yuval on 1/24/2022.
//
//
// Created by Yuval on 1/24/2022.
//
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using ll = unsigned long long;

#define MAX_SIZE 10000
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;
struct PT
{
    PT() {}
    PT(long long _x, long long _y) : x(_x), y(_y) {}
    double x,y;
    PT operator*(double sc)
    {
        PT r;
        r.x=x*sc; r.y=y*sc;
        return r;
    }

    bool operator==(const PT& rhs)
    {
        if (this->x == rhs.x && this->y == rhs.y){
            return true;
        }
        return false;
    }
    PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
    double cross(const PT &p) const { return x * p.y - y * p.x; }
    double dot(const PT &p) const { return x * p.x + y * p.y; }
    double cross(const PT &a, const PT &b) const { return (a - *this).cross(b - *this); }
    double dot(const PT &a, const PT &b) const { return (a - *this).dot(b - *this); }
    double sqrLen() const { return this->dot(*this);};
};

bool myLess(const PT &l, const PT &r) {
    // return true if l < r
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

int sgn(long long val) {
    if (val > 0) {
        return 1;
    } else if (val == 0) {
        return 0;
    }
    return -1;
}

class CountPointsInPoly
{
public:
    CountPointsInPoly(vector<PT> poly) {
        this->prepare(poly);
    }
    vector<PT> seq;
    PT smallestPoint;
    int n;

    bool pointInConvexPolygon(PT point);

private:
    void prepare(vector<PT> &points);
    bool pointInTriangle(PT a, PT b, PT c, PT point);
};

void CountPointsInPoly:: prepare(vector<PT> &points) {
    n = points.size();
    int pos = 0;
    //find the smallest point
    for (int i = 1; i < n; i++) {
        if (myLess(points[i], points[pos]))
            pos = i;
    }
    //starting element is the smallest
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;
    seq.resize(n);
    //pre calculate difference in points
    for (int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];
    smallestPoint = points[0];
}

bool CountPointsInPoly:: pointInTriangle(PT a, PT b, PT c, PT point) {
    long long s1 = abs(a.cross(b, c));
    long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
    return s1 == s2;
}

bool CountPointsInPoly:: pointInConvexPolygon(PT point) {
    point = point - smallestPoint;

    //check if point in inside poly
    if (seq[0].cross(point) != 0 &&
        sgn(seq[0].cross(point)) != sgn(seq[0].cross(seq[n - 1])))
    {
        return false;
    }
    if (seq[n - 1].cross(point) != 0 &&
        sgn(seq[n - 1].cross(point)) != sgn(seq[n - 1].cross(seq[0])))
    {
        return false;
    }

    //check if point is on poly
    if (seq[0].cross(point) == 0)
    {
        return seq[0].sqrLen() >= point.sqrLen();
    }


    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pos = mid;
        if(seq[pos].cross(point) == 0){
            if(seq[pos].sqrLen() >= point.sqrLen()){
                return true;
            }
            return false;
        }
        if (seq[pos].cross(point) > 0)
            l = mid;
        else
            r = mid;
    }
    int pos = l;
    return pointInTriangle(seq[pos], seq[pos + 1], PT(0, 0), point);
}

bool operator<(const PT& a,const PT& b)
{
    //if(fabs(a.x-b.x)<EPS) return a.y<b.y;
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
double dist(PT& a, PT& b)
// the distance between two points
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
// ==========================================================
// The Convex Hull
// ==========================================================

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
// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Point
{
    int x, y;
};

// A global point needed for sorting points with reference
// to the first point Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

// Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
// Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or chose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

// Place the bottom-most point at first position
    swap(points[0], points[min]);

// Sort n-1 points with respect to the first point.
// A point p1 comes before p2 in sorted output if p2
// has larger polar angle (in counterclockwise
// direction) than p1
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

// If two or more points make same angle with p0,
// Remove all but the one that is farthest from p0
// Remember that, in above sorting, our criteria was
// to keep the farthest point at the end when more than
// one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n-1 && orientation(p0, points[i],
                                      points[i+1]) == 0)
            i++;


        points[m] = points[i];
        m++; // Update size of modified array
    }

// If modified array of points has less than 3 points,
// convex hull is not possible
    if (m < 3) return;

// Create an empty stack and push first three points
// to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

// Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

// Now stack has the output points, print contents of stack
    while (!S.empty())
    {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        S.pop();
    }
}


//convex hull nlogn
void vex2(vector<PT>& vin,vector<PT>& vout)
{
    vout.clear();
    int n=vin.size();
    int st=0;
    int i;
    for(i=1;i<n;i++) if(vin[i]<vin[st]) st=i;
    vector<int> used;
    // used[i] is the index of the i-th point on the hull
    used.push_back(st);
    int idx=st; int next;
    do{
        next=0;
        for(i=1;i<n;i++)
            if(better(vin[i],vin[next],vin[idx]))next=i;
        idx=next;
        used.push_back(idx);
    }while(idx!=st);
    for(i=0;i+1<used.size();i++) vout.push_back(vin[used[i]]);
}


void ans(vector<PT> largeLanterns, vector<PT> smallLanterns) {

    //vex2 - calculates the minimal polygon containing all points in the given set
    //time complexity O(n*log(n))
    vector<PT> smallestConvex;
    //vex2(largeLanterns, smallestConvex);
    Point points[largeLanterns.size()];
    for(int i = 0; i < largeLanterns.size(); i++) points[i] = Point{(int)largeLanterns[i].x,(int)largeLanterns[i].y};
    convexHull(points, largeLanterns.size());
    CountPointsInPoly helper = CountPointsInPoly(smallestConvex);

    ll count = 0;

    //remove small points that are not in the minimal convex wrapping all large points
    for (int i = 0; i < smallLanterns.size(); i++)
    {
        int pIsInside = helper.pointInConvexPolygon(smallLanterns.at(i));
        if (pIsInside) {
            count += 1;
        }
    }

    cout << count << endl;
    return;
}

void QuestionF() {
    vector<PT>  largeLanterns = vector<PT> (0);
    vector<PT>  smallLanterns = vector<PT> (0);

    int len;

    cin >> len;
    //read points representing large lanterns
    for (int i = 0; i < len; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        PT point = PT();
        point.x = x;
        point.y = y;
        largeLanterns.push_back(point);
    }

    cin >> len;
    //read points representing small lanterns
    for (int i = 0; i < len; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        PT point = PT();
        point.x = x;
        point.y = y;
        smallLanterns.push_back(point);
    }

    ans(largeLanterns, smallLanterns);
}


int main()
{
    ios_base::sync_with_stdio(false);
    QuestionF();
    return 0;
}


