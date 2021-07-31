/// Converts n to base b
// lg indicates maximum bits
// (5) in base 10 = 0000...00101 in base 2

ll lg;

vector<ll> ConvertToBase(ll n, ll b) {
  vector<ll> res;
  while (n > 0) {
    res.push_back(n%b);
    n /= b;
  }
  while (res.size() < lg) res.push_back(0);
  reverse(res.begin(), res.end());
  return res;
}

ll ToDecimal(vector<ll> bits, ll b) {
  ll res = 0, p = 1, i;
  for (i = lg-1; i >= 0; --i) {
    if (bits[i] > 0) res += bits[i] * p;
    p *= b;
  }
  return res;
}
