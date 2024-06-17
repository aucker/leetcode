#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 261: Graph Valid Tree [M]
   * Sln1: Iterative DFS: Time: O(N+E)
   *
   * @param n
   * @param edges
   * @return true
   * @return false
   */
  bool validTreeIterativeDFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) {
      return false;
    }

    vector<vector<int>> adj_list(n);
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }

    unordered_map<int, int> parent;
    parent[0] = -1;
    stack<int> stk;
    stk.push(0);
    while (!stk.empty()) {
      int node = stk.top();
      stk.pop();
      for (int neighbour : adj_list[node]) {
        if (neighbour == parent[node]) {
          continue;
        }
        if (parent.find(neighbour) != parent.end()) {
          // exist before, indegree gt 1
          return false;
        }
        parent[neighbour] = node;
        stk.push(neighbour);
      }
    }
    return parent.size() == n;
  }

  bool validTreeRecursiveDFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) {
      return false;
    }
    vector<vector<int>> adj_list(n);
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }
    unordered_set<int> seen;

    function<bool(int, int, const vector<vector<int>>&, unordered_set<int>&)>
        dfs = [&](int node, int parent, const vector<vector<int>>& adj_list,
                  unordered_set<int>& seen) -> bool {
      if (seen.count(node)) {
        // indegree gt 1
        return false;
      }
      seen.insert(node);
      for (int neighbour : adj_list[node]) {
        if (neighbour == parent) {
          continue;
        }
        if (seen.count(neighbour)) {
          return false;
        }
        if (!dfs(neighbour, node, adj_list, seen)) {
          return false;
        }
      }
      return true;
    };

    return dfs(0, -1, adj_list, seen) && seen.size() == n;
  }

  bool validTreeIterBFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj_list(n);
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }

    unordered_map<int, int> parent;
    parent[0] = -1;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (int neighbour : adj_list[node]) {
        if (neighbour == parent[node]) continue;
        if (parent.find(neighbour) != parent.end()) return false;
        parent[neighbour] = node;
        q.push(neighbour);
      }
    }
    return parent.size() == n;
  }

  bool validTreeGraphIterDFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj_list(n);
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }

    unordered_set<int> seen = {0};
    stack<int> stk;
    stk.push(0);
    while (!stk.empty()) {
      int node = stk.top();
      stk.pop();
      for (int neighbour : adj_list[node]) {
        if (seen.count(neighbour)) continue;
        seen.insert(neighbour);
        stk.push(neighbour);
      }
    }
    return seen.size() == n;
  }

  bool validTreeGraphRecurDFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj_list(n);
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }

    function<void(int, const vector<vector<int>>&, unordered_set<int>&)> dfs =
        [&](int node, const vector<vector<int>>& adj_list,
            unordered_set<int>& seen) {
          if (seen.count(node)) return;
          seen.insert(node);
          for (int neighbour : adj_list[node]) {
            dfs(neighbour, adj_list, seen);
          }
        };

    unordered_set<int> seen;
    dfs(0, adj_list, seen);
    return seen.size() == n;
  }

  // void dfs(int node, const vector<vector<int>>& adj_list, unordered_set<int>&
  // seen) {
  //   if (seen.count(node)) return;
  //   seen.insert(node);
  //   for (int neighbour : adj_list[node]) {
  //     dfs(neighbour, adj_list, seen);
  //   }
  // }

  bool validTreeGraphIterBFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<vector<int>> adj_list(n);
    for (const auto& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }
    unordered_set<int> seen = {0};
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (int neighbour : adj_list[node]) {
        if (seen.count(neighbour)) continue;
        seen.insert(neighbour);
        q.push(neighbour);
      }
    }

    return seen.size() == n;
  }

  /**
   * @brief LC: 522: Longest Uncommon Subsequence II
   * Time: O(N^2 * m), N: strs.size(), m: strs[i].size()
   * Space: O(1)
   *
   * @param strs
   * @return int
   */
  int findLUSlength(vector<string>& strs) {
    auto is_subseq = [](const string& lhs, const string& rhs) -> bool {
      int pt_lhs = 0, pt_rhs = 0;
      while (pt_lhs < lhs.size() && pt_rhs < rhs.size()) {
        if (lhs[pt_lhs] == rhs[pt_rhs]) {
          ++pt_lhs;
        }
        ++pt_rhs;
      }
      return pt_lhs == lhs.size();
    };

    function<bool(const string&, const string&)> is_subseqq =
        [&](const string& lhs, const string& rhs) {
          int pt_lhs = 0, pt_rhs = 0;
          while (pt_lhs < lhs.size() && pt_rhs < rhs.size()) {
            if (lhs[pt_lhs] == rhs[pt_rhs]) {
              ++pt_lhs;
            }
            ++pt_rhs;
          }
          return pt_lhs == lhs.size();
        };

    int len = strs.size();
    int ans = -1;
    for (int i = 0; i < len; i++) {
      bool check = true;
      for (int j = 0; j < len; j++) {
        if (i != j && is_subseqq(strs[i], strs[j])) {
          check = false;
          break;
        }
      }
      if (check) {
        ans = max(ans, static_cast<int>(strs[i].size()));
      }
    }
    return ans;
  }
};

class UnionFind {
 public:
  UnionFind(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int A) {
    while (A != parent[A]) {
      A = parent[A];
    }
    return A;
  }

  bool unionSets(int A, int B) {
    int root_A = find(A);
    int root_B = find(B);
    if (root_A == root_B) {
      return false;
    }
    parent[root_A] = root_B;
    return true;
  }

 private:
  vector<int> parent;
};

class UnionFindOP {
 private:
  vector<int> parent;
  vector<int> size;

 public:
  UnionFindOP(int n) : parent(n), size(n, 1) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int A) {
    int root = A;
    while (root != parent[root]) {
      root = parent[root];
    }
    while (A != root) {
      int oldRoot = parent[A];
      parent[A] = root;
      A = oldRoot;
    }
    return root;
  }

  bool unionSets(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (rootA == rootB) return false;

    if (size[rootA] < size[rootB]) {
      parent[rootA] = rootB;
      size[rootB] += size[rootA];
    } else {
      parent[rootB] = rootA;
      size[rootA] += size[rootB];
    }
    return true;
  }
};

class ValidTree {
 public:
  bool validTreeUF(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) {
      return false;
    }
    UnionFind unionFind(n);
    for (const auto& edge : edges) {
      if (!unionFind.unionSets(edge[0], edge[1])) {
        return false;
      }
    }
    return true;
  }

  bool validTreeUFOP(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) {
      return false;
    }

    UnionFindOP unionFindOP(n);
    for (const auto& edge : edges) {
      if (!unionFindOP.unionSets(edge[0], edge[1])) {
        return false;
      }
    }
    return true;
  }
};
