#include <vector>
using namespace std;
class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    // int res = 0;
    // int row = mat.size();
    // int col = mat[0].size();
    // int mark = 0;
    // for (int i = 0; i < row; ++i) {
    //   for (int j = 0; j < col; ++j) {
    //     if (mat[i][j] == 1) {
    //       mark = 1;
    //       int k = 0;
    //       while (k < col) {
    //         if (mat[i][k] == 1 && k != j) {
    //           ++mark;
    //           break;
    //         }
    //         ++k;
    //       }
    //       int l = 0;
    //       while (l < row) {
    //         if (mat[l][j] == 1 && l != i) {
    //           ++mark;
    //           break;
    //         }
    //         ++l;
    //       }
    //       ++res;
    //     }
    //     mark = 0;
    //   }
    // }
    // return res;

    /// Version 2
    int res = 0;
    for (int i = 0; i < mat.size(); i++) {
      int index = checkRow(mat, i);
      if (index >= 0 && checkCol(mat, i, index)) res++;
    }
    return res;
  }

 private:
  int checkRow(vector<vector<int>>& mat, int i) {
    int index = -1;
    for (int j = 0; j < mat[0].size(); ++j) {
      if (mat[i][j] == 1) {
        if (index >= 0) {
          return -1;
        } else {
          index = j;
        }
      }
    }
    return index;
  }

  bool checkCol(vector<vector<int>>& mat, int i, int index) {
    for (int j = 0; j < mat.size(); ++j) {
      if (mat[j][index] == 1 && j != i) {
        return false;
      }
    }
    return true;
  }
};
