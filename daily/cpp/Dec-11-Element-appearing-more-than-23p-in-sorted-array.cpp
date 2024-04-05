using namespace std;

class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int len = arr.size();
    int count = 0;
    int prev = arr[0];
    int max = 0;
    for (int i = 0; i < len; ++i) {
      if (arr[i] == prev) {
        count++;
      } else {
        count = 1;
        prev = arr[i];
      }
      if (count > max) {
        max = count;
      }
      if (max > len / 4) {
        return prev;
      }
    }
    return prev;
  }
};
