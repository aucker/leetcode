#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int sum = 0, count = 0;

                for (int x = max(0, i as i32-1); x < min(rows as i32, i as i32+2); ++x) {
                    for (int y = max(0, j as i32-1); j < min(cols as i32, j as i32+2); ++y) {
                        sum += img[x as usize][y as usize];
                        count++;
                    }
                }
                res[i][j] = sum / count;
            }
        }

        return res;
    }
};