#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  string findDiff(vector<string>& nums) {
    string result = "";
    string curr = "";
    bool found = false;
    int n = nums[0].size();
    unordered_set<string> S(nums.begin(), nums.end());
    solve(S, result, curr, n, found);
    return result;
  }

private:
  void solve(unordered_set<string>& S, string& result, string& curr, int& n, bool& found) {
    if (found) return;
    if (curr.size() == n) {
      if (S.find(curr) == S.end()) {
        result = curr;
      }
      return;
    }

    curr += '0';
    solve(S, result, curr, n, found);
    curr.pop_back();
    curr += '1';
    solve(S, result, curr, n, found);
    curr.pop_back();
  }
}
