#include<bits/stdc++.h>
#define MX 100005
using namespace std;
typedef long long ll;

struct st{
     int x, y1, y2, t;
     st(){}
     st(int _x, int _y1, int _y2, int _t){ x=_x, y1=_y1, y2=_y2, t=_t; }
     bool operator<(const st& s) const{ return x<s.x; }
};

vector< int > v1;
vector< st > v2;

struct seg{
     int sm, prop;
} tree[3*MX];

void update(int n, int b, int e, int i, int j, int v){
     if(b>j || e<i){
          return;
     }
     int m=(b+e)/2, l=2*n, r=l+1;
     if(b>=i && e<=j){
          tree[n].prop+=v;
          if(tree[n].prop) tree[n].sm=v1[e+1]-v1[b];
          else tree[n].sm=tree[l].sm+tree[r].sm;
          return;
     }
     update(l, b, m, i, j, v);
     update(r, m+1, e, i, j, v);
     if(tree[n].prop) tree[n].sm=v1[e+1]-v1[b];
     else tree[n].sm=tree[l].sm+tree[r].sm;
}

int main(){
     int i, j, k;
     int t, T, n;
     int x1, x2, y1, y2, curX;
     scanf("%d", &T);
     for(t=1; t<=T; ++t){
          scanf("%d", &n);
          for(i=0; i<3*n; ++i) tree[i].prop=0, tree[i].sm=0;
          for(i=0; i<n; ++i){
               scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
               v1.push_back(y1);
               v1.push_back(y2);
               v2.push_back(st(x1, y1, y2, 1));
               v2.push_back(st(x2, y1, y2, -1));
          }
          sort(v1.begin(), v1.end());
          v1.resize(unique(v1.begin(), v1.end())-v1.begin());
          sort(v2.begin(), v2.end());
          v1.push_back(v1.back());
          curX=v2[0].x;
          int sz=v1.size();
          ll ans=0;
          for(i=0; i<v2.size(); ++i){
               int r1=lower_bound(v1.begin(), v1.end(), v2[i].y1)-v1.begin();
               int r2=lower_bound(v1.begin(), v1.end(), v2[i].y2)-v1.begin();
               ans+=(ll)(v2[i].x-curX)*tree[1].sm;
               update(1, 0, sz-1, r1, r2-1, v2[i].t);
               curX=v2[i].x;
          }
          printf("Case %d: %lld\n", t, ans);
          v1.clear();
          v2.clear();
     }
     return 0;
}
