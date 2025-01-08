#include <map>
#include <unordered_set>
using namespace std;

class MyCalendarI {
  unordered_set<int> tree, lazy;

 public:
  MyCalendarI() {}

  bool query(int start, int end, int l, int r, int idx) {
    if (r < start || end < l) return false;

    if (lazy.count(idx)) return true;

    if (start <= l && r <= end) return tree.count(idx);

    int mid = (l + r) >> 1;
    return query(start, end, l, mid, 2 * idx) ||
           query(start, end, mid + 1, r, 2 * idx + 1);
  }

  void update(int start, int end, int l, int r, int idx) {
    if (r < start || end < l) return;

    if (start <= l && r <= end) {
      tree.emplace(idx);
      lazy.emplace(idx);
    } else {
      int mid = (l + r) >> 1;
      update(start, end, l, mid, 2 * idx);
      update(start, end, mid + 1, r, 2 * idx + 1);
      tree.emplace(idx);
      if (lazy.count(2 * idx) && lazy.count(2 * idx + 1)) {
        lazy.emplace(idx);
      }
    }
  }

  bool book(int start, int end) {
    if (query(start, end - 1, 0, 1e9, 1)) return false;

    update(start, end - 1, 0, 1e9, 1);
    return true;
  }
};

class MyCalendarII {
 public:
  MyCalendarII() {}

  bool book(int start, int end) {
    int ans = 0;
    int maxBook = 0;
    cnt[start]++;
    cnt[end]--;
    for (auto& [_, freq] : cnt) {
      maxBook += freq;
      ans = max(maxBook, ans);
      if (maxBook > 2) {
        cnt[start]--;
        cnt[end]++;
        return false;
      }
    }
    return true;
  }

 private:
  map<int, int> cnt;
};

class MyCalendarIII {
 public:
  unordered_map<int, pair<int, int>> tree;

  MyCalendarIII() {}

  void update(int start, int end, int l, int r, int idx) {
    if (r < start || end < l) {
      return;
    }
    if (start <= l && r <= end) {
      tree[idx].first++;
      tree[idx].second++;
    } else {
      int mid = (l + r) >> 1;
      update(start, end, l, mid, 2 * idx);
      update(start, end, mid + 1, r, 2 * idx + 1);
      tree[idx].first =
          tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
    }
  }

  int book(int start, int end) {
    update(start, end - 1, 0, 1e9, 1);
    return tree[1].first;
  }
};
