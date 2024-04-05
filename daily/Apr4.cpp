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

class Automaton {
  string state = "start";
  unordered_map<string, vector<string>> table = {
      {"start", {"start", "signed", "in_number", "end"}},
      {"signed", {"end", "end", "in_number", "end"}},
      {"in_number", {"end", "end", "in_number", "end"}},
      {"end", {"end", "end", "end", "end"}},
  };

  int get_col(char c) {
    if (isspace(c)) return 0;
    if (c == '+' || c == '-') return 1;
    if (isdigit(c)) return 2;
    return 3;
  }

 public:
  int sign = 1;
  long long ans = 0;

  void get(char c) {
    state = table[state][get_col(c)];
    if (state == "in_number") {
      ans = ans * 10 + c - '0';
    } else if (state == "signed") {
      sign = c == '+' ? 1 : -1;
    }
  }
};

class Solution2 {
 public:
  /**
   * @brief Impl the Atoi
   *
   * @param s
   * @return int
   */
  int myAtoi(string s) {
    Automaton automaton;
    for (char c : s) {
      automaton.get(c);
    }
    return automaton.sign * automaton.ans;
  }

  int myAtoiOP(string s) {
    unsigned long len = s.length();

    // remove leading space
    int idx = 0;
    while (idx < len) {
      if (s[idx] != ' ') {
        break;
      }
      idx++;
    }

    if (idx == len) {
      return 0;
    }

    int sign = 1;
    // first non-empty char signed
    if (s[idx] == '+') {
      idx++;
    } else if (s[idx] == '-') {
      sign = -1;
      idx++;
    }

    int res = 0;
    while (idx < len) {
      char curChar = s[idx];
      if (curChar < '0' || curChar > '9') {
        break;
      }

      if (res > INT_MAX / 10 ||
          (res == INT_MAX / 10 && (curChar - '0') > INT_MAX % 10)) {
        return INT_MAX;
      }
      if (res < INT_MIN / 10 ||
          (res == INT_MIN / 10 && (curChar - '0') > -(INT_MIN % 10))) {
        return INT_MIN;
      }

      res = res * 10 + sign * (curChar - '0');
      idx++;
    }
    return res;
  }

  /**
   * @brief get max water in the container
   *
   */
  int maxArea(vector<int>& height) {
    int n = height.size();
    int le = 0, ri = n - 1;
    int res = 0;
    // while (le < ri) {
    // 	res = height[le] < height[ri] ?
    // 		max(res, (ri - le) * height[le++]) :
    // 		max(res, (ri - le) * height[ri--]);
    // }

    while (le < ri) {
      if (height[le] < height[ri]) {
        res = max(res, (ri - le) * height[le]);
        le++;
      } else {
        res = max(res, (ri - le) * height[ri]);
        ri--;
      }
    }

    return res;
  }

  /**
   * @brief Integer to Roman
   *
   */
  string intToRoman(int num) {
    string roman;
    for (const auto& [value, symbol] : valueSymbols) {
      while (num >= value) {
        num -= value;
        roman += symbol;
      }

      if (num == 0) {
        break;
      }
    }

    return roman;
  }

  vector<vector<int>> generateMatrix(int n) {
    int num = 1;
    vector<vector<int>> res(n, vector<int>(n));
    int le = 0, ri = n - 1, top = 0, bot = n - 1;
    while (le <= ri && top <= bot) {
      for (int col = le; col <= ri; col++) {
        res[top][col] = num;
        num++;
      }
      for (int row = top + 1; row <= bot; row++) {
        res[row][ri] = num;
        num++;
      }

      if (le < ri && top < bot) {
        for (int col = ri - 1; col > le; col--) {
          res[bot][col] = num;
          num++;
        }
        for (int row = bot; row > top; row--) {
          res[row][le] = num;
          num++;
        }
      }
      le++;
      ri--;
      top++;
      bot--;
    }

    return res;
  }
};

const pair<int, string> valueSymbols[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
    {5, "V"},    {4, "IV"},   {1, "I"},
};