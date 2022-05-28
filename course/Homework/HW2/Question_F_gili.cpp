#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using ll = unsigned long long;

#define MAX_SIZE 10001
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
    if (seq[n-1].cross(point) == 0)
    {
        return seq[n-1].sqrLen() >= point.sqrLen();
    }


    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pos = mid;
        if (seq[pos].cross(point) == 0)
        {
            return seq[pos].sqrLen() >= point.sqrLen();
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
//convex hull nlogn
vector<PT> vex2(vector<PT> vin)
// vin is not pass by reference, since we will rotate it
{
    vector<PT> vout = vector<PT> (0);
    vout.clear();
    int n=vin.size();
    sort(vin.begin(),vin.end());
    PT stk[MAX_SIZE];
    int pstk, i;
    // hopefully more than 2 points
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
        stk[i].x= -stk[i].x;
        stk[i].y= -stk[i].y;
        vout.push_back(stk[i]);
    }
    return vout;
}


void ans(vector<PT> largeLanterns, vector<PT> smallLanterns) {

    //vex2 - calculates the minimal polygon containing all points in the given set
    //time complexity O(n*log(n))
    vector<PT> smallestConvex = vex2(largeLanterns);

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