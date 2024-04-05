#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxProductDiffs(vector<int>& nums) {
    /// sort is O(nlogn), which is very slow
    // int len = nums.size();
    // sort(nums.begin(), nums.end());
    // int res = 0;
    // res = nums[len-1] * nums[len-2] - nums[0] * nums[1];
    // return res;

    /// use min and max to find the max and min value
    // int min1 = INT_MAX, min2 = INT_MAX;
    // int max1 = INT_MIN, max2 = INT_MIN;
    // for (int i = 0; i < nums.size(); i++) {
    //     if (nums[i] < min1) {
    //         min2 = min1;
    //         min1 = nums[i];
    //     } else if (nums[i] < min2) {
    //         min2 = nums[i];
    //     }
    //     if (nums[i] > max1) {
    //         max2 = max1;
    //         max1 = nums[i];
    //     } else if (nums[i] > max2) {
    //         max2 = nums[i];
    //     }
    // }
    // int res = 0;
    // res = max1 * max2 - min1 * min2;
    // return res;

    /// more faster way
    int min1{numeric_limits<int>::max()};
    int min2{numeric_limits<int>::max()};
    int max1{numeric_limits<int>::min()};
    int max2{numeric_limits<int>::min()};
    for (const auto num : nums) {
      if (num > max2) {
        max1 = exchange(max2, num);
      } else {
        max1 = max(max1, num);
      }

      if (num < min1) {
        min2 = exchange(min1, num);
      } else {
        min2 = min(min2, num);
      }
    }
    return max1 * max2 - min1 * min2;
  }
};

static const auto _ = []() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  return nullptr;
}();
// The active selection is a common technique used in competitive programming to
// speed up I/O operations in C++. It's a lambda function that is immediately
// invoked at the start of the program. Let's break it down:

// 1. `static const auto _ = []() {...}();`: This is a lambda function (an
// anonymous function) that is immediately invoked. The `static const auto _`
// part means that the result of this function is stored in a static constant
// variable named `_`. The function is invoked immediately because of the `()`
// at the end.

// 2. `ios::sync_with_stdio(false);`: This line disables the synchronization
// between the C and C++ standard streams. By default, all standard streams are
// synchronized, which ensures a proper sequence of reads and writes from/to
// these streams. However, this synchronization can cause a significant
// performance hit. Disabling it can speed up I/O operations, but you should be
// aware that you can't safely mix C and C++ style I/O after you've done this.

// 3. `cout.tie(nullptr);` and `cin.tie(nullptr);`: These lines untie `cin` and
// `cout`. By default, `cin` is tied to `cout` to ensure a proper sequence
// between reads and writes. However, this can cause performance issues because
// every input operation (`cin`) could potentially be followed by a flush
// operation on the output (`cout`). Untying them can result in faster I/O
// operations, but you should be careful because the order of output and input
// can become unpredictable.

// In summary, this block of code is used to optimize the speed of input and
// output operations in C++, which can be particularly useful in competitive
// programming where performance is critical. However, it should be used with
// caution because it can lead to unpredictable results if you're not careful.