#include <string>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> buffers(26, 0);
    vector<int> buffert(26, 0);

    for (char c : s) {
      buffers[c - 'a']++;
    }
    for (char c : t) {
      buffers[c - 'a']++;
    }
    if (buffers == buffert) return true;
    return false;
  }
};
