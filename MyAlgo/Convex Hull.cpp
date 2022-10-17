struct Point {
  ll x, y;
  Point() {
    x = 0, y = 0;
  }
  Point(ll x, ll y) {
    this->x = x, this->y = y;
  }
  bool operator<(const Point &p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
};

ll Cross(Point p1, Point p2, Point p3) { return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x); }

// Returns the Hull created by the vertices of vector 'vertex'
// Does not take linear points in the hull
vector<Point> ConvexHull(vector<Point> vertex){
  ll i, j, k;
  ll n = vertex.size();
  vector<Point> cnvx(2*n);
  sort(vertex.begin(), vertex.end());
  for (i = 0, k = 0; i < n; ++i) {
    while (k >= 2 && Cross(cnvx[k-2], cnvx[k-1], vertex[i]) <= 0) k--;
    cnvx[k++] = vertex[i];
  }
  for (i = n-2, j = k+1; i >= 0; --i) {
    while (k >= j && Cross(cnvx[k-2], cnvx[k-1], vertex[i]) <= 0) k--;
    cnvx[k++] = vertex[i];
  }
  //cnvx.resize(k-1);   // Not taking the last point as first point
  cnvx.resize(k);   // Taking the last point as first point
  return cnvx;
}
