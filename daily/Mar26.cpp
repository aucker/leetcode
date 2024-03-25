#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC743: Network delay time
   * Dijkstra to get the shortest path
   *
   * @param times 2-d array, (u_i, v_i, w_i) (source, target, time)
   * @param n Nodes
   * @param k send signal from node k
   * @return int min time for all node receive signal
   */
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // neighbor matrix
    vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
    for (auto& t : times) {
      // every element is the pos of node with time
      g[t[0] - 1][t[1] - 1] = t[2];
    }

    vector<int> dis(n, INT_MAX / 2), done(n);
    dis[k - 1] = 0;
    while (true) {
      int x = -1;
      for (int i = 0; i < n; ++i) {
        // haven't traverse this node
        if (!done[i] && (x < 0 || dis[i] < dis[x])) {
          x = i;
        }
      }
      if (x < 0) {
        return *max_element(dis.begin(), dis.end());
      }
      if (dis[x] == INT_MAX / 2) {  // some node can't reach
        return -1;
      }
      done[x] = true;  // min path get
      for (int y = 0; y < n; ++y) {
        // update x neighbor shortest path
        dis[y] = min(dis[y], dis[x] + g[x][y]);
      }
    }
  }

  /**
   * @brief This is dumb, of couse we can use hashtable
   * for O(N) of both time and space complexity
   *
   *
   * @param nums
   * @return int
   */
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> cache;
    for (int num : nums) {
      cache[num]++;
    }
    for (int i = 1; i <= n + 1; ++i) {
      if (cache.find(i) == cache.end()) {
        return i;
      }
    }
    return -1;
  }

  int findMissingPositiveOp(vector<int>& nums) {
    int n = nums.size();
    for (int& num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      int num = abs(nums[i]);
      if (num <= n) {
        nums[num - 1] = -abs(nums[num - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }

    return n + 1;
  }
};

class Graph_dijkstra {
 public:
  using pii = pair<int, int>;
  Graph_dijkstra(int n, vector<vector<int>>& edges) {
    this->graph = vector<vector<pii>>(n);
    for (auto& vec : edges) {
      int x = vec[0];
      int y = vec[1];
      int cost = vec[2];
      graph[x].emplace_back(y, cost);
    }
  }

  void addEdge(vector<int> edge) {
    int x = edge[0];
    int y = edge[1];
    int cost = edge[2];
    graph[x].emplace_back(y, cost);
  }

  int shortestPath(int node1, int node2) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(graph.size(), INT_MAX);
    dist[node1] = 0;
    pq.emplace(0, node1);

    while (!pq.empty()) {
      auto [cost, cur] = pq.top();
      pq.pop();
      if (cur == node2) {
        return cost;
      }
      for (auto [next, ncost] : graph[cur]) {
        if (dist[next] > cost + ncost) {
          dist[next] = cost + ncost;
          pq.emplace(cost + ncost, next);
        }
      }
    }
    return -1;
  }

 private:
  vector<vector<pii>> graph;
};

class Graph_Floyed {
 public:
  Graph_Floyed(int n, vector<vector<int>>& edges) {
    dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }
    for (auto& e : edges) {
      dist[e[0]][e[1]] = e[2];
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }

  void addEdge(vector<int> edge) {
    int x = edge[0], y = edge[1], cost = edge[2];
    if (cost >= dist[x][y]) return;

    int n = dist.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][x] != INT_MAX && dist[y][j] != INT_MAX) {
          dist[i][j] = min(dist[i][j], dist[i][x] + cost + dist[y][j]);
        }
      }
    }
  }

  int shortestPath(int node1, int node2) {
    int res = dist[node1][node2];
    return res == INT_MAX ? -1 : res;
  }

 private:
  vector<vector<int>> dist;
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Floyd_cycle {
 public:
  /**
   * LC287: Find the Duplicate Number
   * @brief Find duplicate w/o modifying the list
   * and use the constant extra space
   * This is Floyd cycle detection algorithm
   *
   * @param nums
   * @return int
   */
  int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;
    while (true) {
      fast = nums[nums[fast]];
      slow = nums[slow];
      if (fast == slow) break;
    }
    int slow2 = 0;
    while (true) {
      slow = nums[slow];
      slow2 = nums[slow2];
      if (slow2 == slow) break;
    }

    return slow;
  }

  /**
   * @brief LC142: Linked List Cycle II
   * Use Floyd cycle detection algorithm to solve cycle problem
   *
   * @param head
   * @return ListNode*
   */
  ListNode* detectCycle(ListNode* head) {
    ListNode *fast = head, *slow = head;

    while (true) {
      if (!fast || !fast->next) return nullptr;
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) break;
    }
    ListNode* slow2 = head;
    while (slow2 != slow) {
      slow = slow->next;
      slow2 = slow2->next;
    }
    return slow;
  }
};