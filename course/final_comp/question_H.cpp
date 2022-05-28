#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;
using ll = unsigned long long;


#define MAX_SIZE 1000
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big?????
struct PT
{
    double x,y;
    bool right = true;
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

struct polygon
{
    vector<PT> points;
    double area;
};

bool p_in(polygon polygon, PT &pt);

double calc_baseline(vector<pair<double, double>> *baseline, double a, double b);

#include <map>
#include <vector>
#include <set>

double trap(PT a, PT b)
{
    return (0.5*(b.x - a.x)*(b.y + a.y));
}

double area(vector<PT> &vin)
// Area of a simple polygon, not neccessary convex
{
    int n = vin.size();
    double ret = 0.0;
    for(int i = 0; i < n; i++)
        ret += trap(vin[i], vin[(i+1)%n]);
    return fabs(ret);
}

bool operator<(const PT& a,const PT& b)
{
    if(fabs(a.x-b.x)<EPS){
        if(a.right && b.right){
            return !(a.y<b.y);
        }
        return a.y<b.y;
    }
    return a.x<b.x;
}

int intersection( PT p1, PT p2, PT p3, PT p4, PT &r )
// two lines given by p1->p2, p3->p4 r is the intersection point
// return -1 if two lines are parallel
{
    double d = (p4.y - p3.y)*(p2.x-p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
    if( fabs( d ) < EPS ) return -1;
    // might need to do something special!!!
    double ua, ub;
    ua = (p4.x - p3.x)*(p1.y-p3.y) - (p4.y-p3.y)*(p1.x-p3.x);
    ua /= d;
    // ub = (p2.x - p1.x)*(p1.y-p3.y) - (p2.y-p1.y)*(p1.x-p3.x);
    //ub /= d;
    r = p1 + (p2-p1)*ua;
    return 0;
}
double triarea(PT a, PT b, PT c)
{
    return fabs(trap(a,b)+trap(b,c)+trap(c,a));
}
int pAndSeg(PT& p1, PT& p2, PT& p) //onSegment
// the relation of the point p and the segment p1->p2.
// 1 if point is on the segment; 0 if not on the line; -1 if on the line but not on the segment
{
    double s=triarea(p, p1, p2);
    if(s>EPS) return(0);
    double sg=(p.x-p1.x)*(p.x-p2.x);
    if(sg>EPS) return(-1);
    sg=(p.y-p1.y)*(p.y-p2.y);
    if(sg>EPS) return(-1);
    return(1);
}
int sideSign(PT& p1,PT& p2,PT& p3)// orientation
// which side is p3 to the line p1->p2? returns: 1 left, 0 on, -1 right
{
    double sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y - p3.y)*(p2.x-p3.x);
    if(fabs(sg)<EPS) return 0;
    if(sg>0)return 1;
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    PT p1, p2;
    polygon poly;
    poly.area = 0;
    poly.points = vector<PT>();
    vector<pair<double,double>> baseline;
    double baseline_len = 0.0;
    vector<double> res;
    for( int i = 0; i < N; i++){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        p1.right = false;
        p2.right = true;
        baseline_len = calc_baseline(&baseline, p1.x, p2.x);
        baseline.push_back(make_pair(p1.x,p2.x));
        if(p1.y == 0 && p2.y == 0){
            res.push_back(baseline_len/(p2.x-p1.x));
            continue;
        }
        double prev_area = poly.area;
        vector<int> points_to_remove;
        vector<PT> points_to_add;
        bool p1_yes = true;
        bool p2_yes = true;
        bool p1_0_yes = true;
        bool p2_0_yes = true;

        double slope = (p2.y-p1.y)/(p2.x-p1.x);
        int size = poly.points.size()-1;
        PT bottom1 = PT{p1.x,0, false};
        PT bottom2 = PT{p2.x,0, true};
        for(int j=0; j < size; j++){
            PT r;
            int is_intersected = intersection(poly.points[j], poly.points[j+1], p1, p2, r);
            if(is_intersected == 0 && pAndSeg(p1, p2, r) == 1 && pAndSeg(poly.points[j], poly.points[j+1], r) == 1){
                if((p1.x == r.x && p1.y == r.y) || (p2.x == r.x && p2.y == r.y)){}
                if ((poly.points[j].x == r.x && poly.points[j].y == r.y) || (poly.points[j+1].x == r.x && poly.points[j+1].y == r.y)){}
                else {
                    points_to_add.push_back(r);
                }
            }
            is_intersected = intersection(poly.points[j], poly.points[j+1], bottom1, p1, r);
            if(is_intersected == 0 && pAndSeg(bottom1, p1, r) == 1 && pAndSeg(poly.points[j], poly.points[j+1], r) == 1){
                if((p1.x == r.x && p1.y == r.y) || (bottom1.x == r.x && bottom1.y == r.y)){}
                if ((poly.points[j].x == r.x && poly.points[j].y == r.y) || (poly.points[j+1].x == r.x && poly.points[j+1].y == r.y)){}
                else {
                    points_to_add.push_back(r);
                }
            }
            is_intersected = intersection(poly.points[j], poly.points[j+1], bottom2, p2, r);
            if(is_intersected == 0 && pAndSeg(bottom2, p2, r) == 1 && pAndSeg(poly.points[j], poly.points[j+1], r) == 1){
                if((p2.x == r.x && p2.y == r.y) || (bottom2.x == r.x && bottom2.y == r.y)){}
                if ((poly.points[j].x == r.x && poly.points[j].y == r.y) || (poly.points[j+1].x == r.x && poly.points[j+1].y == r.y)){}
                else {
                    points_to_add.push_back(r);
                }
            }
            int side1 = sideSign(poly.points[j], poly.points[j+1], p1);
            int side2 = sideSign(poly.points[j], poly.points[j+1], p2);
            double slope_i = (poly.points[j+1].y - poly.points[j].y)/(poly.points[j+1].x - poly.points[j].x);
            if(p1.x == poly.points[j].x || p1.x == poly.points[j+1].x) {p1_0_yes = false;}
            if(p2.x == poly.points[j].x || p2.x == poly.points[j+1].x) {p2_0_yes = false;}
            if(p1.x > poly.points[j].x && p1.x < poly.points[j+1].x){
                if(side1 < 0){
                    p1_yes = false;
                }
                if(poly.points[j].y != 0 || poly.points[j+1].y != 0){
                    p1_0_yes = false;
                }

            }
            if(p2.x > poly.points[j].x && p2.x < poly.points[j+1].x){
                if(side2 < 0){
                    p2_yes = false;
                }
                if(poly.points[j].y != 0 || poly.points[j+1].y != 0){
                    p2_0_yes = false;
                }
            }
            int sidej = sideSign(p1, p2, poly.points[j]);
            if (poly.points[j].x > p1.x && poly.points[j].x < p2.x) {
                if (sidej < 0) {
                    points_to_remove.push_back(j);
                }
            }
            if(poly.points[j].x == p1.x && poly.points[j+1].x == p1.x && poly.points[j+1].y == 0){
                points_to_remove.push_back(j+1);
            }
            if(poly.points[j].x == p2.x && poly.points[j+1].x == p2.x && poly.points[j].y == 0){
                points_to_remove.push_back(j);
            }
        }
        if(size >= 0) {
            int sidej = sideSign(p1, p2, poly.points[size]);
            if (poly.points[size].x > p1.x && poly.points[size].x < p2.x) {
                if (sidej < 0 ) {
                    points_to_remove.push_back(size);
                }
            }
        }

        for(int j = 0; j < points_to_remove.size(); j++){
            poly.points[points_to_remove[j]] = PT{-1,-1};
        }
        for(int j = 0; j < poly.points.size(); j++){
            if(poly.points[j].x == -1){
                poly.points.erase(poly.points.begin()+j);
                j--;
            }
        }
        for(int j = 0; j < points_to_add.size(); j++){
            if(p_in(poly, points_to_add[j])) continue;
            poly.points.push_back(points_to_add[j]);
        }
        if(i == 1){
            int x = 3300;
        }
        if(p1_yes){ if(!p_in(poly, p1)) poly.points.push_back(p1);}
        if(p2_yes) {if(!p_in(poly, p2)) poly.points.push_back(p2);}
        if(p1_0_yes) {if(!p_in(poly, bottom1)) poly.points.push_back(bottom1);}
        if(p2_0_yes) {if(!p_in(poly, bottom2)) poly.points.push_back(bottom2);}
        sort(poly.points.begin(), poly.points.end());
        poly.area = area(poly.points);
        double added_area = poly.area - prev_area;
        vector<PT> building = vector<PT>();//{PT{p1.x,0}, p1, p2, PT{p2.x,0}});
        building.push_back(PT{p1.x,0});
        if(p1.y != 0) building.push_back(p1);
        building.push_back(p2);
        if(p2.y != 0) building.push_back(PT{p2.x,0});
        double building_area = area(building);
        res.push_back(added_area/building_area);
    }
    cout.precision(8);
    for(int i=0; i<N; i++){
        cout << res[i] << endl;
    }
    return 0;
}

double calc_baseline(vector<pair<double, double>> *baseline, double a, double b) {
    for(int i = 0; i < baseline->size(); i++){
        if((*baseline)[i].first <= a && (*baseline)[i].second >= b){
            return 0.0;
        }
        if((*baseline)[i].first <= a && (*baseline)[i].second >= a ){
            a = (*baseline)[i].second;
        }
        if((*baseline)[i].first <= b && (*baseline)[i].second >= b ){
            b = (*baseline)[i].first;
        }
    }
    if( a >= b){
        return 0.0;
    }
    return b-a;
}

bool p_in(polygon polygon, PT &pt) {
    for(int i = 0; i < polygon.points.size(); i++){
        if(polygon.points[i].x == pt.x && polygon.points[i].y == pt.y) return true;
    }
    return false;
}
