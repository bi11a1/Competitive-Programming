///TODO: Set value of lg
///Caution: node starts from 1

const int lg=9;

int n;
int depth[MX], par[MX][lg];
vector< int > adj[MX];

void Dfs(int u, int p){
  for(auto v:adj[u]){
    if(v==p) continue;
    depth[v]=1+depth[u];
    par[v][0]=u;
    Dfs(v, u);
  }
}

void SetPar(){
  int i, j, k;
  for(i=1; i<lg; ++i){
    for(j=1; j<=n; ++j){
      if(par[j][i-1]!=-1) par[j][i]=par[par[j][i-1]][i-1];
    }
  }
}

int Lca(int u, int v){
  int i, j, k;
  if(depth[u]>depth[v]) swap(u, v);
  int dif=depth[v]-depth[u];
  for(i=0; i<lg; ++i){
    if(dif & (1<<i)) v=par[v][i];
  }
  for(i=lg-1; i>=0; --i){
    if(par[u][i]!=par[v][i]) u=par[u][i], v=par[v][i];
  }
  if(u==v) return u;
  return par[u][0];
}
