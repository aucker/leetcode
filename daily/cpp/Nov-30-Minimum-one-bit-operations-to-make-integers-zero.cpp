using namespace std;

class Solution {
 public:
  int minimumOneBitOperations(int n) {
    int res = 0;
    for (res = 0; n > 0; n &= n - 1) res = -(res + (n ^ (n - 1)));
    return abs(res);
  }
};
