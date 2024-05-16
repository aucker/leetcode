#include <bits/stdc++.h>

#include <algorithm>
#include <array>
#include <numeric>
using std::accumulate;
using std::sort;
using std::vector;

class Solution {
 public:
  /**
   * @brief Greedy + Brute Force
   * Time: O(nlogn + n * U), n = len(tasks), U = max(end)
   * Space: O(U)
   *
   * @param tasks
   * @return int
   */
  auto FindMinimumTime(vector<vector<int>>& tasks) -> int {
    // ranges::sort(tasks, [])
    sort(tasks.begin(), tasks.end(),
         [&](auto& lhs, auto& rhs) { return lhs[1] < rhs[1]; });
    int ans = 0;
    vector<int> run(tasks.back()[1] + 1);
    for (auto& t : tasks) {
      int start = t[0];
      int end = t[1];
      int d = t[2];
      d -= accumulate(run.begin() + start,
                      run.begin() + end + 1);  // remove running time
      for (int i = end; d > 0; i--) {
        if (run[i] == 0) {
          run[i] = 1;  // run
          d--;
          ans++;
        }
      }
    }
    return ans;
  }

  /// The follow is another solution
  vector<int> cnt_, todo_;
  void Do(int o, int l, int r) {
    cnt_[o] = r - l + 1;
    todo_[o] = 1;
  }

  void Spread(int o, int l, int m, int r) {
    if (todo_[o] != 0) {
      Do(o * 2, l, m);
      Do(o * 2 + 1, m + 1, r);
      todo_[o] = 0;
    }
  }

  // query L and R
  auto Query(int o, int l, int r, int L, int R) -> int {
    if (L <= l && r <= R) {
      return cnt_[o];
    }
    int m = (l + r) / 2;
    Spread(o, l, m, r);
    if (m >= R) {
      return Query(o * 2, l, m, L, R);
    }
    if (m < L) {
      return Query(o * 2 + 1, m + 1, r, L, R);
    }
    return Query(o * 2, l, m, L, R) + Query(o * 2 + 1, m + 1, r, L, R);
  }

  void Update(int o, int l, int r, int L, int R, int& suffix) {
    int size = r - l + 1;
    if (cnt_[o] == size) {
      return;
    }
    if (L <= l && r <= R && size - cnt_[o] <= suffix) {
      suffix -= size - cnt_[o];
      Do(o, l, r);
      return;
    }
    int m = (l + r) / 2;
    Spread(o, l, m, r);
    if (m < R) {
      Update(o * 2 + 1, m + 1, r, L, R, suffix);
    }  // update right subtree
    if (suffix != 0) {
      Update(o * 2, l, m, L, R, suffix);
    }  // update left subtree
    cnt_[o] = cnt_[o * 2] + cnt_[o * 2 + 1];
  }
  /**
   * @brief use tree to solve
   * Time: O(nlogn + nlog U), n = len(tasks), U = max(end)
   * Space: O(U)
   *
   * @param tasks
   * @return int
   */
  auto FindMinimumTimeTree(vector<vector<int>>& tasks) -> int {
    // ranges::sort(tasks, [](auto& lhs, auto& rhs) { return lhs[1] < rhs[1];
    // });
    sort(tasks.begin(), tasks.end(),
         [&](auto& lhs, auto& rhs) { return lhs[1] < rhs[1]; });
    int u = tasks.back()[1];
    int m = 2 << (32 - __builtin_clz(u));
    cnt_.resize(m);
    todo_.resize(m);
    for (auto& t : tasks) {
      int start = t[0];
      int end = t[1];
      int d = t[2];
      d -= Query(1, 1, u, start, end);
      if (d > 0) {
        Update(1, 1, u, start, end, d);
      }
    }
    return cnt_[1];
  }

  /**
   * @brief use Stack + Binary search
   * Time: O(nlog n)
   * Space: O(n)
   *
   * @param tasks
   * @return int
   */
  auto FindMinimumTimeStk(vector<vector<int>>& tasks) -> int {
    sort(tasks.begin(), tasks.end(),
         [&](auto& lhs, auto& rhs) { return lhs[1] < rhs[1]; });
// stk has the left and right points, sum of top and bottom
#include <array>  // Add missing include directive for 'array' header file

    vector<array<int, 3>> stk{{-2, -2, 0}};  // sentinel
    for (auto& t : tasks) {
      int start = t[0];
      int end = t[1];
      int d = t[2];
      auto [_, r, s] =
          *--std::lower_bound(stk.begin(), stk.end(), start,
                              [](const auto& a, int b) { return a[0] < b; });

      d -= stk.back()[2] - s;  // remove the running point
      if (start <= r) {
        d -= r - start + 1;
      }
      if (d <= 0) {
        continue;
      }
      while (end - stk.back()[1] <= d) {
        auto [l, r, _] = stk.back();
        stk.pop_back();
        d += r - l + 1;  // merge
      }
      stk.push_back({end - d + 1, end, stk.back()[2] + d});
    }
    return stk.back()[2];
  }
};