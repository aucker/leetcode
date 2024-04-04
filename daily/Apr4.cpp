#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Get the Ancestors object
   * LC2192: all the ancestors in DAG for a node
   * topo sort
   *
   * @param n
   * @param edges
   * @return vector<vector<int>>
   */
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<unordered_set<int>> anc(n);  // store node's ancestors
    vector<vector<int>> e(n);           // neighbor edges
    vector<int> indeg(n);               // indegree
    // preprocess
    for (const auto& edge : edges) {
      e[edge[0]].push_back(edge[1]);
      ++indeg[edge[1]];
    }
    // BFS topo sort
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (!indeg[i]) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : e[u]) {
        // update childs hash table
        anc[v].insert(u);
        for (int i : anc[u]) {
          anc[v].insert(i);
        }
        --indeg[v];
        if (!indeg[v]) {
          q.push(v);
        }
      }
    }

    // get the res
    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++) {
      for (int j : anc[i]) {
        res[i].push_back(j);
      }
      sort(res[i].begin(), res[i].end());
    }
    return res;
  }

  /**
   * @brief LC1614: max nesting dep of parentheses
   * Easy using the stack, basic algorithm (STL)
   *
   * @param s
   * @return int
   */
  int maxDepth(string s) {
    int res = 0;
    int len = s.length();
    stack<char> stk;

    for (int i = 0; i < len; i++) {
      if (s[i] == '(') {
        stk.push(s[i]);
      }
      int tmp = stk.size();
      res = max(res, tmp);

      if (s[i] == ')') {
        stk.pop();
      }
    }

    return res;
  }
};