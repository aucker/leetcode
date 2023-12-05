using namespace std;

class Solution {
  int numberOfmatches(int n) {
    int res = 0;
    int team = n;
    while (team > 1) {
      res += team / 2;
      team = team / 2 + team % 2;
    }
    return res;
  }
}
