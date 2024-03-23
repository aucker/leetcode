#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief Find the duplicate number in List
   * Use set in STL is really slow
   * O(N) of time and space complexity
   * 
   * @param nums 
   * @return int 
   */
  int findDuplicate(vector<int>& nums) {
    set<int> st;
    for (int num : nums) {
      if (st.find(num) == st.end()) {
        st.insert(num);
      } else {
        return num;
      }
    }
    return -1;
  }

  int findDuplicateOptmize(vector<int>& nums) {
    int len = nums.size();
    if (len > 1) {
      int fast = nums[nums[0]];
      int slow = nums[0];

      while (fast != slow) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      fast = 0;
      while (fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
      }
      return slow;
    } else {
      return -1;
    }
  }

};