#include <string>

using namespace std;
class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    vector<int> counts(26, 0);

    for (char ch : chars) {
      counts[ch - 'a']++;
    }

    int res = 0;
    for (const string& word : words) {
      if (canForm(word, counts)) {
        res += word.size();
      }
    }
    return res;
  }

  bool canForm(const string& word, vector<int>& counts) {
    vector<int> c(26, 0);

    for (char ch : word) {
      int x = ch - 'a';
      c[x]++;
      if (c[x] > counts[x]) return false;
    }

    return true;
  }
};
