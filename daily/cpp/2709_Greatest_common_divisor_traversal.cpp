#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canTraverseAllPairs(vector<int>& nums) {
    int numElements = nums.size();
    if (numElements == 1) return true;

    vector<int> disjointSet(numElements);
    vector<int> setSize(numElements, 1);
    unordered_map<int, int> factorFirstOccurence;

    for (int i = 0; i < numElements; ++i) {
      disjointSet[i] = i;
      int num = nums[i];
      int divisor = 2;
      while (divisor * divisor <= num) {
        if (num % divisor == 0) {
          if (factorFirstOccurence.find(divisor) !=
              factorFirstOccurence.end()) {
            unionSets(disjointSet, setSize, i, factorFirstOccurence[divisor]);
          } else {
            factorFirstOccurence[divisor] = i;
          }
          while (num % divisor == 0) {
            num /= divisor;
          }
        }
        divisor++;
      }
      if (num > 1) {
        if (factorFirstOccurence.find(num) != factorFirstOccurence.end()) {
          unionSets(disjointSet, setSize, i, factorFirstOccurence[num]);
        } else {
          factorFirstOccurence[num] = i;
        }
      }
    }
    return setSize[findSetLeader(disjointSet, 0)] == numElements;
  }

 private:
  int findSetLeader(vector<int>& disjointSet, int node) {
    if (disjointSet[node] == node) return node;
    disjointSet[node] = findSetLeader(disjointSet, disjointSet[node]);
    return disjointSet[node];
  }

  void unionSets(vector<int>& disjointSet, vector<int>& setSize, int node1,
                 int node2) {
    int leader1 = findSetLeader(disjointSet, node1);
    int leader2 = findSetLeader(disjointSet, node2);
    if (leader1 == leader2) return;
    if (setSize[leader1] < setSize[leader2]) {
      disjointSet[leader1] = leader2;
      setSize[leader2] += setSize[leader1];
    } else {
      disjointSet[leader2] = leader1;
      setSize[leader1] += setSize[leader2];
    }
  }
};