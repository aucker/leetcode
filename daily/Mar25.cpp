#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  /**
   * @brief LC442: Find All duplicates in an array
   * use STL is slow, we use the map here
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> findDuplicates(vector<int>& nums) {
    map<int, int> seen;
    vector<int> ans;
    for (auto it = seen.begin(); it != seen.end(); ++it) {
      if (it->second > 1) {
        ans.push_back(it->first);
      }
    }
    return ans;
  }

  vector<int> findDuplicatesFast(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      int idx = abs(nums[i]) - 1;
      // already marked as seen
      if (nums[idx] < 0) {
        ans.push_back(idx + 1);
      }

      // mark this val as seen
      nums[idx] *= -1;
    }

    return ans;
  }

  /**
   * @brief LC 572: Subtree of Another tree
   * First use the DFS to check if there is a node that
   * make it equals to the subtree
   * So time complexity is O(|root| X |subRoot|)
   * space complexity is O(max{d_root, d_subRoot})
   *
   * @param root
   * @param subRoot
   * @return true
   * @return false
   */
  bool isSubtreeDFS(TreeNode* root, TreeNode* subRoot) {
    return dfs(root, subRoot);
  }

 private:
  /**
   * This is helper function for isSubtree problem
   */
  bool check(TreeNode* o, TreeNode* t) {
    if (!o && !t) return true;

    if ((!o && t) || (o && !t) || o->val != t->val) {
      return false;
    }
    return check(o->left, t->left) && check(o->right, t->right);
  }

  /**
   * This is dfs for isSubtree problem
   */
  bool dfs(TreeNode* o, TreeNode* t) {
    if (!o) return false;
    return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
  }
};

class DFS_KMP {
 public:
  vector<int> sOrder, tOrder;
  int maxElement, lNull, rNull;

  void getMaxElement(TreeNode* o) {
    if (!o) return;
    maxElement = max(maxElement, o->val);
    getMaxElement(o->left);
    getMaxElement(o->right);
  }

  void getDfsOrder(TreeNode* o, vector<int>& tar) {
    if (!o) return;
    tar.push_back(o->val);
    if (o->left) {
      getDfsOrder(o->left, tar);
    } else {
      tar.push_back(lNull);
    }
    if (o->right) {
      getDfsOrder(o->right, tar);
    } else {
      tar.push_back(rNull);
    }
  }

  bool kmp() {
    int sLen = sOrder.size(), tLen = tOrder.size();
    vector<int> fail(tOrder.size(), -1);
    for (int i = 1, j = -1; i < tLen; ++i) {
      while (j != -1 && tOrder[i] != tOrder[j + 1]) {
        j = fail[j];
      }
      if (tOrder[i] == tOrder[j + 1]) {
        ++j;
      }

      fail[i] = j;
    }

    for (int i = 0, j = -1; i < sLen; ++i) {
      while (j != -1 && sOrder[i] != tOrder[j + 1]) {
        j = fail[j];
      }
      if (sOrder[i] == tOrder[j + 1]) {
        ++j;
      }
      if (j == tLen - 1) {
        return true;
      }
    }
    return false;
  }
  /**
   * @brief We use KMP to
   *
   * @param root
   * @param subRoot
   * @return true
   * @return false
   */
  bool isSubTreeDfsKMP(TreeNode* root, TreeNode* subRoot) {
    maxElement = INT_MIN;
    getMaxElement(root);
    getMaxElement(subRoot);
    lNull = maxElement + 1;
    rNull = maxElement + 2;

    getDfsOrder(root, sOrder);
    getDfsOrder(subRoot, tOrder);

    return kmp();
  }
};

class DFS_Hash {
 public:
  static constexpr int MAX_N = 1000 + 5;
  static constexpr int MOD = int(1e9) + 7;

  bool vis[MAX_N];
  int p[MAX_N], tot;
  void getPrime() {
    vis[0] = vis[1] = 1;
    tot = 0;
    for (int i = 2; i < MAX_N; ++i) {
      if (!vis[i]) p[++tot] = i;
      for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
        vis[i * p[j]] = 1;
        if (i % p[j] == 0) break;
      }
    }
  }

  struct Status {
    int f, s;  // f is hashvalue, s is size of subtree
    Status(int f_ = 0, int s_ = 0) : f(f_), s(s_) {}
  };

  unordered_map<TreeNode*, Status> hS, hT;

  void dfs(TreeNode* o, unordered_map<TreeNode*, Status>& h) {
    h[o] = Status(o->val, 1);
    if (!o->left && !o->right) return;
    if (o->left) {
      dfs(o->left, h);
      h[o].s += h[o->left].s;
      h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
    }
    if (o->right) {
      dfs(o->right, h);
      h[o].s += h[o->right].s;
      h[o].f =
          (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
    }
  }

  bool isSubtree(TreeNode* s, TreeNode* t) {
    getPrime();
    dfs(s, hS);
    dfs(t, hT);

    int tHash = hT[t].f;
    for (const auto& [k, v] : hS) {
      if (v.f == tHash) {
        return true;
      }
    }
    return false;
  }
};

class Word_Pattern {
 public:
  /**
   * @brief LC290: Word Pattern
   * We just iterator the hashtable
   * for char and string, we have 2 hashtable
   *
   * @param pattern
   * @param str
   * @return true
   * @return false
   */
  bool wordPattern(string pattern, string str) {
    unordered_map<string, char> str2ch;
    unordered_map<char, string> ch2str;
    int m = str.length();
    int i = 0;
    for (auto ch : pattern) {
      if (i >= m) {
        return false;
      }

      int j = i;
      while (j < m && str[j] != ' ') j++;
      const string& tmp = str.substr(i, j - i);
      if (str2ch.count(tmp) && str2ch[tmp] != ch) {
        return false;
      }
      if (ch2str.count(ch) && ch2str[ch] != tmp) {
        return false;
      }

      str2ch[tmp] = ch;
      ch2str[ch] = tmp;
      i = j + 1;
    }

    return i >= m;
  }
};