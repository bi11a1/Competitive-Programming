// Source: https://codeforces.com/contest/1559/submission/125961141

const int MX = 100001; 
 
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ];
 
    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }
 
    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }
 
    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;
 
    }
};
 
void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    DSU<MX> A, B;
    F0R(i, X) {
        int U, V; cin >> U >> V; U--; V--;
        A.unify(U, V);
    }
    F0R(i, Y) {
        int U, V; cin >> U >> V; U--; V--;
        B.unify(U, V);
    }
 
    vpi ans;
    F0R(i, N) {
        F0R(j, i) {
            if (A.get(i) != A.get(j) && B.get(i) != B.get(j)) {
                A.unify(i, j); B.unify(i, j); ans.pb({i+1, j+1});
            }
        }
    }
    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a.f << " " << a.s << nl;
    }
 
}
