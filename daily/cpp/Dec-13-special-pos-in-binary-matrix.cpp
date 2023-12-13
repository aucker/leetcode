#include <vector>
using namespace std;
class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
    int res = 0;
    int row = mat.size();
    int col = mat[0].size();
    int mark = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (mat[i][j] == 1) {
          mark = 1;
          int k = 0;
          while (k < col) {
            if (mat[i][k] == 1 && k != j) {
              ++mark;
              break;
            }
            ++k;
          }
          int l = 0;
          while (l < row) {
            if (mat[l][j] == 1 && l != i) {
              ++mark;
              break;
            }
            ++l;
          }
          ++res;
        }
        mark = 0;
      }
    }
    return res;
  }
};
