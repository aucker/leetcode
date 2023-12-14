#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> res(row, vector<int>(col));
		vector<int> rowOne(col);
		vector<int> colOne(row);
		// got to know number of each row and col of ones
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == 1) {
					rowOne[j]++;
					colOne[i]++;
				}
			}
		}

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				res[i][j] = rowOne[j] + colOne[i] - (row - rowOne[j]) - (col - colOne[i]);
			}
		}
		return res;
	}
};

