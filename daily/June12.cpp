#include <bits/stdc++.h>

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <vector>
using namespace std;

class Solution {
 public:
  /**
   * @brief 2806: Account Balance After Rounded Purchase [E]
   * Time: O(1), Space: O(1)
   *
   * @param purchaseAmount
   * @return int
   */
  int accountBalanceAfterPurchase(int purchaseAmount) {
    if ((purchaseAmount % 10) >= 5) {
      return 100 - 10 * (1 + (purchaseAmount / 10));
    } else {
      return 100 - 10 * (purchaseAmount / 10);
    }
  }

  /**
   * @brief 2771: Longest non-decreasing subarray from two arrays [M]
   * DP
   * Time: O(N^2), Space: O(N^2)
   *
   * @param nums1
   * @param nums2
   * @return int
   */
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size();
    vector<vector<int>> nums = {nums1, nums2};
    vector<vector<int>> memo(
        len, vector<int>(2, -1));  // -1 means not through before

    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (i == 0) {
        return 1;
      }

      int& p = memo[i][j];

      if (p != -1) {  // get this before
        return p;
      }
      int res = 1;
      if (nums1[i - 1] <= nums[j][i]) {
        // return dfs(i - 1, 0) + 1;
        res = max(res, dfs(i - 1, 0) + 1);
      }
      if (nums2[i - 1] <= nums[j][i]) {
        res = max(res, dfs(i - 1, 1) + 1);
      }
      p = res;  // cache/memoization
      return res;
    };

    int ans = 0;
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < len; i++) {
        ans = max(ans, dfs(i, j));
      }
    }
    return ans;
  }

  /**
   * @brief
   * Time: O(N), Space: O(N)
   *
   * @param nums1
   * @param nums2
   * @return int
   */
  int maxNonDecreasingLengthV1(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), ans = 1;
    vector<vector<int>> nums = {nums1, nums2};
    vector<vector<int>> f(n, vector<int>(2));
    f[0] = {1, 1};

    for (int i = 1; i < n; i++) {
      f[i] = {1, 1};
      for (int j = 0; j < 2; j++) {
        if (nums1[i - 1] <= nums[j][i]) {
          f[i][j] = f[i - 1][0] + 1;
        }
        if (nums2[i - 1] <= nums[j][i]) {
          f[i][j] = max(f[i][j], f[i - 1][1] + 1);
        }
      }
      ans = max(ans, max(f[i][0], f[i][1]));
    }

    return ans;
  }

  /**
   * @brief
   * Time: O(N), Space: O(1)
   *
   * @param nums1
   * @param nums2
   * @return int
   */
  int maxNonDecreasingLengthV2(vector<int>& nums1, vector<int>& nums2) {
    int ans = 1, n = nums1.size();
    int f0 = 1, f1 = 1;
    for (int i = 1; i < n; i++) {
      int f = 1, g = 1;
      if (nums1[i - 1] <= nums1[i]) {
        f = f0 + 1;
      }
      if (nums2[i - 1] <= nums1[i]) {
        f = max(f, f1 + 1);
      }
      if (nums1[i - 1] <= nums2[i]) {
        g = f0 + 1;
      }
      if (nums2[i - 1] <= nums2[i]) {
        g = max(g, f1 + 1);
      }
      f0 = f;
      f1 = g;
      ans = max(ans, max(f0, f1));
    }

    return ans;
  }
};

class TicTacToe {
  /* size of board */
  int n;

  /* rows[i] = sum of row i */
  vector<int> rows;
  /* cols[j] = sum of col j */
  vector<int> cols;
  /* sum of diagnals */
  int dia1, dia2;

 public:
  // TicTacToe(int n) : rows(n), cols(n) {
  // TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0), dia1(0), dia2(0) {}
  TicTacToe(int n) {
    this->n = n;
    rows.resize(n);
    cols.resize(n);
    dia1 = 0;
    dia2 = 0;
  }

  int move(int row, int col, int player) {
    int cell = 1 == player ? 1 : -1;

    // player wins sun
    int sum = 1 == player ? n : -n;
    // curr sum of row
    rows[row] += cell;
    if (sum == rows[row]) return player;
    // curr sum of col
    cols[col] += cell;
    if (sum == cols[col]) return player;

    // sum of main diagnal
    if (row == col) {
      dia1 += cell;
      if (sum == dia1) return player;
    }
    // sum of sub diagnal
    if (row + col == n - 1) {
      dia2 += cell;
      if (sum == dia2) return player;
    }
    return 0;
  }
};

int main() {
  Solution sln;
  std::vector<int> nums1 = {1, 3, 5, 4};
  std::vector<int> nums2 = {2, 2, 3, 4};
  int res = sln.maxNonDecreasingLength(nums1, nums2);
  cout << "The max non decreasing len is " << endl;

  return 0;
}
