#include <functional>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * @brief LC weekly: Bitwise ops
   * Bitwise OR(|) and Shifts(>>): fills all bits to the right of
   * the highest set bit with ones.
   * @param n
   * @return int
   */
  int smallestNumber(int n) {
    int num = n;
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;

    return num;
  }

  /**
   * @brief LC51: NQueen
   * Backtrack
   *
   * @param n
   * @return vector<vector<string>>
   */
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> col(n), on_path(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
    function<void(int)> dfs = [&](int r) {
      // traverse the last row, end
      if (r == n) {
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
          board[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
        }
        ans.emplace_back(board);
        return;
      }

      // just traverse every row & col
      for (int c = 0; c < n; c++) {
        int rc = r - c + n - 1;
        if (!on_path[c] && !diag1[r + c] && !diag2[rc]) {
          col[r] = c;
          // place at pos
          on_path[c] = diag1[r + c] = diag2[rc] = true;
          // go to next row w/ backtrack
          dfs(r + 1);
          // recover by undo
          on_path[c] = diag1[r + c] = diag2[rc] = false;
        }
      }
    };
    // from first row: row 0
    dfs(0);
    return ans;
  }

  /**
   * @brief LC1564: Greedy Algo: basic version
   * but resize the warehouse vector
   * Time: O(NlogN), Space: O(1)
   *
   * @param boxes
   * @param warehouse
   * @return int
   */
  int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
    // preprocess warehouse height
    for (int i = 1; i < warehouse.size(); i++) {
      warehouse[i] = min(warehouse[i - 1], warehouse[i]);
    }

    sort(boxes.begin(), boxes.end());
    int ans = 0;
    for (int i = warehouse.size() - 1; i >= 0; i--) {
      if (ans < boxes.size() && boxes[ans] <= warehouse[i]) {
        ans++;
      } }
    return ans;
  }
  /**
   * @brief Refined version of Greedy Algo
   * Time: O(NlogN + m), Space: O(1)
   *
   * @param boxes
   * @param warehouse
   * @return int
   */
  int maxBoxesInWarehouse2(vector<int>& boxes, vector<int>& warehouse) {
    int i = boxes.size() - 1;
    int ans = 0;
    sort(boxes.begin(), boxes.end());
    for (int room : warehouse) {
      // drop boxes not fit
      while (i >= 0 && boxes[i] > room) {
        i--;
      }
      if (i == -1) {
        return ans;
      }
      ans++;
      i--;
    }
    return ans;
  }
};
