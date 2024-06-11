#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> temperature(vector<int>& T) {
    vector<int> res(T.size(), 0);
    stack<int> st;
    for (int i = 0; i < T.size(); ++i) {
      while (!st.empty() && T[i] > T[st.top()]) {
        int idx = st.top();
        st.pop();
        res[idx] = i - idx;
      }
      st.push(i);
    }
    return res;
  }

  void test1() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = temperature(T);
    for (int i = 0; i < res.size(); ++i) {
      cout << res[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Solution* s = new Solution();
  s->test1();
  return 0;
}