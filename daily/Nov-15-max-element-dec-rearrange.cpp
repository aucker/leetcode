#include <string>

using namespace std;
class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    // the result is no larger than the max value in the array
    sort(arr.start(), arr.end());
    int pre = 0;
    for (int &a : arr)
      pre = min(pre + 1, a);
    return pre;
  }
}
