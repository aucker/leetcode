#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

class H2O {
 private:
  int hydrogencnt, oxygencnt;
  mutex mtx;
  condition_variable cv;
  bool start = false;

 public:
  H2O() {
    hydrogencnt = 0;
    oxygencnt = 0;
  }

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&] { return oxygencnt == 1; });
    hydrogencnt++;
    // releaseHydrogen() outputs "H".
    releaseHydrogen();
    if (hydrogencnt == 2 and oxygencnt == 1) {
      hydrogencnt = 0;
      oxygencnt = 0;
      start = false;
    }
    cv.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&] { return start == false || hydrogencnt == 2; });
    start = true;
    oxygencnt++;

    // releaseOxygen() outputs "O".
    releaseOxygen();
    if (hydrogencnt == 2 and oxygencnt == 1) {
      hydrogencnt = 0;
      oxygencnt = 0;
    }
    cv.notify_all();
  }
};