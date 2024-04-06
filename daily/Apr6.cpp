#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
  vector<int> depth;
  vector<vector<int>> pa;

 public:
  TreeAncestor(vector<pair<int, int>>& edges) {
    int n = edges.size() + 1;
    int m = 32 - __builtin_clz(n);  // n binary size
    vector<vector<int>> g(n);
    for (auto [x, y] : edges) {  // node from 0
      g[x].push_back(y);
      g[y].push_back(x);
    }

    depth.resize(n);
    pa.resize(n, vector<int>(m, -1));
    function<void(int, int)> dfs = [&](int x, int fa) {
      pa[x][0] = fa;
      for (int y : g[x]) {
        if (y != fa) {
          depth[y] = depth[x] + 1;
          dfs(y, x);
        }
      }
    };

    dfs(0, -1);

    for (int i = 0; i < m - 1; i++) {
      for (int x = 0; x < n; x++) {
        if (int p = pa[x][i] && p != -1) {
          pa[x][i + 1] = pa[p][i];
        }
      }
    }
  }

  int get_kth_ancestor(int node, int k) {
    for (; k; k &= k - 1) {
      node = pa[node][__builtin_ctz(k)];
    }
    return node;
  }

  // return x , y 's lca from 0
  int get_lca(int x, int y) {
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    // make x and y in same depth
    y = get_kth_ancestor(y, depth[y] - depth[x]);
    if (y == x) {
      return x;
    }
    for (int i = pa[x].size() - 1; i >= 0; i--) {
      int px = pa[x][i], py = pa[y][i];
      if (px != py) {
        x = px;
        y = py;
      }
    }

    return pa[x][0];
  }
};

class TreeAncestor1 {
  vector<vector<int>> pa;

 public:
  TreeAncestor1(int n, vector<int>& parent) {
    int m = 32 - __builtin_clz(n);  // n binary size
    pa.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      pa[i][0] = parent[i];
    }
    for (int i = 0; i < m - 1; i++) {
      for (int x = 0; x < n; x++) {
        if (int p = pa[x][i]; p != -1) {
          pa[x][i + 1] = pa[p][i];
        }
      }
    }
  }

  int getKthAncestor(int node, int k) {
    int m = 32 - __builtin_clz(k);  // k binary size
    for (int i = 0; i < m; i++) {
      if ((k >> i) && 1) {  //
        node = pa[node][i];
        if (node < 0) break;
      }
    }
    return node;
  }

  int getKthAncestor1(int node, int k) {
    for (; k && node != -1; k &= k - 1) {
      node = pa[node][__builtin_ctz(k)];
    }
    return node;
  }
};

// class BFS {
// 	public:
// 	int BFSTemplate(Node* start, Node* end) {
// 		queue<Node*> q;  // core ds
// 		set<Node*> visited;  // avoid repeat

// 		q.push(start);  // enqueue the start node
// 		visited.insert(start);
// 		int step = 0;  // record the steps that has expanded

// 		while (!q.empty()) {
// 			int sz = q.size();
// 			/* all the node in the queue expand  */
// 			for (int i = 0; i < sz; i++) {
// 				Node* cur = q.pop();

// 				/* check if arrived at the end node */
// 				if (cur == target) {
// 					return step;
// 				}
// 				/* enqueue the cur adjecent node */
// 				for (Node* x : cur.adj()) {
// 					if (visited.find(x) == visited.end()) {
// 						q.push(x);
// 						visited.insert(x);
// 					}
// 				}
// 			}
// 			step++;
// 		}
// 	}
// };

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class BFS {
 public:
  /**
   * @brief LC111. The min depth of binary tree
   *
   * @param root
   * @return int
   */
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, int>> q;
    q.emplace(root, 1);

    while (!q.empty()) {
      TreeNode* node = q.front().first;
      int depth = q.front().second;
      q.pop();
      if (node->left == nullptr && node->right == nullptr) {
        return depth;
      }
      if (node->left) {
        q.emplace(node->left, depth + 1);
      }
      if (node->right) {
        q.emplace(node->right, depth + 1);
      }
    }
    return 0;
  }
};

struct Node {
  int key, val;
  int freq;
  Node* prev;
  Node* next;
  Node() : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
  Node(int key_, int val_)
      : key(key_), val(val_), freq(1), prev(nullptr), next(nullptr) {}
};

struct FreqList {
  int freq;
  Node* vhead;
  Node* vtail;
  FreqList(int f_) : freq(f_) {
    vhead = new Node();
    vtail = new Node();
    vhead->next = vtail;
    vtail->prev = vhead;
  }
};

/* LFU implementation */
class LFUCache {
  unordered_map<int, Node*> cache;
  unordered_map<int, FreqList*> freq_map;
  int size;
  int min_freq;

 public:
  LFUCache(int capacity_) : size(capacity_) {}

  bool isEmpty(FreqList* list) {
    return list->vhead->next == list->vtail ? true : false;
  }

  void deleteNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addHead(Node* node) {
    int freq = node->freq;
    if (freq_map.find(freq) == freq_map.end()) {
      // not find this freq
      freq_map[freq] = new FreqList(freq);
    }

    FreqList* list = freq_map[freq];
    node->next = list->vhead->next;
    node->prev = list->vhead->next->prev;
    list->vhead->next->prev = node;
    list->vhead->next = node;
  }

  void popTail() {
    Node* node = freq_map[min_freq]->vtail->prev;
    deleteNode(node);
    cache.erase(node->key);
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      // find this
      Node* node = cache[key];
      res = node->val;
      deleteNode(node);
      node->freq++;
      if (isEmpty(freq_map[min_freq])) min_freq++;
      addHead(node);  // move this node to head
    }

    return res;
  }

  void put(int key, int value) {
    if (size == 0) return;
    if (get(key) != -1) {
      cache[key]->val = value;
    } else {
      if (cache.size() == size) {
        popTail();  // cache is full, need to remove some
      }
      Node* node = new Node(key, value);
      cache[key] = node;  // add the cache
      min_freq = 1;       // new node freq will be 1
      addHead(node);
    }
  }
};