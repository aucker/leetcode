#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
 /**
  * @brief LC: image smoother
  * 2d-array manipulation
  *
  * @param img
  * @return vector<vector<int>>
  */
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int row = img.size(), col = img[0].size();
    vector<vector<int>> ans(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        int sum = 0, count = 0;

        for (int ni = i - 1; ni <= i + 1; ni++) {
          for (int nj = j - 1; nj <= j + 1; nj++) {
            if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
              sum += img[ni][nj];
              count++;
            }
          }
        }
        ans[i][j] = sum / count;
      }
    }

    return ans;

    // dumb and lack a corner case
    // for (int i = 1; i < row - 1; i++) {
    //   for (int j = 1; j < col - 1; j++) {
    //     ans[i][j] = (img[i-1][j-1] + img[i-1][j] + img[i-1][j+1] +
    //     img[i][j-1] + img[i][j] + img[i][j+1] + img[i+1][j-1] + img[i+1][j]+
    //     img[i+1][j+1]) / 9;
    //   }
    // }

    // for (int j = 1; j < col - 1; j++) {
    //   ans[0][j] = (img[0][j-1] + img[0][j] + img[0][j+1] + img[1][j-1] +
    //   img[1][j] + img[1][j+1]) / 6;
    // }
    // for (int j = 1; j < col - 1; j++) {
    //   ans[row-1][j] = (img[row-1][j-1] + img[row-1][j] + img[row-1][j+1] +
    //   img[row-2][j-1] + img[row - 2][j] + img[row-2][j+1]) / 6;
    // }

    // for (int i = 1; i < row - 1; i++) {
    //   ans[i][0] = (img[i-1][0] + img[i][0] + img[i+1][0] + img[i-1][1] +
    //   img[i][1] + img[i+1][1]) / 6;
    // }
    // for (int i = 1; i < row - 1; i++) {
    //   ans[i][col-1] = (img[i-1][col-1] + img[i][col-1] + img[i+1][col-1] +
    //   img[i-1][col-2] + img[i][col-2] + img[i+1][col-2]) / 6;
    // }

    // ans[0][0] = (img[0][0] + img[0][1] + img[1][0] + img[1][1]) / 4;
    // ans[0][col-1] = (img[0][col-1] + img[1][col-1] + img[0][col-2] +
    // img[1][col-2]) / 4; ans[row-1][0] = (img[row-1][0] + img[row-1][1] +
    // img[row-2][0] + img[row-2][1]) / 4; ans[row-1][col-1] =
    // (img[row-1][col-1] + img[row-2][col-1] + img[row-1][col-2] +
    // img[row-2][col-2]) / 4;
  }
};
