// Problem Link: https://codeforces.com/problemset/problem/86/D

#include<bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

const int kN = 2e5+5;
const int kBlockSize = sqrt(kN)+1;

int ara[kN], freq[kN*5];

// index are assumed to be within range of [0, kN-1]
struct Query {
  int left, right, index;
  Query() {}
  Query(int new_left, int new_right, int new_index) {
    left = new_left, right = new_right, index = new_index;
  }
  bool operator<(const Query& new_query) const {
    int block_no = left/kBlockSize, new_block_no = new_query.left/kBlockSize;
    if (block_no != new_block_no) { // Smaller blocks first
      return block_no < new_block_no;
    } else {  // For even blocks sort in ascending, for odd block sort in descending
      return (block_no&1) ? (right<new_query.right) : (right>new_query.right);
    }
  }
};

// TODO: Add value at pos and update cur_ans
void AddQuery(int pos, ll &cur_ans) {
  cur_ans -= 1LL*freq[ara[pos]]*freq[ara[pos]]*ara[pos];
  freq[ara[pos]]++;
  cur_ans += 1LL*freq[ara[pos]]*freq[ara[pos]]*ara[pos];
}

// TODO: Remove value at pos and update cur_ans
void RemoveQuery(int pos, ll &cur_ans) {
  cur_ans -= 1LL*freq[ara[pos]]*freq[ara[pos]]*ara[pos];
  freq[ara[pos]]--;
  cur_ans += 1LL*freq[ara[pos]]*freq[ara[pos]]*ara[pos];
}

// Assuming each query has index [0, n-1]
vector<ll> SqrtDecomposition(vector<Query> queries) {
  vector<ll> answers(queries.size());
  sort(queries.begin(), queries.end());

  // Data structure will hold the cur_ans in range [cur_left, cur_right]
  int cur_left = 0, cur_right = -1;
  ll cur_ans = 0;
  for (Query q : queries) {
    while (cur_left > q.left) {
      cur_left--;
      AddQuery(cur_left, cur_ans);
    }
    while (cur_left < q.left) {
      RemoveQuery(cur_left, cur_ans);
      cur_left++;
    }
    while (cur_right > q.right) {
      RemoveQuery(cur_right, cur_ans);
      cur_right--;
    }
    while (cur_right < q.right) {
      cur_right++;
      AddQuery(cur_right, cur_ans);
    }
    answers[q.index] = cur_ans;
  }
  return answers;
}

int main() {
  FASTIO;
  int i, j, k;
  int n, t;
  cin >> n >> t;
  vector<Query> queries;
  for (i = 0; i < n; ++i) cin >> ara[i];
  for (i = 0; i < t; ++i) {
    int left, right, index;
    cin >> left >> right;
    left--;
    right--;
    index = i;
    queries.push_back(Query(left, right, index));
  }

  vector<ll> answers = SqrtDecomposition(queries);
  for (i = 0; i < answers.size(); ++i) {
    cout << answers[i] << endl;
  }
}
