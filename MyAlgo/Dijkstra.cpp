const ll INF = 1e17;
// vector<vector<pair<int, int>>> adj;
// the edges are of the form u -> (v, path_len)
// array d contains distance from s to all other vertices
// array p contains path to it's parent in the shortest path (except for root, s)
 
void Dijkstra(ll s, vector<ll> &d, vector<ll> &p) {
  /// Todo: Set the value of 'n'
  ll n = 9*MX-1;
  d.assign(n, INF);
  p.assign(n, -1);
 
  d[s] = 0;
  using pii = pair<ll, ll>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty()) {
    ll v = q.top().second;
    ll d_v = q.top().first;
    q.pop();
    if (d_v != d[v]) continue;
 
    for (auto edge : adj[v]) {
      ll to = edge.first;
      ll len = edge.second;
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
        q.push({d[to], to});
      }
    }
  }
}
