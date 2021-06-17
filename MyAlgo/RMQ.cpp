/// Stores the position of the maximum element in array B
void SetSparseTable() {
  int i, j, k;
  for (i = 1; i < MX; ++i) pre_log[i] = log2(i);
  for (i = 0; i < n; ++i) {
    spt[i][0] = i;
  }
  for (i = 1; i < LG; ++i) {
    for (j = 0; j+(1<<i)-1 < n; ++j) {
      if(B[spt[j][i-1]] >= B[spt[j + (1<<(i-1))][i-1]]) {
        spt[j][i] = spt[j][i - 1];
      } else {
	spt[j][i] = spt[j + (1<<(i-1))][i-1];
      }
    }
  }
}

/// Range Maximum Query on range [l, r] in array B
int RMQ(int l, int r) {
  int len = r-l+1;
  int k = pre_log[len];
  return max(B[spt[l][k]], B[spt[l + len - (1 << k)][k]]);
}
