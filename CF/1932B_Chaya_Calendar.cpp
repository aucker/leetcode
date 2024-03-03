/// Link: https://codeforces.com/contest/1932/problem/B
/// Author: Aucker (aucker)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define fast_io            \
//   ios::sync_with_stdio(0); \
//   cin.tie(0);              \
//   cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }

  ll res = a[0];
  for (int i = 1; i < n; ++i) {
    ll tmp;
    if (a[i] > res) {
      res = a[i];
    } else {
      tmp = res / a[i] + 1;
      res = a[i] * tmp;
    }
  }
  cout << res << endl;
}

int main() {
  //   fast_io int t;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

// #include <bits/stdc++.h>

// #include <iostream>  // Add this line

// using namespace std;

// void solve() {
//   int n;
//   cin >> n;
//   vector<int> a(n);
//   for (int &x : a) {
//     cin >> x;
//   }

//   // init a vector that same with a
//   int res = 0;
//   if (n == 1) {
//     cout << a[0] << endl;
//     return;
//   }
//   for (int i = 1; i < n; ++i) {
//     int tmp = a[i];
//     while (a[i] <= a[i - 1]) {
//       a[i] += tmp;
//     }
//   }
//   res = a[n - 1];
//   cout << res << endl;
// }

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     solve();
//   }
//   return 0;
// }