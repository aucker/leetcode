#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getSumAbsoluteDiffs(vector<int>& nums) {
    // use double loop w/ O(N^2) will cause time exceeded

    /* int sum = 0; */
    /* for (int n : nums) { */
    /*   sum += n; */
    /* } */

    /* int left = 0, right = sum; */
    /* vector<int> res(nums.size(), 0);  // init the result vector */

    /* for (int i = 0; i < nums.size(); i++) { */
    /*   int n = nums[i]; */
    /*   right -= n; */

    /*   res[i] = n*i - left + right - n*(nums.size() - i - 1); */

    /*   left += n; */
    /* } */
    /* return res; */
    // time complexity: O(N)
    //

    int n = nums.size();
    vector<int> res(n);
    vector<int> prefixSum(n), suffixSum(n);

    // calculate and init the prefix sum & suffix sum array
    prefixSum[0] = nums[0];
    suffixSum[n-1] = nums[n-1];

    // calculate the prefix sums & suffix sums array in one loop
    for (int i = 1; i < n; i++) {
      prefixSum[i] = prefixSum[i-1] + nums[i];
      suffixSum[n-i-1] = suffixSum[n-1] + nums[n-i-1];
    }

    // calculate absolute diffs and update res array
    for (int i = 0; i < n; i++) {
      int currAbsDiff = ((nums[i]*i) - prefixSum[i]) + (suffixSum[i] - (nums[i] * (n-i-1)));
      res[i] = currAbsDiff;
    }

    return res;
  }
}
