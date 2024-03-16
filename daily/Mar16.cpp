#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * @brief reverse the words in a string, trim the left and right space
   *
   * @param s
   * @return string
   */
  string reverseWords(string s) {
    // reverse use the FILO
    stack<string> stk;

    istringstream iss(s);

    do {
      string subs;
      iss >> subs;

      stk.push(subs);
    } while (iss);

    string ans;
    while (!stk.empty()) {
      ans += stk.top();
      stk.pop();
      ans += " ";
    }
    ans.erase(0, 1);
    ans.erase(ans.size() - 1, 1);
    return ans;
  }

  string reverseWords1(string s) {
    // trim all the space and add space between words
    int slow = 0;
    for (int fast = 0; fast < s.length(); ++fast) {
      if (s[fast] != ' ') {
        if (slow != 0) {
          s[slow++] = ' ';
        }
        while (fast < s.size() && s[fast] != ' ') {
          s[slow++] = s[fast++];
        }
      }
    }
    s.resize(slow);  // size of slow is string remove the extra spaces

    reverse1(s, 0, s.size() - 1);  // reverse string

    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
      if (i == s.size() || s[i] == ' ') {  // space or end of word
        reverse1(s, start, i - 1);         // reverse single word
        start = i + 1;                     // update next word
      }
    }
    return s;
  }

  string reverseWords2(string s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start) {
      if (s[start] != ' ') {
        // fill space and move idx to the start of next word
        if (idx != 0) s[idx++] = ' ';

        // loop till end of word
        int end = start;
        while (end < n && s[end] != ' ') s[idx++] = s[end++];

        // reverse whole word
        reverse(s.begin() + idx - (end - start), s.begin() + idx);

        // update start, find next word
        start = end;
      }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
  }

  /**
   * @brief use deque to handle the problem
   *
   * @param s
   * @return string
   */
  string reverseWords3(string s) {
    int n = s.size();
    int left = 0, right = n - 1;
    // trim the space of words begin
    while (left <= right && s[left] == ' ') ++left;

    // trim the space of words end
    while (left <= right && s[right] == ' ') --right;

    deque<string> d;
    string word;

    while (left <= right) {
      char c = s[left];
      if (word.size() && c == ' ') {
        // push word to the head of deque
        d.push_front(move(word));
        word = "";
      } else if (c != ' ') {
        word += c;
      }
      ++left;
    }
    d.push_front(move(word));

    string ans;
    while (!d.empty()) {
      ans += d.front();
      d.pop_front();
      if (!d.empty()) ans += ' ';
    }
    return ans;
  }

  string reverseWord4(string s) {
    // use two pointers
    int m = s.size() - 1;
    string ans;
    // trim the end space
    while (s[m] == ' ' && m > 0) m--;

    int n = m;  // another pointer
    while (m >= 0) {
      while (m >= 0 && s[m] != ' ') m--;
      ans += s.substr(m + 1, n - m) + " ";  // get word add space
      while (m >= 0 && s[m] == ' ') m--;
      n = m;
    }
    return ans.substr(0, ans.size() - 1);  // trim the last space
  }

  /**
   * @brief
   *
   * @param txt Text string to search in
   * @param pat Pattern string to search for
   * @return vector<int> Indices where pattern is found
   */
  vector<int> KMPSearch(string txt, string pat) {
    int M = pat.length();
    int N = txt.length();

    // create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps(M, 0);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;        // index for txt[]
    int j = 0;        // index for pat[]
    vector<int> res;  // to store the indices where pattern is found

    while (i < N) {
      if (pat[j] == txt[i]) {
        j++;
        i++;
      }

      if (j == M) {
        res.push_back(i - j);
        j = lps[j - 1];
      }

      // mismatch after j matches
      else if (i < N && pat[j] != txt[i]) {
        // Do not match lps[0..lps[j-1]] characters, they will match anyway
        if (j != 0)
          j = lps[j - 1];
        else
          i = i + 1;
      }
    }
    return res;
  }

  /**
   * @brief Utility function to calculate lps
   *
   * @param pat Pattern string
   * @param M Length of pattern string
   * @param lps lps array
   */
  void computeLPSArray(string pat, int M, vector<int>& lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;  // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
      if (pat[i] == pat[len]) {
        len++;
        lps[i] = len;
        i++;
      } else {
        // (pat[i] != pat[len])
        if (len != 0) {
          // This is tricky. Consider the example.
          // AAACAAAA and i = 7. The idea is similar to search step.
          len = lps[len - 1];

          // Also, note that we do not increment i here
        } else {
          // if (len == 0)
          lps[i] = 0;
          i++;
        }
      }
    }
  }

  int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    if (m == 0) return 0;
    // pivot
    haystack.insert(haystack.begin(), ' ');
    needle.insert(needle.begin(), ' ');
    vector<int> next(m + 1);
    // preprocess next
    for (int i = 2, j = 0; i <= m; ++i) {
      while (j && needle[i] != needle[j + 1]) j = next[j];
      if (needle[i] == needle[j + 1]) ++j;
      next[i] = j;
    }
    // match process
    for (int i = 1, j = 0; i <= n; ++i) {
      while (j && haystack[i] != needle[j + 1]) j = next[j];
      if (haystack[i] == needle[j + 1]) ++j;
      if (j == m) return i - m;
    }
    return -1;
  }

 private:
  void reverse1(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }
};

int main() {
  Solution s;
  string si = "hi from here";
  string ans = s.reverseWords(si);
  cout << ans << endl;
}