/// Link: https://codeforces.com/problemset/problem/1932/A
/// Author: Aucker (aucker)

#include <bits/stdc++.h>
using namespace std;

/// Can also use this function to solve the problem
// void solve() {
//   int n;
//   string s;
//   cin >> n >> s;
//   int res = 0;
//   for (int i = 0; i < n; ++i) {
//     if (s[i] == '.' and s[i + 1] == '*' and s[i + 2] == '*') {
//       break;
//     }
//     if (s[i] == '@') {
//       ++res;
//       if (s[i + 1] == '*' and s[i + 2] == '*') {
//         break;
//       }
//     }
//   }
//   cout << res << endl;
// }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '.' and s[i + 1] == '*' and s[i + 2] == '*') {
        break;
      }
      if (s[i] == '@') {
        res++;
        if (s[i + 1] == '*' and s[i + 2] == '*') {
          break;
        }
      }
    }
    cout << res << endl;
  }

  return 0;
}