int tree[4*MX], carry[4*MX];

void Init(int node, int b, int e) {
  if (b == e) {
    /// TODO: tree[node] = ?
    /// TODO: carry[node] = ?
    return;
  }
  int lft = (node<<1), rht = lft+1, mid = ((b+e)>>1);
  Init(lft, b, mid);
  Init(rht, mid+1, e);
  ///TODO: tree[node] = ?
  ///TODO: carry[node] = ?
}

void Propagate(int node, int c) {
  /// Todo: tree[node] = ?
  /// Todo: carry[node] = ?
}

void Update(int node, int b, int e, int s, int f) {
  if (b > f || e < s) return;
  if (b >= s && e <= f) {
    /// TODO: Propagate(node, ?)
    return;
  }
  int lft = (node<<1), rht = lft+1, mid = ((b+e)>>1);

  Propagate(lft, carry[node]);
  Propagate(rht, carry[node]);
  /// TODO: carry[node] = ?

  Update(lft, b, mid, s, f);
  Update(rht, mid+1, e, s, f);
  /// TODO: tree[node] = ?
}

int Query(int node, int b, int e, int s, int f) {
  if (b > f || e < s) {
    return /// TODO: return value for outside segment
  }
  if (b >= s && e <= f) {
    return /// TODO: tree[node] ??
  }
  int lft = (node<<1), rht = lft+1, mid = ((b+e)>>1);
  int q1 = Query(lft, b, mid, s, f);
  int q2 = Query(rht, mid+1, e, s, f);
  return /// TODO: q1 or q2 ??
}
