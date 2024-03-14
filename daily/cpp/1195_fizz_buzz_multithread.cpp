#include <bits/stdc++.h>
using namespace std;

class FizzBuzz {
 private:
  int n;
  int i;
  mutex mtx;
  condition_variable cv;

 public:
  FizzBuzz(int n) {
    this->n = n;
    this->i = 1;
  }

  // printFizz() outputs "fizz"
  void fizz(function<void()> printFizz) {
    unique_lock<mutex> lock(mtx);
    while (i <= n) {
      /* while (i <= n && ((i % 3 == 0) && (i % 5 != 0)) == 0) {
        cv.wait(lock);
      } */
      cv.wait(lock, [&] { return i > n || (i % 3 == 0 && i % 5 != 0); });
      if (i <= n) {
        printFizz();
        ++i;
      }
      cv.notify_all();
    }
  }

  // printBuzz() outputs "buzz"
  void buzz(function<void()> printBuzz) {
    unique_lock<mutex> lock(mtx);
    while (i <= n) {
      while (i <= n && ((i % 5 == 0) && (i % 3 != 0)) == 0) {
        cv.wait(lock);
      }
      if (i <= n) {
        printBuzz();
        ++i;
      }
      cv.notify_all();
    }
  }

  void fizzbuzz(function<void()> printFizzBuzz) {
    unique_lock<mutex> lock(mtx);
    while (i <= n) {
      /* while (i <= n && ((i % 5 == 0) && (i % 3 == 0)) == 0) {
        cv.wait(lock);
      } */

      cv.wait(lock, [this] { return i > n || (i % 3 == 0 && i % 5 == 0); });
      if (i <= n) {
        printFizzBuzz();
        ++i;
      }
      cv.notify_all();
    }
  }

  void number(function<void(int)> printNumber) {
    unique_lock<mutex> lock(mtx);
    while (i <= n) {
      cv.wait(lock, [this] { return i > n || (i % 3 != 0 && i % 5 != 0); });
      if (i <= n) {
        printNumber(i);
        ++i;
      }
      cv.notify_all();
    }
  }
};