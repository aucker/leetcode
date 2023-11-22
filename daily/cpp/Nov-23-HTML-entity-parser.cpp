#include <string>

using namespace std;

class Solution {
private:
  map<string, string> m_pool = {
    {"&quot;", "\""}, {"&apos;", "'"}, {"&amp;", "&"}, {"&gt;", ">"},
    {"&lt;", "<"}, {"&frasl;", "/"};
  };

public:
  string entityParser(string text) {
    string key;
    string res;
    for (auto achar : text) {
      if (achar == '&') {
        if (!key.empty()) {
          res += key;
          key.erase();
        }
        key.push_back(achar);
      } else if (achar != ';') {  // not valid, not replace 
        key.push_back(achar);      
      } else {
        key.push_back(achar);
        if (m_pool.find(key) != m_pool.end()) {
          res += m_pool[key];
          key.erase();
        } else {
          res += key;
          key.erase();
        }
      }
    }
    if (!key.empty()) {
      res += key;
    }
    return res;
  }
}
