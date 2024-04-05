#include <bitset>
#include <cstdint>
#include <string>
using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    // int res = 0;
    // while(n) {
    //     res += n & 1;
    //     n >>= 1;
    // };
    // return res;

    // convert the binary n to string directly
    int res = 0;
    string s = bitset<32>(n).to_string();
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') res++;
    }
    return res;
  }
};
