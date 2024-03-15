#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /* 120. Triangle */
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      // first column can only be reached from the previous row's first column
      dp[i][0] = dp[i - 1][0] + triangle[i][0];
      for (int j = 1; j < i; ++j) {
        // middle columns can be reached from either top or top-left
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }
      //
      dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }

  /* 64: min sum path */
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < row; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < col; ++j) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[row - 1][col - 1];
  }

  /* 63. Unique Paths II */
  int uniquePathWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size(), col = obstacleGrid.at(0).size();
    vector<int> dp(col, 0);
    dp[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[j] = 0;
          continue;
        }
        if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
          dp[j] += dp[j - 1];
        }
      }
    }
    return dp.back();
  }

  /**
   * @brief Unique Paths III is a backtracking problem.
   * 980. Unique Paths III
   *
   * @param grid
   * @return int
   */
  int uniquePathsIII(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    int start_x, start_y, end_x, end_y, empty = 1;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1) {
          start_x = i;
          start_y = j;
        } else if (grid[i][j] == 2) {
          end_x = i;
          end_y = j;
        } else if (grid[i][j] == 0) {
          empty++;
        }
      }
    }
  }

  /**
   * @brief Interleave String is DP problem
   * 97. Interleaving String
   *
   */
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    if (len1 + len2 != len3) return false;

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= len1; ++i) {
      for (int j = 0; j <= len2; ++j) {
        int p = i + j - 1;
        if (i > 0) {
          dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
        }
        if (j > 0) {
          dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
        }
      }
    }
    return dp[len1][len2];
  }

  /**
   * @brief  maximal square is a DP problem
   * 221. Maximal Square
   *
   * @param matrix
   * @return int
   */
  int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    if (row == 0 || col == 0) return 0;
    int maxSide = 0;
    vector<vector<int>> dp(row, vector<int>(col));

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] =
                min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
          }
          maxSide = max(maxSide, dp[i][j]);
        }
      }
    }
    int ans = maxSide * maxSide;
    return ans;
  }

  /**
   * @brief best time to buy and sell the stock I DP
   *
   * @param prices
   * @return int
   */
  int maxProfitI(vector<int>& prices) {
    int n = prices.size();
    int buy = -prices[0];
    int sell = 0;
    for (int i = 0; i < n; ++i) {
      // in buy, we get the min possible value
      buy = max(buy, -prices[i]);
      // to get the max profit, we hope to the min buy and max sell
      // that's why we use max here
      sell = max(sell, prices[i] + buy);
    }
    return sell;
  }

  /**
   * @brief another way to solve maxProfitI problem
   * For every iteration, we hope to get the min price and max profit
   * At the I-th day, there are two states we can be in for the profit:
   * 1. We don't buy the stock yet, we don't have any profit
   * 2. We buy the stock, we hope the price is low enough
   * 3. We sold the stock before, we hope the price is high enough, so we can
   * still get the max profit
   * 4. We sold the stock today, we hope to get the max profit
   *
   * The profit is curr day price - min price
   * as we iterate through the array, we either already have the max profit
   * before, or we hope to get the max profit so the transition function is:
   * dp[i] = max(dp[i-1], prices[i] - minPrice)
   *
   * @param prices
   * @return int
   */
  int maxProfitI_2(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n, 0);
    int minPrice = prices[0];

    for (int i = 1; i < n; ++i) {
      minPrice = min(minPrice, prices[i]);
      dp[i] = max(dp[i - 1], prices[i] - minPrice);
    }
    return dp[n - 1];
  }
  /**
   * @brief We analyze the problem of two ways:
   * the second way use a array to store the max profit, the there will be extra
   * memory overhead, with time and space complexity of both O(n) The first way
   * use two variables to store the max profit, we still traverse the array
   * once, but we don't use extra space, so for the memory sensitive case, the
   * first way is better
   *
   */

  /**
   * @brief best time to buy and sell the stock II Greedy
   *
   * @param prices
   * @return int
   */
  int maxProfitII(vector<int>& prices) {
    int n = prices.size();
    int start = 0;
    int max = 0;
    for (int i = 0; i < n; ++i) {
      if (prices[i] > start) {
        max += prices[i] - start;
      }
      start = prices[i];
    }
    return max;
  }

  /**
   * @brief best time to buy and sell the stock III DP
   * 123. Best time to Buy and sell stock
   *
   * @param prices
   * @return int
   */
  int maxProfitIII(vector<int>& prices) {
    int n = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 0; i < n; ++i) {
      buy1 = max(buy1, -prices[i]);
      sell1 = max(sell1, buy1 + prices[i]);
      buy2 = max(buy1, sell1 - prices[i]);
      sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
  }

  /**
   * @brief  Best time to buy and sell IV
   *
   * @param prices, k
   * @return int
   */
  int maxProfitIV(int k, vector<int>& prices) {
    if (prices.empty()) return 0;
    int n = prices.size();

    k = min(k, n / 2);
    vector<vector<int>> buy(n, vector<int>(k + 1));
    vector<vector<int>> sell(n, vector<int>(k + 1));

    // the first idx is the day number
    // the second idx is the txn number
    buy[0][0] = -prices[0];
    sell[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
      // INT_MIN / 2 here to prevent overflow
      buy[0][i] = sell[0][i] = INT_MIN / 2;
    }

    for (int i = 1; i < n; ++i) {
      buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
      for (int j = 1; j <= n; ++j) {
        buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
        sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
      }
    }
    return *max_element(sell[n - 1].begin(), sell[n - 1].end());
  }
};