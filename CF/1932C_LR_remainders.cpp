/// Link: https://codeforces.com/contest/1932/problem/C
/// Author: Aucker (aucker)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast_io            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define newline cout << endl;
#define last(x) x[x.size() - 1];
#define pb(x) push_back(x);
#define mp(x, y) make_pair(x, y);

/// No idea why there is TLE in this solution
// vector<ll> solve() {
//   int n, mo;
//   cin >> n >> mo;
//   // use vector
//   vector<ll> a(n);
//   for (ll &x : a) {
//     cin >> x;
//   }

//   string s; std::cin >> s;
//   vector<ll> res(n);

//   ll val = 1;
//   int le = 0, ri = n - 1;

//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < n; ++j) {
//       if (a[j] % mo == 0) {
//         val = 0;
//         break;
//       } else {
//         val *= (a[j] % mo);
//         if (val >= mo) {
//         val %= mo;
//         }
//       }
//     }
//     res[i] = val;
//     if (s[i] == 'R') {
//       a[ri] = 1;
//       --ri;
//     } else if (s[i] == 'L') {
//       a[le] = 1;
//       ++le;
//     }
//     val = 1;
//   }
//   for (int i = 0; i < n; ++i) {
//     cout << res[i] << " ";
//   }
//   return res;
// }

vector<ll> solve() {
  ll n, mo;
  cin >> n >> mo;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }
  string s;
  cin >> s;

  ll le = -1, ri = n;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == 'L')
      le++;
    else
      --ri;
  }

  ll remainder = 1;
  vector<ll> res;
  for (ll i = n - 1; i >= 0; --i) {
    if (s[i] == 'L') {
      remainder = (remainder * a[le]) % mo;
      res.pb(remainder);
      --le;
    } else {
      remainder = (remainder * a[ri]) % mo;
      res.pb(remainder);
      ++ri;
    }
  }

  for (ll i = n - 1; i >= 0; --i) {
    cout << res[i] << " ";
  }
  newline;
  return res;
}

int main() {
  fast_io;

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}