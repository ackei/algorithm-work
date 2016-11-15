#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define EPS 1e-5

struct point{
	double x,y;
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec{
	double x,y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2){
	return hypot(p1.x-p2.x,p1.y-p2.y);
}

double dist(point p, vec v){
	return hypot(p.x-v.x,p.y-v.y);
}

double area(const vector<point> &P){
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size()-1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}

vec addVec(vec a, vec b){
	return vec(a.x+b.x,a.y+b.y);
}

vec toVec(point a, point b){
	return vec(b.x-a.x,b.y-a.y);
}

vec scale(vec v, double s){
	return vec(v.x * s, v.y * s);
}

double dot(vec a, vec b){
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
	return v.x * v.x + v.y + v.y;
}

double angle(point a, point o, point b){
	vec oa = toVector(o,a), ob = toVector(o,b);
	return acos(dot(os,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double angle(vec os, vec ob){
	return acos(dot(os,ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double binary_search(double L, double s1, double s2, point p1, point p2, point p3){
	double lb = 0;
	double ub = L-s1-s2;
	double x = (ub + lb) / 2;
	double a1 = L - s1 - s2 - x;
	vec v = toVec(p2,p3);
	double a2 = dist(p1,scale(v,x/sqrt(norm_sq(v))));
	while (fabs(a1 - a2) > EPS){
		if (a1 > a2){
			lb = x;
			x = (ub + lb) / 2;
		}
		else{
			ub = x;
			x = (ub + lb) / 2;
		}
	}
	return x;
}



int main(){
	int TC;
	cin >> TC;
	while (TC--){
		int c, bx, cx, cy, L;
		scanf("%d %lf %lf %lf %lf",&c,&bx,&cx,&cy,&L);
		point A(0.0,0.0);
		point B(bx,0.0);
		point C(cx,cy);	
		
	}
	return 0;
}
