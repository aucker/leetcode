#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Leetcode Weekly 391
 * Today problems are not so hard, no some special DSs
 * but numbers
 *
 * *** Address sanitizer problem, heap overflow problem:
 * this is usually happens when access an array, linkedlist with out bounds. So
 * when access those elements, make sure to check if index is valid.
 *
 * 1. get the sum of every digit of the number
 *
 * 2. greedy? loop, add the remain of bottle
 *
 * 3. traverse the whole array, don't try the sliding window, will cause TLE.
 * Try to get the sub problem of every length of valid slice, then the sum of
 * this all subproblems. Sum of 4 is : 4 + 3 + 2 + 1 sum of 1 is 1 so: sum of (1
 * to n) and add the whole
 *
 * AK 3 problem, no clue about the last problem
 * Manhattan distance, get every value of the manhattan?
 *
 */
class Solution {
 public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    int n = 0;
    int tmp = x;
    while (tmp != 0) {
      n += (tmp % 10);
      cout << "n is " << n << endl;
      tmp /= 10;
    }
    return x % n == 0 ? n : -1;
  }

  int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = 0;
    int left = 0;
    int drink = 0;
    ans += numBottles;
    while (numBottles >= numExchange) {
      // left += (numBottles - numExchange);
      numBottles -= numExchange;
      drink++;
      numExchange++;
      numBottles++;
    }
    ans += drink;
    return ans;
  }

  long long countAlternatingSubarrays(vector<int>& nums) {
    /// Use the sliding window will TLE
    // int len = nums.size();
    // int le = 0, ri = 0;
    // long long ans = 0;
    // while (le < len ) {
    //   // if valid, ri ++
    //   // if invalid, le ++
    //   if (le == ri) {
    //     ans ++;
    //     ri++;
    //   }
    //   else if (nums[ri] != nums[ri-1]) {
    //     ans++;
    //     ri ++;
    //   }
    //   else if (nums[ri] == nums[ri-1]) {
    //     le ++;
    //     ri = le;
    //   }
    //   if (ri >= len) {
    //     le ++;
    //     ri = le;
    //   }
    // }
    // return ans;

    /// We use D&C, math way to solve this
    long long len = nums.size();
    long long len1 = len;
    long long ri = 1;
    long long ans = 0;
    long long tmplen = 1;
    if (len == 1) return 1;
    while (ri < len) {
      while (ri < len && nums[ri] != nums[ri - 1]) {
        tmplen++;
        ri++;
      }
      if (ri < len && nums[ri] == nums[ri - 1]) {
        ri++;
      }
      if (tmplen > 1) {
        len1 -= tmplen;
        ans += ((1 + tmplen) * tmplen / 2);
      }

      tmplen = 1;
    }
    ans += len1;
    return ans;
  }
};

int main() {
  Solution s;
  // int n = 18;
  vector<int> test = {1, 0, 1, 0};
  cout << " this is " << s.countAlternatingSubarrays(test) << endl;
  int bottles = 10, exchange = 3;
  cout << "the num to drink is " << s.maxBottlesDrunk(bottles, exchange)
       << endl;
  return 0;
}