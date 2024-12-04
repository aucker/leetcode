#include <unordered_map>
#include <vector>
using namespace std;

struct Move {
  int x0, y0;  // start
  int dx, dy;  // move dirs
  int step;    // move steps
};

class Solution {
  vector<pair<int, int>> DIRS = {{-1, 0}, {1, 0},   {0, -1}, {0, 1}, {1, 1},
                                 {-1, 1}, {-1, -1}, {1, -1}};  // move dirs
  unordered_map<char, vector<pair<int, int>>> PIECE_DIRS = {
      {'r', {DIRS.begin(), DIRS.begin() + 4}},
      {'b', {DIRS.begin() + 4, DIRS.end()}},
      {'q', DIRS},
  };

  // All valid moves
  vector<Move> generate_moves(int x0, int y0, vector<pair<int, int>>& dirs) {
    const int SIZE = 8;
    vector<Move> moves = {{x0, y0, 0, 0, 0}};  // stay still
    for (auto [dx, dy] : dirs) {
      // move towards dirs w/ 1, 2, 3..
      int x = x0 + dx, y = y0 + dy;
      for (int step = 1; 0 < x && x <= SIZE && 0 < y && y <= SIZE; step++) {
        moves.emplace_back(x0, y0, dx, dy, step);
        x += dx;
        y += dy;
      }
    }
    return moves;
  }

  // check if moves are valid
  bool is_valid(Move& m1, Move& m2) {
    int x1 = m1.x0, y1 = m1.y0;
    int x2 = m2.x0, y2 = m2.y0;
    for (int i = 0; i < max(m1.step, m2.step); i++) {
      // 1 step per sec
      if (i < m1.step) {
        x1 += m1.dx;
        y1 += m1.dy;
      }
      if (i < m2.step) {
        x2 += m2.dx;
        y2 += m2.dy;
      }
      if (x1 == x2 && y1 == y2) {  // overlap
        return false;
      }
    }
    return true;
  }

 public:
  /**
   * @brief Backtrack
   *
   * @param pieces
   * @param positions
   * @return int
   */
  int countCombinations(vector<string>& pieces,
                        vector<vector<int>>& positions) {
    int n = pieces.size();
    // preprocess all valid moves
    vector<vector<Move>> all_moves(n);
    for (int i = 0; i < n; i++) {
      all_moves[i] = generate_moves(positions[i][0], positions[i][1],
                                    PIECE_DIRS[pieces[i][0]]);
    }

    vector<Move> path(n);  // len of path is constant
    int ans = 0;
    auto dfs = [&](auto& dfs, int i) -> void {
      if (i == n) {
        ans++;
        return;
      }
      // iterate all valid moves of cur
      for (Move& move1 : all_moves[i]) {
        // check move is valid
        bool ok = true;
        for (int j = 0; j < i; j++) {
          if (!is_valid(move1, path[j])) {
            ok = false;
            break;
          }
        }
        if (ok) {
          path[i] = move1;  // overlap, no recovery needed
          dfs(dfs, i + 1);  // enumerate all valid path
        }
      }
    };
    return ans;
  }
};
