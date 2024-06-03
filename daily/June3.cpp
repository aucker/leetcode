#include <vector>
using namespace std;

class Solution {
 public:
  /**
   * LC:1103: distribute candies II [E]
   * Time: O(N + sqrt(candies)), Space: O(1)
   */
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ans(num_people);
    for (int i = 1; candies > 0; i++) {
      ans[(i - 1) % num_people] += min(i, candies);
      candies -= i;
    }

    return ans;
  }
};
