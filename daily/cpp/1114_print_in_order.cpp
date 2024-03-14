#include <bits/stdc++.h>
using namespace std;

class Foo {
 public:
  Foo() { cnt = 1; }

  void first(function<void()> printFirst) {
    unique_lock<mutex> lck(mtx);
    // printFirst() outputs "first"
    printFirst();
    cnt = 2;
    cv.notify_all();
  }

  void second(function<void()> printSecond) {
    unique_lock<mutex> lck(mtx);
    while (cnt != 2) {
      cv.wait(lck);
    }
    // printSecond() outputs "second"
    printSecond();
    cnt = 3;
    cv.notify_all();
  }

  void third(function<void()> printThird) {
    unique_lock<mutex> lck(mtx);
    while (cnt != 3) {
      cv.wait(lck);
    }
    // printThird() outputs "third"
    printThird();
  }

 private:
  int cnt = 0;
  mutex mtx;
  condition_variable cv;
};