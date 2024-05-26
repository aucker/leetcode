#include <bits/stdc++.h>
#include <bits/types.h>

#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    for (int i = 0; i < nums2.size(); i++) {
      nums2[i] *= k;
    }

    int res = 0;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] >= nums2[j] && nums1[i] % nums2[j] == 0) {
          res++;
        }
      }
    }
    return res;
  }

  string compressedString(string word) {
    if (word.empty()) {
      return word;
    }

    // Initialize the compressed string
    std::string compressed;
    // Initialize the count of the current character
    int count = 1;

    // Iterate through the string starting from the second character
    for (size_t i = 1; i < word.length(); ++i) {
      // Check if the current character is the same as the previous one
      if (word[i] == word[i - 1]) {
        // Increment the count of the current character
        count++;
      } else {
        // Append the previous character and its count(s) to the compressed
        // string
        while (count > 9) {
          compressed += '9';
          compressed += word[i - 1];
          count -= 9;
        }
        compressed += word[i - 1];
        compressed += std::to_string(count);
        // Reset the count for the new character
        count = 1;
      }
    }

    // Append the last character and its count(s)
    while (count > 9) {
      compressed += '9';
      compressed += word.back();
      count -= 9;
    }
    compressed += std::to_string(count);
    compressed += word.back();

    // Return the original string if the compressed string is not shorter
    // return compressed.length() < word.length() ? compressed : word;
    return compressed;
  }

  long long numberOfPairsII(vector<int>& nums1, vector<int>& nums2, int k) {
    unordered_map<int, int> map;
    long long pairs = 0;

    // Count occurrences of elements in nums2
    for (int num : nums2) {
      map[num]++;
    }

    // Iterate through nums1 and check for divisible pairs
    for (int num : nums1) {
      if (num % k == 0) {
        int divisor = num / k;

        // Check for divisors up to the square root of divisor
        for (int j = 1; j * j <= divisor; j++) {
          if (divisor % j == 0) {
            pairs += map[j];
            if (j != divisor / j) {
              pairs += map[divisor / j];
            }
          }
        }
      }
    }

    return pairs;
  }

  /**
   * @brief LC: 1738: Find Kth Largest XOR Coordinate Val
   * Time: O(mnlog(mn))  / O(mn)
   * Space: O(MN)
   *
   * @param matrix
   * @param k
   * @return int
   */
  int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> a;
    vector<vector<int>> s(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
      }
      a.insert(a.end(), s[i + 1].begin() + 1, s[i + 1].end());
    }
    // ranges::nth_element(a, a.end() - k);
    std::nth_element(a.begin(), a.begin() + k, a.end(), std::greater<int>());
    return a[a.size() - k];
  }
};