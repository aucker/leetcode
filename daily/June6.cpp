#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  /**
   * LC: 1938: Separate Black/White Balls
   * Time: O(N), Space: O(1)
   * All the '0's will be left, encounter 0, swap with
   * leftside cnt1, so res += cnt1, until this is no 0 left
   *
   * Note this is also the 'Greedy' solution
   */
  long long minimumSteps(string s) {
    long long ans = 0;
    int cnt1 = 0;
    for (char c : s) {
      if (c == '1') {
        cnt1++;
      } else {
        ans += cnt1;
      }
    }
    return ans;
  }

  /**
   * Sorted Merge LCCI [E]
   * 1. from back to begin
   * Time: O(n), Space: O(1)
   */
  void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int k = m + n - 1;
    int i = m - 1, j = n - 1;
    while (k >= 0 && (i >= 0 || j >= 0)) {
      if (i >= 0 && j >= 0 && A[i] >= B[j]) {
        A[k] = A[i];
        i--;
        k--;
      } else if (i >= 0 && j >= 0 && A[i] < B[j]) {
        A[k] = B[j];
        j--;
        k--;
      } else if (i >= 0 && j < 0) {
        A[k] = A[i];
        i--;
        k--;
      } else if (i < 0 && j >= 0) {
        A[k] = A[j];
        j--;
        k--;
      }
    }
  }

  /**
   * Use STD library of std::sort
   * Time: Average: O(nlogn)
   * Both works, but this is easy to implement, no much edge case
   */
  void mergeSTD(vector<int>& A, int m, vector<int>& B, int n) {
    for (int i = 0; i < n; i++) {
      A[m + i] = B[i];
    }
    sort(A.begin(), A.end());
  }

  // Func to perform partitioning
  int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // choosing last element as pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
      // If curr element is LE to pivot
      if (arr[j] <= pivot) {
        i++;                   // increment index of smaller element
        swap(arr[i], arr[j]);  // swap elements
      }
    }
    swap(arr[i + 1], arr[high]);  // swap pivot element w/ ele at i+1
    return (i + 1);
  }

 public:
  // Main func implement quickSorts
  void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
      // pi is partitioning index, arr[p] is now at right place
      int pi = partition(arr, low, high);

      // Separately sort elems before and after partition
      quickSort(arr, low, pi - 1);   // before pi
      quickSort(arr, pi + 1, high);  // after pi
    }
  }

  //  * Print an Array
  void printArray(const vector<int>& arr) {
    for (int i : arr) {
      cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  Solution sln;
  vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();
  cout << "Original array: ";
  sln.printArray(arr);

  sln.quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  sln.printArray(arr);
  return 0;
}
