#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Fenwick {
  vector<int> tree;

 public:
  Fenwick(int n) : tree(n) {}

  // increase 1 for label i
  void add(int i) {
    while (i < tree.size()) {
      tree[i]++;
      i += i & -i;
    }
  }

  // return sum of label [1, i]
  int pre_sum(int i) {
    int res = 0;
    while (i > 0) {
      res += tree[i];
      i &= i - 1;
    }
    return res;
  }
};

class Solution {
 public:
  /**
   * LC:3072: Distribute Elements into two arrays II
   * Time: O(NlogN), Space: O(N)
   *
   */
  vector<int> resultArray(vector<int>& nums) {
    auto sorted = nums;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();

    vector<int> a{nums[0]}, b{nums[1]};
    Fenwick t1(m + 1), t2(m + 1);

    auto it = lower_bound(sorted.begin(), sorted.end(), nums[0]);
    t1.add(distance(sorted.begin(), it) + 1);
    it = lower_bound(sorted.begin(), sorted.end(), nums[1]);
    t2.add(distance(sorted.begin(), it) + 1);

    for (int i = 2; i < nums.size(); i++) {
      int x = nums[i];
      int v = distance(sorted.begin(),
                       lower_bound(sorted.begin(), sorted.end(), x) + 1);
      int gc1 = a.size() - t1.pre_sum(v);  // greaterCount(a, v)
      int gc2 = b.size() - t2.pre_sum(v);  // greaterCount(b, v)
      if (gc1 > gc2 || gc1 == gc2 && a.size() <= b.size()) {
        a.push_back(x);
        t1.add(v);
      } else {
        b.push_back(x);
        t2.add(v);
      }
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }

  string clearStars(string s) {
    /**
     * LC: contest 400-3: Lexicographically min string after removing stars
     * min heap
     * Time: O(n*log(26)) = O(n)
     * Space: O(26) + O(2*n) = O(n)
     *
     */
    priority_queue<char, vector<char>, greater<char>> pq;
    vector<vector<int>> indices(26, vector<int>());
    char ch;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*') {
        ch = pq.top();
        s[indices[ch - 'a'].back()] = '!';
        indices[ch - 'a'].pop_back();
        if (indices[ch - 'a'].size() == 0) {
          pq.pop();
        }
        continue;
      }
      if (indices[s[i] - 'a'].size() == 0) {
        pq.push(s[i]);
      }
      indices[s[i] - 'a'].push_back(i);
    }

    string res = "";
    for (char c : s) {
      if (c >= 'a') {
        res += c;
      }
    }
    return res;
  }
};
