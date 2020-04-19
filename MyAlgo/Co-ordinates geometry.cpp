#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-9;
const double PI=acos(-1);

/// POINT

struct point{
     double x, y; // check the data type
     point(){ x=y=0.0; }
     point(double _x, double _y){ x=_x; y=_y; } // user defined
     bool operator< (point p) const{    // sorting
          if(fabs(x-p.x)>EPS) return x<p.x;
          else return y<p.y;
     }
};

// Euclidean distance
double dist(point p1, point p2){
     // return hypot(p1.x-p2.x, p1.y-p2.y);    hypot(dx, dy)=sqrt(dx*dx+dy*dy) :v
     return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

// rotate p by rad(in radian) CCW w.r.t origin (0, 0)
point pointRotate(point p, double rad){ return point(p.x*cos(rad)-p.y*sin(rad), p.x*sin(rad)+p.y*cos(rad)); }

// rotate p1 by rad(in radian) CCW w.r.t origin p2
point pointRotatePoint(point p1, point p2, double rad){
     point p=pointRotate(point(p1.x-p2.x, p1.y-p2.y), rad);
     p.x+=p2.x; p.y+=p2.y;
     return p;
}

//Returns true if _x1==_x2
bool floatEqual(double _x1, double _x2){ return fabs(_x1-_x2)<EPS; }
//Returns true if _x1>_x2
bool floatGreater(double _x1, double _x2){ return _x1-EPS>_x2; }
//Returns true if _x1<_x2
bool floatLesser(double _x1, double _x2){ return _x1+EPS<_x2; }

/// LINE

// Equation of a line: ax+by+c=0
struct line{
     double a, b, c;
};

// Returns equation of a line passing through p1 and p2
line pointsToLine(point p1, point p2){
     line l;
     if(fabs(p1.x-p2.x)<EPS){      // Vertical line
          l.a=1; l.b=0.0; l.c=-p1.x;
     }
     else{
          l.a=-(p1.y-p2.y)/(p1.x-p2.x);
          l.b=1;
          l.c=-(l.a*p1.x)-p1.y;
     }
     return l;
}

// Returns true if two lines are parallel
bool areParallel(line l1, line l2){ return fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS; }

// returns true if a point p is on the segment whose end points are a, b
bool onSegment(point p, point a, point b){
     return p.x>=min(a.x, b.x) && p.x<=max(a.x, b.x) && p.y>=min(a.y, b.y) && p.y<=max(a.y, b.y);
}

// returns true(also the point) if two lines intersect
// intersected point is stored in p
bool doIntersect(point p1, point p2, point p3, point p4, point &p){
     line l1=pointsToLine(p1, p2);
     line l2=pointsToLine(p3, p4);
     if(areParallel(l1, l2)){
          if(onSegment(p1, p3, p4)) p.x=p1.x, p.y=p1.y;
          else if(onSegment(p2, p3, p4)) p.x=p2.x, p.y=p2.y;
          else return 0;
          return 1;
     }
     p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b); // by solving two line equation
     if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);  // to avoid divide by zero
     else p.y = -(l2.a * p.x + l2.c);
     return 1;
}

/// VECTOR

struct vec{
     double x, y;
     vec(){x=y=0.0;}
     vec(double _x, double _y){x=_x; y=_y;}
};

// convert 2 points to vector p1->p2
vec toVector(point p1, point p2){ return vec(p2.x-p1.x, p2.y-p1.y); }

// nonnegative s = [<1 .. 1 .. >1]
//                       shorter.same.longer
vec scale(vec v, double x){ return vec(v.x*x, v.y*x); }

// translate p according to v
// i.e: p is transferred (from its current position) |v| unit in the direction of v
point translate(point p, vec v){ return point(p.x+v.x, p.y+v.y); }

// Dot product of vector a, b: (axi+ayi).(bxi+byi)=ax*bx+ay*by
double dotProduct(vec a, vec b){ return a.x*b.x+a.y*b.y; }

// Using determinant rule
double crossProduct(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// |v|^2=v.x*v.x+v.y*v.y
double norm_sq(vec v){ return v.x*v.x+v.y*v.y; }

// returns the distance from p to the line(_segment=0)/segment(_segment=1) defined by -
// two points a and b (a and b must be different for line)
// the closest point (from p to line) is stored in c
double distToLineOrSeg(point p, point a, point b, point &c, bool _segment){
     vec ap=toVector(a, p), ab=toVector(a, b);
     double u=dotProduct(ap, ab)/norm_sq(ab);
     if(_segment){
          if(u<0.0) c=a; // Closer to a
          else if(u>1.0) c=b; // Closer to b
          else c=translate(a, scale(ab, u)); // Similar to line
     }
     else c=translate(a, scale(ab, u));
     return dist(c, p);
}

// Given a point p and a line l (described by two points a and b) -
// returns the location of a reflection point r of point p when mirrored against line l
point mirrorPoint(point p, point a, point b){
     point c, r;
     distToLineOrSeg(p, a, b, c, 0);
     r=translate(p, scale(toVector(p, c), 2));
     return r;
}

// returns angle aob in rad
double angle(point a, point o, point b){
     vec oa=toVector(o, a), ob=toVector(o, b);
     return acos(dotProduct(oa, ob)/(sqrt(norm_sq(oa)*norm_sq(ob))));
}

// returns c.c.w. angle from x axis to the vector in rad
double angleWRTx(vec v){
     double rad=atan2(v.y, v.x);
     if(rad<0) rad=2.0*PI+rad;
     return rad;
}

// note: to accept collinear points as CCW, change '> 0' to '>=0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r){ return crossProduct(toVector(p, q), toVector(p, r))>0; }

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) { return fabs(crossProduct(toVector(p, q), toVector(p, r))) < EPS; }

/// TRIANGLE

// returns angle between edges a and b (length of the edges of triangles are a, b, c)
double angleFromLength(double a, double b, double c){ return acos((a*a+b*b-c*c)/(2.0*a*b)); }

// area of the triangle with edge lengths a, b, c
double areaFromLength(double a, double b, double c){
     double s=(a+b+c)/2.0;
     return sqrt(s*(s-a)*(s-b)*(s-c));
}

/// CIRCLE

// returns the radius of the circle surrounding the triangle
double rCircumCircle(double ab, double bc, double ca){
     return ab * bc * ca / (4.0 * areaFromLength(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c){
     return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

// returns the radius of the circle surrounded by the triangle
double rInCircle(double ab, double bc, double ca){
     return areaFromLength(ab, bc, ca) / (0.5 * (ab+bc+ca));
}
double rInCircle(point a, point b, point c){
     return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// returns 1 if there is an inCircle(circle surrounded by the triangle) center
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r){
     r=rInCircle(p1, p2, p3);
     if(fabs(r)<EPS) return 0; // no inCircle center
     double ration = dist(p1, p2) / dist(p1, p3);
     point p = translate(p2, scale(toVector(p2, p3), ration / (1 + ration)));
     ration = dist(p2, p1) / dist(p2, p3);
     p = translate(p1, scale(toVector(p1, p3), ration / (1 + ration)));
     doIntersect(p1, p, p2, p, ctr); // get their intersection point
     return 1;
}

// returns the overlapped area(union) of two circles
// first circle center c1 and radius r1
// second circle center c2 and radius r2
double overlapCircleArea(point c1, double r1, point c2, double r2){
     double d, rad1, rad2, area1, area2, chord;
     if(r1>r2){
          swap(c1, c2);
          swap(r1, r2);
     }
     d=dist(c1, c2);
     if(d>=r1+r2) return 0;
     if(d<=r2-r1) return PI*r1*r1;
     rad1=angleFromLength(r1, d, r2), rad2=angleFromLength(r2, d, r1);
     chord=2.0*r1*sin(rad1);
     area1=(r1*r1*rad1)-((2*rad1>PI)?-1:1)*areaFromLength(r1, r1, chord);
     area2=(r2*r2*rad2)-areaFromLength(r2, r2, chord);
     return area1+area2;
}

/// POLYGON

//returns true if the point p is inside polygon(first point=last point)
bool inPolygon(point poly[], int n, point p){
     int i, j, k;
     double totAngle=0;
     for(i=0; i<n; ++i) if(poly[i].x==p.x && poly[i].y==p.y) return true;  //if it overlaps with some point
     for(i=1; i<n; ++i) if(collinear(p, poly[i-1], poly[i]) && onSegment(p, poly[i-1], poly[i])) return true; //if it is in some edges of the polygon
     for(i=1; i<n; ++i){
          if(ccw(poly[i-1], p, poly[i])) totAngle-=angle(poly[i-1], p, poly[i]);
          else totAngle+=angle(poly[i-1], p, poly[i]);
     }
     return fabs(totAngle-2.*PI)<EPS;
}

/// CONVEX HULL
double cross(point p1, point p2, point p3){ return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x); }
// Returns the Hull created by the n points of ara[]
// Does not take linear points in the hull
vector< point > ConvexHull(int n, point ara[]){
     int i, j, k;
     vector< point > cnvx(2*n);
     sort(ara, ara+n);
     for(i=0, k=0; i<n; ++i){
          while(k>=2 && cross(cnvx[k-2], cnvx[k-1], ara[i])<=0) k--;
          cnvx[k++]=ara[i];
     }
     for(i=n-2, j=k+1; i>=0; --i){
          while(k>=j && cross(cnvx[k-2], cnvx[k-1], ara[i])<=0) k--;
          cnvx[k++]=ara[i];
     }
     cnvx.resize(k-1);   // Not taking the last point as first point
     return cnvx;
}
// returns the maximum area of a triangle created by three points on the convex hull
double maxTriangleArea(vector< point > cnvx){
     int sz=cnvx.size();
     if(sz<3) return 0;
     int a=0, b=(a+1)%sz, c=(b+1)%sz;
     double area, narea, ans=0;
     while(a<sz){
          area=getArea(cnvx[a], cnvx[b], cnvx[c]);
          while(1){
               while(1){
                    c=(c+1)%sz;
                    narea=getArea(cnvx[a], cnvx[b], cnvx[c]);
                    if(narea<area){
                         c=(c-1+sz)%sz;
                         break;
                    }
                    area=narea;
               }
               b=(b+1)%sz;
               narea=getArea(cnvx[a], cnvx[b], cnvx[c]);
               if(narea<area){
                    b=(b-1+sz)%sz;
                    break;
               }
               area=narea;
          }
          ans=max(ans, area);
          a++;
          if(a==b) b=(b+1)%sz;
          if(b==c) c=(c+1)%sz;
     }
     return ans;
}
