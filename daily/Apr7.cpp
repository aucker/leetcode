#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int fa[MAXN], val[MAXN];

class ThroneInheritance {
  unordered_map<string, vector<string>> edges;
  unordered_set<string> dead;
  string king;

 public:
  ThroneInheritance(string kingName) : king{move(kingName)} {}

  void birth(string parentName, string childName) {
    edges[move(parentName)].push_back(move(childName));
  }

  void death(string name) { dead.insert(move(name)); }

  vector<string> getInheritanceOrder() {
    vector<string> ans;

    /* closure to get the string */
    function<void(const string&)> preorder = [&](const string& name) {
      if (!dead.count(name)) {
        ans.push_back(name);
      }
      if (edges.count(name)) {
        for (const string& childName : edges[name]) {
          preorder(childName);
        }
      }
    };

    preorder(king);
    return ans;
  }
};

class Contest392 {
  using ll = long long;

 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int ans = 1, n = nums.size();
    for (int i = 1, j = 1; i < n; i++) {
      if (nums[i] < nums[i - 1])
        j++;
      else
        j = 1;
      ans = max(ans, j);
    }
    // go through this two times
    for (int i = 1, j = 1; i < n; i++) {
      if (nums[i] > nums[i - 1])
        j++;
      else
        j = 1;
      ans = max(ans, j);
    }
    return ans;
  }

  /*  */
  int dis(char p, char q) {
    int d = p - q;
    if (d < 0) d = -d;
    return min(d, 26 - d);
  }

  string getSmallestString(string s, int k) {
    int n = s.length();
    for (int i = 0; i < n && k != 0; i++) {
      char c = 'a';
      while (c <= 'z' && dis(s[i], c) > k) c++;
      if (c > 'z') break;
      k -= dis(s[i], c);
      s[i] = c;
    }
    return s;
  }

  ll minOperationsToMakeMedianK(vector<int>& nums, int k) {
    ll ans = 0;
    int n = nums.size();
    int m = n / 2;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (i < m) {
        if (nums[i] > k) ans += nums[i] - k;
      } else if (i == m)
        ans += abs(nums[i] - k);
      else {
        if (nums[i] < k) ans += k - nums[i];
      }
    }
    return ans;
  }

  int getfa(int x) {
    if (x == fa[x])
      return x;
    else
      return fa[x] = getfa(fa[x]);
  }

  vector<int> minimumCost(int n, vector<vector<int>>& e,
                          vector<vector<int>>& Q) {
    for (int i = 0; i < n; i++) fa[i] = i;
    for (auto& x : e) {
      int p = getfa(x[0]), q = getfa(x[1]);
      if (p != q) fa[p] = q;
    }

    for (int i = 0; i < n; i++) {
      getfa(i);
      val[i] = -1;
    }

    for (auto& x : e) {
      int p = getfa(x[0]);
      if (val[p] == -1)
        val[p] = x[2];
      else
        val[p] &= x[2];
    }
    vector<int> ans;

    for (auto& q : Q) {
      int x = getfa(q[0]), y = getfa(q[1]);
      if (q[0] == q[1])
        ans.push_back(0);
      else {
        if (x == y)
          ans.push_back(val[x]);
        else
          ans.push_back(-1);
      }
    }
    return ans;
  }
};