#include <bits/stdc++.h>
using namespace std;

class Solution {

 public:
  /**
   * @brief LC 928 Minimize Malware Spread II
   * 
   * @param graph 
   * @param initial 
   * @return int 
   */
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    unordered_set<int> st(initial.begin(), initial.end());
    vector<int> vis(graph.size());
    int node_id, size;
    function<void(int)> dfs = [&](int x) {
      vis[x] = true;
      size++;
      for (int y = 0; y < graph[x].size(); y++) {
        if (graph[x][y] == 0) {
          continue;
        }
        if (st.count(y)) {
          // update state machine
          if (node_id != -2 && node_id != y) {
            node_id = node_id == -1 ? y : -2;
          }
        } else if (!vis[y]) {
          dfs(y);
        }
      }
    };

    unordered_map<int, int> cnt;
    for (int i = 0; i < graph.size(); i++) {
      if (vis[i] || st.count(i)) {
        continue;
      }
      node_id = -1;
      size = 0;
      dfs(i);
      if (node_id > 0) {  // only find one node in initial
        // delete node_id makes size nodes not infected
        cnt[node_id] += size;
      }
    }

    int max_cnt = 0;
    int min_node_id = 0;
    for (auto [node_id, c] : cnt) {
      if (c > max_cnt || c == max_cnt && node_id < min_node_id) {
        max_cnt = c;
        min_node_id = node_id;
      }
    }

    return cnt.empty() ? *min_element(initial.begin(), initial.end())
                       : min_node_id;
  }
};