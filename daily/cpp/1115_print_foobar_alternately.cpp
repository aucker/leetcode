#include <bits/stdc++.h>
using namespace std;

class FooBar {
 private:
  int n;

  mutex mtx;
  condition_variable cv;
  bool turn;

 public:
  FooBar(int n) {
    this->n = n;
    turn = false;
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; ++i) {
      unique_lock<mutex> lck(mtx);
      while (turn) {
        cv.wait(lck);
      }
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      turn = true;
      cv.notify_all();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; ++i) {
      unique_lock<mutex> lck(mtx);
      while (!turn) {
        cv.wait(lck);
      }
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      turn = false;
      cv.notify_all();
    }
  }
};