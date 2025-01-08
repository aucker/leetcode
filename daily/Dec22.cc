#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int stepToOne(int n) {
    int res = 0;
    if (n == 1) return 0;
    while (n != 1) { if (n % 2 == 0) {
        n /= 2;
      } else {
        n = n * 3 + 1;
      }
      res++;
    }
    return res;
  }

  /**
   * LC1387: Sort Integers by the power value [E]
   * Basic pair, map
   */
  int getKth(int lo, int hi, int k) {
    unordered_map<int, int> nmap;
    for (int i = lo; i <= hi; i++) {
      nmap[i] = stepToOne(i);
    }
    vector<pair<int, int>> sortedVector(nmap.begin(), nmap.end());

    sort(sortedVector.begin(), sortedVector.end(),
         [](const pair<int, int>& le, const pair<int, int>& ri) {
           if (le.second == ri.second) {
             return le.first < ri.first;
           }
           return le.second < ri.second;
         });

    return sortedVector[k - 1].first;
  }
};
