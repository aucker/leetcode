#include <cmath>
#include <iostream>
using namespace std;

class Solution {
 public:
  /**
   * @brief LC1134: Armstrong number
   * Time: O(N), Space: O(N)
   * Easy, just traverse the string
   *
   * @param n
   * @return true
   * @return false
   */
  bool isArmstrong(int n) {
    int count = 0;
    int pre = n;
    vector<int> temp;
    while (n > 9) {
      temp.push_back(n % 10);
      n /= 10;
      count++;
    }
    temp.push_back(n);
    count++;

    int sum = 0;
    for (int num : temp) {
      sum += pow(num, count);
    }
    cout << "sum is : " << sum << endl;
    cout << "count is : " << count << endl;

    return sum == pre ? true : false;
  }

  
};
