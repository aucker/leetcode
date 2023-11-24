#include <vector>

using namespace std;
class Solution {
public:
  int maxCoins(vector<int>& piles) {
    int len = piles.size();
    int res = 0;
    sort(piles.begin(), piles.end());
    vector<int> piles_slice(piles.begin() + (len / 3), piles.end());
    for (int i = 0; i < len / 3 * 2; i+= 2) {
      res += piles_slice[i];
    }
    return res;
  }
}
