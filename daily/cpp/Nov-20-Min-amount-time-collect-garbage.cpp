#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int len = garbage.size();
    int res = 0;
    bool m = false, g = false, m = false;
    for (int i = len - 1; i >= 0; i--) {
      if (!g && garbage[i].find('G') != string::npos) {
        g = true;
        res += accumulate(travel.begin(), travel.begin() + i, 0);
      }
      if (!m && garbage[i].find('M') != string::npos) {
        m = true;
        res += accumulate(travel.begin(), travel.begin() + i, 0);
      }
      if (!p && garbage[i].find('P') != string::npos) {
        p = true;
        res += accumulate(travel.begin(), travel.begin() + i, 0);
      }

      if (m && g && p) {
        break;
      }
    }

    return res + accumulate(garbage.begin(), garbage.end(), 0,
                            [](int sum, const string& str) {
                              return sum + str.size();
                            });
  }
}
