using namespace std;

class Solution {
public:
  int totalMoney(int n) {
    int res = 0;
    int weekn = n / 7;
    int day = n % 7;
    int j = 0;
    int money = weekn + 1;
    while (j < day) {
      res += money;
      money++;
      j++;
    }

    if (weekn >= 1) {
      int i = 1;
      while (i <= weekn) {
        res += sumSeven(i);
        i++;
      }
    }

    return res;
  }

  int sumSeven(int s) {
    int sum = 0;
    int n = 1;
    while (n < =7) {
      sum += s;
      s++;
      n++;
    }
    return sum;
  }
};
