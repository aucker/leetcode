#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int res = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      if (left <= right) {
        res = max(res, (right-left) * height[left]);
        left++;
      } else {
        res = max(res, (right-left) * height[right]);
        right--;
      }
    }
    return res;
  }
}
