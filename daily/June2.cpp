#include <bits/stdc++.h>

#include <algorithm>
#include <cstddef>
using namespace std;

struct SegmentNode {
  int start, end, max_end;
  SegmentNode *left, *right;
  SegmentNode(int start_, int end_)
      : start(start_),
        end(end_),
        max_end(end_),
        left(nullptr),
        right(nullptr) {}
};

SegmentNode* build_segment_tree(vector<pair<int, int>>& intervals, int l,
                                int r) {
  if (l > r) {
    return nullptr;
  }

  int mid = l + (r - 1) / 2;
  SegmentNode* node =
      new SegmentNode(intervals[mid].first, intervals[mid].second);

  node->left = build_segment_tree(intervals, l, mid - 1);
  node->right = build_segment_tree(intervals, mid + 1, r);

  if (node->left) {
    node->max_end = max(node->max_end, node->left->max_end);
  }
  if (node->right) {
    node->max_end = max(node->max_end, node->right->max_end);
  }

  return node;
}

void merge_intervals(vector<pair<int, int>>& intervals,
                     set<pair<int, int>>& merged_intervals, SegmentNode* node,
                     int l, int r, int query_l, int query_r) {
  if (l > r || query_l > query_r || node->max_end < query_l) {
    return;
  }
  if (query_l <= node->start && node->end <= query_r) {
    merged_intervals.insert({node->start, node->end});
    return;
  }
  if (query_l < node->start) {
    merge_intervals(intervals, merged_intervals, node->left, l, node->start - 1,
                    query_l, query_r);
  }

  if (query_r > node->end) {
    merge_intervals(intervals, merged_intervals, node->right, node->start + 1,
                    r, query_l, query_r);
  }
}

vector<pair<int, int>> merge_all_intervals(vector<pair<int, int>>& intervals) {
  // build segment tree
  SegmentNode* root = build_segment_tree(intervals, 0, intervals.size() - 1);

  // merge
  set<pair<int, int>> merged_intervals;
  merge_intervals(intervals, merged_intervals, root, 0, intervals.size() - 1, 0,
                  intervals.size() - 1);

  // collect res after merge
  vector<pair<int, int>> result(merged_intervals.begin(),
                                merged_intervals.end());
  return result;
}

class Solution {
 public:
  /**
   * @brief Contest 400: P1 chairs
   * Time: O(n)
   *
   * @param s
   * @return int
   */
  int minimumChairs(string s) {
    int ans = 0;
    stack<int> stk;
    for (char c : s) {
      // too much cache miss here with cond
      if (c == 'E') {
        stk.push(1);
      }
      ans = ans > stk.size() ? ans : stk.size();
      if (c == 'L') {
        stk.pop();
      }
    }
    return ans;
  }

  int countDays(int days, vector<vector<int>>& meetings) {
    // sort meetings by first value
    // sort(meetings.begin(), meetings.end(),
    //  [&](int lhs, int rhs) { return meetings[lhs] < meetings[rhs]; });

    int tmp = 0;
    if (meetings.size() == 0) return days;

    sort(meetings.begin(), meetings.end());
    vector<vector<int>> merged;
    for (int i = 0; i < meetings.size(); i++) {
      int L = meetings[i][0], R = meetings[i][1];
      if (!merged.size() || merged.back()[1] < L) {
        merged.push_back({L, R});
      } else {
        merged.back()[1] = max(merged.back()[1], R);
      }
    }
    for (int i = 0; i < merged.size(); i++) {
      tmp += (merged[i][1] - merged[i][0] + 1);
    }
    return days - tmp;
  }

  string clearStars(string s) {
    string ans = s;
    for (char c : s) {
    }
  }

  /**
   * @brief LC: 575: candy distribution
   * Time/Space: O(n)
   *
   * @param candyType
   * @return int
   */
  int distributeCandies(vector<int>& candyType) {
    unordered_map<int, int> repeat;
    for (int candy : candyType) {
      repeat[candy]++;
    }
    int len = candyType.size();
    int type = repeat.size();
    return type >= len / 2 ? len / 2 : type;
  }
};