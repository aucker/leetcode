#include <queue>
#include <vector>
using namespace std;

class Solution {
  int catMouseGame(vector<vector<int>>& g_mouse, vector<vector<int>>& g_cat, int mouse_start, int cat_start, int hole) {
    int n = g_mouse.size();
    vector deg(n, vector<array<int, 2>>(n));
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        deg[i][j][0] = g_mouse[i].size();
        deg[i][j][1] = g_cat[j].size();
      }
    }

    vector winner(n, vector<array<int, 2>>(n));
    queue<tuple<int, int, int>> q;
    for (size_t i = 0; i < n; i++) {
      winner[hole][i][1] = 1;                 // mouse win
      winner[i][hole][0] = 2;                 // cat win
      winner[i][i][0] = winner[i][i][1] = 2;  // same spot, cat win
      q.emplace(hole, i, 1);
      q.emplace(i, hole, 0);
      q.emplace(i, i, 0);
      q.emplace(i, i, 1);
    }

    // (mouse, cat, turn) pre state
    auto get_pre_states = [&](int mouse, int cat, int turn) {
      vector<pair<int, int>> pre_states;
      if (turn == 0) {                       // mouse move
        for (size_t pre_cat : g_cat[cat]) {  // pre cat spot
          if (winner[mouse][pre_cat][1] == 0) {
            pre_states.emplace_back(mouse, pre_cat);
          }
        }
      } else {                                     // cat move
        for (size_t pre_mouse : g_mouse[mouse]) {  // pre mouse spot
          if (winner[pre_mouse][cat][0] == 0) {
            pre_states.emplace_back(pre_mouse, cat);
          }
        }
      }
      return pre_states;
    };

    while (!q.empty()) {
      auto [mouse, cat, turn] = q.front();
      q.pop();
      int win = winner[mouse][cat][turn];  // who wins
      int pre_turn = turn ^ 1;
      for (auto [pre_mouse, pre_cat] : get_pre_states(mouse, cat, turn)) {
        /**
         * case 1: pre state: mouse mv from pre to cur, mouse win, mark pre winner = mouse
         * case 2: pre state: cat mv from pre to cur, cat win, mark pre winner = cat
         * case 3: pre state: mouse mv from pre to cur, cat win, to be sure
         * case 4: pre state: cat mv from pre to cur, mouse win, to be sure
         */
        if (pre_turn == win - 1 || --deg[pre_mouse][pre_cat][pre_turn] == 0) {
          winner[pre_mouse][pre_cat][pre_turn] = win;
          q.emplace(pre_mouse, pre_cat, pre_turn);  // continue
        }
      }
    }
    // mouse in mouse_start, cat in cat_start, mouse's turn
    return winner[mouse_start][cat_start][0];  // return who wins finally (or draw)
  }

 public:
  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = grid.size(), n = grid[0].size();
    // construct graph for mouse & cat
    vector<vector<int>> g_mouse(m * n), g_cat(m * n);
    int mx, my, cx, cy, fx, fy;
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (grid[i][j] == '#') {  // wall here
          continue;
        }
        if (grid[i][j] == 'M') {  // mouse pos
          mx = i;
          my = j;
        } else if (grid[i][j] == 'C') {  // cat pos
          cx = i;
          cy = j;
        } else if (grid[i][j] == 'F') {  // food pos
          fx = i;
          fy = j;
        }
        int v = i * n + j;                           // from 2d (i, j) to 1d
        for (auto [dx, dy] : DIRS) {                 // enum l,r,u,d 4 dirs
          for (size_t k = 0; k <= mouseJump; k++) {  // enum jump len
            int x = i + k * dx, y = j + k * dy;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {  // out/wall
              break;
            }
            g_mouse[v].push_back(x * n + y);
          }
          for (size_t k = 0; k <= catJump; k++) {  // enum jump len
            int x = i + k * dx, y = j + k * dy;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
              break;
            }
            g_cat[v].push_back(x * n + y);
          }
        }
      }
    }
    return catMouseGame(g_mouse, g_cat, mx * n + my, cx * n + cy, fx * n + fy) == 1;
  }
};
