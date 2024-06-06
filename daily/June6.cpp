#include <iostream>
using namespace std;

class Solution {
  /**
   * LC: 1938: Separate Black/White Balls
   * Time: O(N), Space: O(1)
   * All the '0's will be left, encounter 0, swap with
   * leftside cnt1, so res += cnt1, until this is no 0 left
   *
   * Note this is also the 'Greedy' solution
   */
  long long minimumSteps(string s) {
    long long ans = 0;
    int cnt1 = 0;
    for (char c : s) {
      if (c == '1') {
        cnt1++;
      } else {
        ans += cnt1;
      }
    }
    return ans;
  }

  /**
   * Sorted Merge LCCI [E]
   * 1. from back to begin
   * Time: O(n), Space: O(1)
   */
  void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int k = m + n - 1;
    int i = m - 1, j = n - 1;
    while (k >= 0 && (i >= 0 || j >= 0)) {
      if (i >= 0 && j >= 0 && A[i] >= B[j]) {
        A[k] = A[i];
        i--;
        k--;
      } else if (i >= 0 && j >= 0 && A[i] < B[j]) {
        A[k] = B[j];
        j--;
        k--;
      } else if (i >= 0 && j < 0) {
        A[k] = A[i];
        i--;
        k--;
      } else if (i < 0 && j >= 0) {
        A[k] = A[j];
        j--;
        k--;
      }
    }
  }

  /**
   * Use STD library of std::sort
   * Time: Average: O(nlogn)
   * Both works, but this is easy to implement, no much edge case
   */
  void mergeSTD(vector<int>& A, int m, vector<int>& B, int n) {
    for (int i = 0; i < n; i++) {
      A[m + i] = B[i];
    }
    sort(A.begin(), A.end());
  }
};
