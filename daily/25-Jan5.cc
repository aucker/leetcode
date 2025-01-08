#include <vector>
using namespace std;

class ATM {
  /**
   * @brief LC2241: Design ATM
   *
   */
  static constexpr int DENOMINATIONS[] = {20, 50, 100, 200, 500};
  static constexpr int KINDS = size(DENOMINATIONS);

  int banknotes[KINDS]{};

 public:
  ATM() {}

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < KINDS; i++) {
      banknotes[i] += banknotesCount[i];
    }
  }

  vector<int> withdraw(int amount) {
    vector<int> ans(KINDS);

    for (int i = KINDS - 1; i >= 0; i--) {
      ans[i] = min(amount / DENOMINATIONS[i], banknotes[i]);
      amount -= ans[i] * DENOMINATIONS[i];
    }

    if (amount > 0) return {-1};

    for (int i = 0; i < KINDS; i++) {
      banknotes[i] -= ans[i];
    }

    return ans;
  }
};
