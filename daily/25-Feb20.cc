#include <vector>
using namespace std;

class Solution {
  enum Bits {
    bit0 = 0b0000000001,
    bit1 = 0b0000000010,
    bit2 = 0b0000000100,
    bit3 = 0b0000001000,
    bit4 = 0b0000010000,
    bit5 = 0b0000100000,
    bit6 = 0b0001000000,
    bit7 = 0b0010000000,
    bit8 = 0b0100000000,
    bit9 = 0b1000000000,
  };

 public:
  /**
   * @brief LC2595: Number of Even and Odd Bits
   * Time: O(1), Space: O(1)
   * Bit operation is really fast, haha <3
   *
   * @param n
   * @return vector<int>
   */
  vector<int> evenOddBit(int n) {
    vector<int> ans(2, 0);
    Bits mybits[] = {bit0, bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8, bit9};
    int sentinel = 0;
    for (auto bit : mybits) {
      if ((bit & n) != 0 && sentinel % 2 == 0) {
        ans[0]++;
      } else if ((bit & n) != 0 && sentinel % 2 == 1) {
        ans[1]++;
      }
      sentinel++;
    }
    return ans;
  }
};
