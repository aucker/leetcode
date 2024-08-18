#include <string>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC: 551: Student Attendance Record I [E]
   * Just use the CPP feature, Time: O(N), Space: O(1)
   *
   * @param s
   * @return true, false
   */
  bool checkRecord(string s) {
    return ranges::counts(s, 'A') && s.find("LLL") == string::npos;
  }
};