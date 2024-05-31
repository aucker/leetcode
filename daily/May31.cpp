#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  /**
   * @brief use vector to store the whole value
   * when n is large, this is slow, O(N^2)
   * So, There does seem to be a O(1) solution. Sure!
   *
   * @param grid
   * @return vector<int>
   */
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> appear(n * n + 1, 0);
    appear[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        appear[grid[i][j]]++;
      }
    }
    int a = 0, b = 0;
    for (int i = 0; i < appear.size(); i++) {
      if (appear[i] == 2) {
        a = i;
      }
      if (appear[i] == 0) {
        b = i;
      }
    }
    return {a, b};
  }

  /**
   * @brief use the bit ops, this is much faster
   * O(1), 1 and 3 bit ops is 1
   *
   * @param grid
   * @return vector<int>
   */
  vector<int> findMissingAndRepeatedValuesOp(vector<vector<int>>& grid) {
    int n = grid.size();
    int xor_all = 0;
    for (auto& row : grid) {
      for (int x : row) {
        xor_all ^= x;
      }
    }
    xor_all ^= n % 2 ? 1 : n * n;
    int shift = __builtin_ctz(xor_all);

    vector<int> ans(2);
    for (int x = 1; x <= n * n; x++) {
      ans[x >> shift & 1] ^= x;
    }
    for (auto& row : grid) {
      for (int x : row) {
        ans[x >> shift & 1] ^= x;
      }
    }

    for (auto& row : grid) {
      // if (row.find(ans[0]) != row.end()) {
      if (std::find(row.begin(), row.end(), ans[0]) != row.end()) {
        return ans;
      }
    }
    return {ans[1], ans[0]};
  }

  /**
   * @brief LC:248 Strobogrammatic Number III
   * Time: O(5^(m/2) + 5^(n/2))
   * Space: O(5^(m/2) + 5^(n/2))
   *
   * @param low
   * @param high
   * @return int
   */
  int strobogrammaticInRange(string low, string high) {
    int lowLength = low.length(), highLength = high.length();
    if (lowLength > highLength ||
        (lowLength == highLength && low.compare(high) > 0)) {
      return 0;
    }

    if (lowLength == highLength) {
      auto strobogrammatics = findStrobogrammatic(lowLength);
      int lowIndex = binarySearch(strobogrammatics, low);
      lowIndex = lowIndex < 0 ? -lowIndex - 1 : lowIndex;
      int highIndex = binarySearch(strobogrammatics, high);
      highIndex = highIndex < 0 ? -highIndex - 2 : highIndex;
      return highIndex - lowIndex + 1;
    } else {
      int count = 0;
      for (int i = lowLength + 1; i < highLength; i++) {
        count += countStrobogrammatic(i);
      }
      auto lowStrobogrammatics = findStrobogrammatic(lowLength);
      auto highStrobogrammatics = findStrobogrammatic(highLength);
      int lowIndex = binarySearch(lowStrobogrammatics, low);
      lowIndex = lowIndex < 0 ? -lowIndex - 1 : lowIndex;
      count += lowStrobogrammatics.size() - lowIndex;
      int highIndex = binarySearch(highStrobogrammatics, high);
      highIndex = highIndex < 0 ? -highIndex - 2 : highIndex;
      count += highIndex + 1;
      return count;
    }
  }

  int binarySearch(const vector<string>& list, const string& key) {
    int low = 0, high = list.size() - 1;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      string str = list[mid];
      if (str == key) {
        return mid;
      } else if (str > key) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -low - 1;
  }

  vector<string> findStrobogrammatic(int n) {
    auto findStrobogrammaticWithZero = [&](int n) {
      queue<string> queue;
      int start = n % 2 == 1 ? 1 : 2;
      if (start == 1) {
        queue.push("0");
        queue.push("1");
        queue.push("8");
      } else {
        queue.push("00");
        queue.push("11");
        queue.push("69");
        queue.push("88");
        queue.push("96");
      }
      for (int i = start; i < n; i += 2) {
        int size = queue.size();
        for (int j = 0; j < size; j++) {
          string prevStrobogrammatic = queue.front();
          queue.pop();
          queue.push("0" + prevStrobogrammatic + "0");
          queue.push("1" + prevStrobogrammatic + "1");
          queue.push("6" + prevStrobogrammatic + "9");
          queue.push("8" + prevStrobogrammatic + "8");
          queue.push("9" + prevStrobogrammatic + "6");
        }
      }
      vector<string> strobogrammatics;
      while (!queue.empty()) {
        strobogrammatics.push_back(queue.front());
        queue.pop();
      }
      return strobogrammatics;
    };

    auto strobogrammatics = findStrobogrammaticWithZero(n);
    if (n == 1) {
      return strobogrammatics;
    }
    strobogrammatics.erase(
        remove_if(strobogrammatics.begin(), strobogrammatics.end(),
                  [](const string& s) { return s[0] == '0'; }),
        strobogrammatics.end());
    sort(strobogrammatics.begin(), strobogrammatics.end());
    return strobogrammatics;
  }

  int countStrobogrammatic(int n) {
    if (n == 1) {
      return 3;
    } else if (n == 2) {
      return 4;

    } else if (n == 3) {
      return 12;
    } else {
      int difference = n % 2 == 0 ? n - 2 : n - 3;
      return n % 2 == 0 ? 4 * pow(5, difference / 2)
                        : 12 * pow(5, difference / 2);
    }
  }
};
