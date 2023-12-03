#include <vector>

using namespace std;
class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int res = 0;

    for (int i = 1; i < points.size(); i++) {
      res += toTime(points[i-1], points[i]);
    }

    return res;
  }

  int toTime(vector<int>& from, vector<int>& to) {
    int xDiff = abs(from[0] - to[0]);
    int yDiff = abs(from[1] - to[1]);

    return max(xDiff, yDiff);
  }
};
