///CF 877E

#include<bits/stdc++.h>
#define MX 200005
using namespace std;
typedef long long ll;

vector< int > vt[MX];
int chk[MX], dpth[MX], col[MX], pos[MX], light[MX];
pair< int, int > ara[MX];
int gt=0;

void dfs(int node){
     chk[node]=1; dpth[node]=1;
     ara[node].first=++gt, ara[node].second=node;
     int i, j, k;
     for(i=0; i<vt[node].size(); ++i){
          j=vt[node][i];
          if(!chk[j]){
               dfs(j);
               dpth[node]+=dpth[j];
          }
     }
}

struct st{
     int carry, on, off;
};

st tree[4*MX];

void init(int node, int b, int e){
     if(b==e){
          tree[node].on=light[b];
          tree[node].off=!light[b];
          tree[node].carry=0;
          return;
     }
     int l=2*node, r=l+1, m=(b+e)/2;
     init(l, b, m);
     init(r, m+1, e);
     tree[node].on=tree[l].on+tree[r].on;
     tree[node].off=tree[l].off+tree[r].off;
     tree[node].carry=0;
}

void update(int node, int b, int e, int i, int j, int carry){
     if(b>j || e<i){
          if(carry%2) swap(tree[node].on, tree[node].off);
          tree[node].carry+=carry;
          return;
     }
     if(b>=i && e<=j){
          if((carry+1)%2) swap(tree[node].on, tree[node].off);
          tree[node].carry+=carry+1;
          return;
     }
     int m=(b+e)/2, l=node*2, r=l+1;
     update(l, b, m, i, j, carry+tree[node].carry);
     update(r, m+1, e, i, j, carry+tree[node].carry);
     tree[node].on=tree[l].on+tree[r].on;
     tree[node].off=tree[l].off+tree[r].off;
     tree[node].carry=0;
}

int query(int node, int b, int e, int i, int j, int carry){
     if(e<i || b>j) return 0;
     if(b>=i && e<=j) return (carry%2)?tree[node].off:tree[node].on;
     int l=2*node, r=l+1, m=(b+e)/2;
     return query(l, b, m, i, j, carry+tree[node].carry)+query(r, m+1, e, i, j, carry+tree[node].carry);
}

int main(){
     int i, j, k;
     int n;
     char str[100];
     scanf("%d", &n);
     for(i=2; i<=n; ++i){
          scanf("%d", &k);
          vt[i].push_back(k);
          vt[k].push_back(i);
     }
     for(i=1; i<=n; ++i){
          scanf("%d", &k);
          col[i]=k;
     }
     dfs(1);
     sort(ara+1, ara+n+1);
     for(i=1; i<=n; ++i) pos[ara[i].second]=i, light[i]=col[ara[i].second];
     int q;
     scanf("%d", &q);
     init(1, 1, n);
     while(q--){
          scanf("%s %d", str, &k);
          if(str[0]=='p') update(1, 1, n, pos[k], pos[k]+dpth[k]-1, 0);
          else printf("%d\n", query(1, 1, n, pos[k], pos[k]+dpth[k]-1, 0));
     }
}
