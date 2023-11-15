#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    // the result is no larger than the max value in the array
    sort(arr.begin(), arr.end());
    int pre = 0;
    for (int &a : arr)
      pre = min(pre + 1, a);
    return pre;
  }
  // sort() time complexity is O(nlogn)

  int maxEleAfterDecARe(vector<int> &arr) {
    // optimized version with O(n)
    int l = arr.size();
    std::vector<int> counter(l, 0);

    for (int i = 0; i < l; i++) {
      int index = min(arr[i] - 1, l - 1);
      counter[index]++;
    }

    int vacancy = 0;
    for (int i = 0; i < counter.size(); i++) {
      vacancy++;
      if (counter[i] != 0) {
        vacancy = max(0, vacancy - counter[i]);
      }
    }
    return counter.size() - vacancy;
  }
  // optimized version with O(n)
};