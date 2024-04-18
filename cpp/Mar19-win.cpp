#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        backtrack(board, i, j);
      }
    }
    return;
  }

  void backtrack(vector<vector<char>>& board, int i, int j) {
    int m = 9, n = 9;
    if (j == n) {
      // go the last col, we need to new row
      backtrack(board, i + 1, 0);
      return;
    }

    // if this place has number, just skip
    if (board[i][j] != '.') {
      backtrack(board, i, j + 1);
      return;
    }

    for (char ch = '1'; ch <= '9'; ++ch) {
      // if not valid, skip
      if (!isValid(board, i, j, ch)) {
        continue;
      }
      // make selection
      board[i][j] = ch;
      // go to next pos
      backtrack(board, i, j + 1);
      // recover
      board[i][j] = '.';
    }
  }

  bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for (int i = 0; i < 9; ++i) {
      // check repeat in row
      if (board[r][i] == ch) return false;
      // check repeat in col
      if (board[i][c] == ch) return false;
      // check subbox
      if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return false;
    }
    return true;
  }
};

class NQueen {
  vector<vector<string>> ans;

 public:
  vector<vector<string>> solveNQueens(int n) {
    // '.' is empty, 'Q' is queen
    // init a board with string vector
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return ans;
  }

  // path: all rows that are smaller than row has queen
  // select from: the 'row' row every col is option to place queen
  // end: row is equal or greater than last row of board, full in the board
  void backtrack(vector<string>& board, int row) {
    // when to end
    if (row == board.size()) {
      ans.push_back(board);
      return;
    }

    int n = board[0].size();
    for (int col = 0; col < n; ++col) {
      // remove the invalid option
      if (!isValid(board, row, col)) {
        continue;
      }
      // make selection
      board[row][col] = 'Q';
      // go to next decision
      backtrack(board, row + 1);
      // recover
      board[row][col] = '.';
    }
  }

  bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // check if queen are in conflict
    for (int i = 0; i < row; ++i) {
      // curr is 'Q', cant put Queen, invalid
      if (board[i][col] == 'Q') return false;
    }

    // check if top right valid
    for (int i = row - 1, j = col + 1; i >= 0 && j < 9; --i, ++j) {
      if (board[i][j] == 'Q') return false;
    }
    // check if top left valid
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j] == 'Q') return false;
    }

    return true;
  }
};

struct DLinkedList {
  int key, val;
  DLinkedList* prev;
  DLinkedList* next;
  DLinkedList() : key(0), val(0), prev(nullptr), next(nullptr) {}
  DLinkedList(int _key, int _val)
      : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  unordered_map<int, DLinkedList*> cache;
  DLinkedList* head;
  DLinkedList* tail;
  int size;
  int capacity;

 public:
  LRUCache(int _capacity) : size(0), capacity(_capacity) {
    head = new DLinkedList();
    tail = new DLinkedList();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    // check if cache has the key
    if (!cache.count(key)) return -1;
    DLinkedList* node = cache[key];
    moveToHead(node);
    return node->val;
  }

  void push(int key, int value) {
    // check if cache has the key
    if (!cache.count(key)) {
      // add new
      DLinkedList* node = new DLinkedList(key, value);
      cache[key] = node;
      addToHead(node);
      ++size;
      if (size > capacity) {
        DLinkedList* toRemove = removeTail();
        // remember for the hashtable, always erase the key
        cache.erase(toRemove->key);
        delete toRemove;
        --size;
      }
    } else {
      // the key has the value, just update the value of key
      DLinkedList* node = cache[key];
      node->val = value;
      moveToHead(node);
    }
  }

  void addToHead(DLinkedList* node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;

    //
    head->next = node;
  }

  void removeNode(DLinkedList* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedList* node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedList* removeTail() {
    DLinkedList* toRemove = tail->prev;
    removeNode(toRemove);
    return toRemove;
  }
};

class BinaryFind {
 public:
  // write a basic binary search
  int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    // not found
    return -1;
  }

  // find the first position of target
  int binarySearchFirst(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (left >= nums.size() || nums[left] != target) {
      return -1;
    }
    return left;
  }
};

/**
 * @brief This is a class for Sort
 * several sort algorithms:
 * 1. bubble sort
 * 2. selection sort
 * 3. insertion sort
 * 4. merge sort
 * 5. quick sort
 * 6. heap sort
 * 7. counting sort
 * 8. bucket sort
 * 9. radix sort
 *
 */
class Sort {
 public:
  /**
   * @brief bubble sort
   *
   * @param nums
   */
  void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n - i - 1; ++j) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
        }
      }
    }
  }

  /**
   * @brief selection sort
   *
   * @param nums
   */
  void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      swap(nums[i], nums[minIndex]);
    }
  }

  /**
   * @brief insertion sort
   *
   * @param nums
   */
  void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      int key = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = key;
    }
  }

  /**
   * @brief merge sort
   *
   * @param nums
   */
  void mergeSort(vector<int>& nums) { merge(nums, 0, nums.size() - 1); }

  void merge(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }
    int mid = left + (right - left) / 2;
    merge(nums, left, mid);
    merge(nums, mid + 1, right);

    // merge(nums, left, mid, right);
  }

  void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        temp[k++] = nums[i++];
      } else {
        temp[k++] = nums[j++];
      }
    }
    while (i <= mid) {
      temp[k++] = nums[i++];
    }
    while (j <= right) {
      temp[k++] = nums[j++];
    }
    for (int p = 0; p < temp.size(); ++p) {
      nums[left + p] = temp[p];
    }
  }

  /**
   * @brief quick sort
   *
   * @param nums
   */
  void quickSort(vector<int>& nums) { quick(nums, 0, nums.size() - 1); }

  void quick(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }
    int pivot = partition(nums, left, right);
    quick(nums, left, pivot - 1);
    quick(nums, pivot + 1, right);
  }

  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; ++j) {
      if (nums[j] < pivot) {
        swap(nums[i], nums[j]);
        ++i;
      }
    }
    swap(nums[i], nums[right]);
    return i;
  }

  /**
   * @brief heap sort
   *
   * @param nums
   */
  void heapSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
      heapify(nums, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
      swap(nums[0], nums[i]);
      heapify(nums, i, 0);
    }
  }

  void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && nums[left] > nums[largest]) {
      largest = left;
    }
    if (right < n && nums[right] > nums[largest]) {
      largest = right;
    }
    if (largest != i) {
      swap(nums[i], nums[largest]);
      heapify(nums, n, largest);
    }
  }

  /**
   * @brief counting sort
   *
   * @param nums
   */
  void countingSort(vector<int>& nums) {
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> count(maxVal + 1);
    for (int i = 0; i < n; ++i) {
      ++count[nums[i]];
    }
    for (int i = 1; i <= maxVal; ++i) {
      count[i] += count[i - 1];
    }
    vector<int> temp(n);
    for (int i = n - 1; i >= 0; --i) {
      temp[--count[nums[i]]] = nums[i];
    }
    for (int i = 0; i < n; ++i) {
      nums[i] = temp[i];
    }
  }

  /**
   * @brief bucket sort
   *
   * @param nums
   */
  void bucketSort(vector<int>& nums) {
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());
    int bucketSize = 5;
    int bucketNum = (maxVal - minVal) / bucketSize + 1;
    vector<vector<int>> buckets(bucketNum);
    for (int i = 0; i < n; ++i) {
      int idx = (nums[i] - minVal) / bucketSize;
      buckets[idx].push_back(nums[i]);
    }
    for (int i = 0; i < bucketNum; ++i) {
      sort(buckets[i].begin(), buckets[i].end());
    }
    int idx = 0;
    for (int i = 0; i < bucketNum; ++i) {
      for (int j = 0; j < buckets[i].size(); ++j) {
        nums[idx++] = buckets[i][j];
      }
    }
  }

  /**
   * @brief radix sort
   *
   * @param nums
   */
  void radixSort(vector<int>& nums) {
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
      countingSortByDigit(nums, exp);
    }
  }

  void countingSortByDigit(vector<int>& nums, int exp) {
    int n = nums.size();
    vector<int> count(10);
    for (int i = 0; i < n; ++i) {
      ++count[(nums[i] / exp) % 10];
    }
    for (int i = 1; i < 10; ++i) {
      count[i] += count[i - 1];
    }
    vector<int> temp(n);
    for (int i = n - 1; i >= 0; --i) {
      temp[--count[(nums[i] / exp) % 10]] = nums[i];
    }
    for (int i = 0; i < n; ++i) {
      nums[i] = temp[i];
    }
  }

  /**
   * @brief shell sort
   *
   * @param nums
   */
  void shellSort(vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < n; ++i) {
        int temp = nums[i];
        int j = i;
        for (; j >= gap && nums[j - gap] > temp; j -= gap) {
          nums[j] = nums[j - gap];
        }
        nums[j] = temp;
      }
    }
  }

  /**
   * @brief comb sort
   *
   * @param nums
   */
  void combSort(vector<int>& nums) {
    int n = nums.size();
    int gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
      if (gap > 1) {
        gap = gap * 10 / 13;
      }
      swapped = false;
      for (int i = 0; i < n - gap; ++i) {
        if (nums[i] > nums[i + gap]) {
          swap(nums[i], nums[i + gap]);
          swapped = true;
        }
      }
    }
  }
};

class BinarySearch {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;
    int m1 = 0, m2 = 0;
    for (int count = 0; count < (m + n) / 2; ++count) {
      m2 = m1;
      if (i != m && j != n) {
        m1 = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
      } else if (i < m) {
        m1 = nums1[i++];
      } else {
        m1 = nums2[j++];
      }
    }
    if ((m + n) % 2 == 1) {
      return static_cast<double>(m1);  // odd
    } else {
      return static_cast<double>(m1 + m2) / 2;  // even
    }
  }
};

int main() {
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  BinarySearch bs;
  double ans = bs.findMedianSortedArrays(nums1, nums2);
  cout << ans << endl;
  return 0;
}
