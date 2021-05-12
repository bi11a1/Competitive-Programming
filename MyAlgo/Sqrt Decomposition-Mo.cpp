/// Sample Submission:https://codeforces.com/contest/86/submission/116024412

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// ----------------begin SqrtDecomposition---------------------
// Complexity: O((N+Q)sqrt(N))
// Check value of N
// Query range [0, n-1]
struct Query {
  int left, right, index;
  Query() {}
  Query(int new_left, int new_right, int new_index) {
    left = new_left, right = new_right, index = new_index;
  }
};

class SqrtDecomposition {
 public:
  void AddQuery(Query q) {
    Queries.push_back(q);
  }

  // Must pass static/global compare function in sort()
  static bool CompareQueries(const Query q1, const Query q2) {
    int block_no1 = q1.left/BlockSize;
    int block_no2 = q2.left/BlockSize;
    if (block_no1 != block_no2) { // For two different blocks, keep Smaller one first
      return block_no1 < block_no2;
    } else {  // For even blocks sort in ascending, for odd block sort in descending
      return (block_no1&1) ? (q1.right<q2.right) : (q1.right>q2.right);
    }
  }

  ///TODO: Add pos
  void AddPos(int pos) {

  }

  ///TODO: Remove pos
  void RemovePos(int pos) {

  }

  ///TODO: Calculate answer
  int GetAnswer() {

  }

  void ProcessQueries() {
    sort(Queries.begin(), Queries.end(), CompareQueries);
    Answers.resize(Queries.size());
    int cur_left = 0, cur_right = -1;
    for (Query q : Queries) {
      while (cur_left > q.left) {
        cur_left--;
        AddPos(cur_left);
      }
      while (cur_left < q.left) {
        RemovePos(cur_left);
        cur_left++;
      }
      while (cur_right > q.right) {
        RemovePos(cur_right);
        cur_right--;
      }
      while (cur_right < q.right) {
        cur_right++;
        AddPos(cur_right);
      }
      Answers[q.index] = GetAnswer();
    }
  }

  /// TODO: Shows answers
  void ShowAnswers() {
    for (int i = 0; i < Answers.size(); ++i) {
      cout << Answers[i] << endl;
    }
  }

 private:
  // static members are initialized once and kept for entire execution of the program
  static const int N = 2e5+5;
  static const int BlockSize = sqrt(N)+1;
  vector<Query> Queries;
  vector<int> Answers;
};
//---------------------end SqrtDecomposition--------------------------------

int main() {
  // Declare object
  SqrtDecomposition sqd;

  /// TODO: AddQueries()

  /// TODO: ProcessQueries()
  sqd.ProcessQueries();

  /// TODO: ShowAnswers()
  sqd.ShowAnswers();
}
