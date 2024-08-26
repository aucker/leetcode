#include <string>

using namespace std;
class Solution {
 public:
  int numberOfWays(string corridor) {
    int chairs = 0;
    long long res = 1;

    for (int i = 0; i < corridor.size(); i++) {
      if (corridor[i] == 'S') {
        chairs++;

        while (++i < corridor.size() && corridor[i] != 'S')
          ;
        // the while increment i and check each character in the corridor
        // string. the loop continues until the end of the string or until the
        // next chair.
        if (i < corridor.size()) {
          chairs++;
        }

        int divisions = 1;
        while (++i < corridor.size() && corridor[i] != 'S') {
          divisions++;
        }

        if (divisions > 1 && i < corridor.size()) {
          res = (res * divisions) % static_cast<int>(1e9 + 7);
        }
        i--;
      }
    }

    return (chairs != 0 && chairs % 2 == 0) ? static_cast<int>(res) : 0;
  }
};
