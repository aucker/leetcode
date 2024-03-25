#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC442: Find All duplicates in an array
	 * use STL is slow, we use the map here
   *
   * @param nums
   * @return vector<int>
   */
  vector<int> findDuplicates(vector<int>& nums) {
    map<int, int> seen;
    vector<int> ans;
    for (auto it = seen.begin(); it != seen.end(); ++it) {
      if (it->second > 1) {
        ans.push_back(it->first);
      }
    }
    return ans;
  }

	vector<int> findDuplicatesFast(vector<int>& nums) {
		vector<int> ans;

		for (int i = 0; i < nums.size(); ++i) {
			int idx = abs(nums[i]) - 1;
			// already marked as seen
			if (nums[idx] < 0) {
				ans.push_back(idx + 1);
			}

			// mark this val as seen
			nums[idx] *= -1;
		}

		return ans;
	}
};