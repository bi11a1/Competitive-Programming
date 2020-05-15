// SPOJ MST

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct st{
      int u, v, dis;
      bool operator< (const st& s) const{
            return dis<s.dis;
      }
};

vector<st> vt;
int par[10005];

int findP(int n){
      return par[n]=(par[n]==n)?n:(findP(par[n]));
}

void mst(int n){
      int i, j, k, cnt=0;
      ll sm=0;
      sort(vt.begin(), vt.end());
      for(i=1; i<=n; ++i) par[i]=i;
      for(i=0; i<vt.size(); ++i){
            j=findP(vt[i].u);
            k=findP(vt[i].v);
            if(j!=k){
                  par[j]=k;
                  sm+=vt[i].dis;
                  cnt++;
            }
            if(cnt==n-1) break;
      }
      cout << sm << endl;
}

int main(){
      int n, e;
      int i, j, k;
      st s;
      while(cin >> n >> e){
            vt.clear();
            for(i=0; i<e; ++i){
                  scanf("%d %d %d", &s.u, &s.v, &s.dis);
                  vt.push_back(s);
            }
            mst(n);
      }
      return 0;
}
