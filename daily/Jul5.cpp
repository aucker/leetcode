#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 3033: modify the matrix [E]
   * Time: O(N*M), Space: O(N*M)
   *
   * @param matrix
   * @return vector<vector<int>>
   */
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> ans = matrix;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < col; i++) {
      int max = matrix[0][i];
      for (int j = 0; j < row; j++) {
        max = max > matrix[j][i] ? max : matrix[j][i];
      }
      for (int j = 0; j < row; j++) {
        if (ans[j][i] == -1) {
          ans[j][i] = max;
        }
      }
    }
    return ans;
  }
};