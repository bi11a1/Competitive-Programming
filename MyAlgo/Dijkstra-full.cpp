// Source: https://codeforces.com/contest/1715/submission/169162508

#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using ll = long long;

const ll inf1 = 1e15;

void Dijkstra(vector<vector<pair<ll, ll>>> &g, vector<ll> &dist) {
  const ll n = g.size();
  vector<bool> used(n, false);
  priority_queue<pair<ll, ll>> q;
  for (ll i = 0; i < n; ++i) {
    q.push({ -dist[i], i });
  }
  while (!q.empty()) {
    ll v = q.top().second;
    q.pop();
    if (used[v]) {
      continue;
    }
    used[v] = true;
    for (auto [u, w] : g[v]) {
      if (dist[u] > dist[v] + w) {
        dist[u] = dist[v] + w;
        q.push({ -dist[u], u });
      }
    }
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> g(n);
  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].push_back({ v, w });
    g[v].push_back({ u, w });
  }
  vector<ll> dist(n, inf1);
  dist[0] = 0;
  Dijkstra(g, dist);
}
