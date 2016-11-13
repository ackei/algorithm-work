#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define EPS 1e-9

struct point{
	double x,y;
	point() {x=y=0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

point midpoint(point p1, point p2){
	return point((p1.x+p2.x)/2.0, (p1.y+p2.y)/2.0);
}


struct line{
	double a,b,c;
};

void pointsToLine(point p1, point p2, line& l){
	if (fabs(p1.x - p2.x) < EPS){
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	}
	else{
		l.a = -(double)(p1.y-p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areIntersect(line l1, line l2, point& p){
	if (areParallel(l1,l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else				  p.y = -(l2.a * p.x + l2.c);
	return true;
}

double perimeter(const vector<point> &P){
	double result = 0.0;
	for (int i = 0; i < (int)P.size()-1; i++)
		result += dist(P[i],P[i+1]);
	return result;
}

double area (const vector<point> &P){
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size() - 1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}

double area_triangle(point p1, point p2, point p3){
	vector<point> P;
	P.push_back(p1);
	P.push_back(p2);
	P.push_back(p3);
	P.push_back(p1);
	return area(P);
}

int main(){
	int TC, c;
	double bx, cx, cy, dx, dy;
	scanf("%d",&TC);
	while (TC--){
		scanf("%d %lf %lf %lf %lf %lf",&c,&bx,&cx,&cy,&dx,&dy);
		vector<point> tract;
		tract.push_back(point(0.0,0.0));
		tract.push_back(point(bx,0.0));
		tract.push_back(point(cx,cy));
		tract.push_back(point(dx,dy));
		tract.push_back(point(0.0,0.0));
		vector<point> intersect_points;
		for (int i = 0; i < 4; i++){
			line l1, l2;
			pointsToLine(tract[i],midpoint(tract[i+1],tract[(i+2) % 4]),l1);
			pointsToLine(tract[i+1],midpoint(tract[(i+2) % 4],tract[(i+3) % 4]),l2);
			point p;
			areIntersect(l1,l2,p);
			intersect_points.push_back(p);
		}
		intersect_points.push_back(intersect_points[0]);
		printf("%d ",c);
		for (int i = 0; i < 4; i++){
			printf("%.3f ", area_triangle(tract[i],tract[i+1],intersect_points[i]) / 160);
		}
		printf("%.3f ", area(intersect_points) / 160);
		printf("%.0f\n", ceil(perimeter(intersect_points) * 16.5));
	}
	return 0;
}

