#include <queue>
#include <unordered_map>
using namespace std;

struct compare {
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};

class Solution {
  int memo[1001];

 public:
  /**
   * @brief LC1884: Egg drop w/ 2 eggs and N floors
   * DP problem Time: O(N^2), num of states * time of single state
   * Space: O(N)
   *
   * @param n
   * @return int
   */
  int twoEggDrop(int n) {
    if (n == 0) {
      return 0;
    }

    int& res = memo[n];
    if (res) {
      return res;
    }

    res = INT_MAX;
    for (int j = 1; j <= n; j++) {
      res = min(res, max(j, twoEggDrop(n - j) + 1));
    }

    return res;
  }

  /**
   * @brief LC Weekly problem: Find X-Sum of All K-Long Subarrays I
   * Use of minHeap and HashMap
   *
   * @param nums
   * @param k
   * @param x
   * @return vector<int>
   */
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    int len = nums.size();

    vector<int> res(len - k + 1, 0);

    for (int i = 0; i <= len - k; i++) {
      vector<int> slice(nums.begin() + i, nums.begin() + i + k);

      res[i] = topKFreqNumSun(slice, x);
    }

    return res;
  }

 private:
  int topKFreqNumSun(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
      freqMap[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> minHeap;
    for (auto& entry : freqMap) {
      minHeap.push({entry.first, entry.second});

      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    int sum = 0;
    while (k-- && !minHeap.empty()) {
      int num = minHeap.top().first;
      sum += (num * freqMap[num]);
      minHeap.pop();
    }

    return sum;
  }
};
