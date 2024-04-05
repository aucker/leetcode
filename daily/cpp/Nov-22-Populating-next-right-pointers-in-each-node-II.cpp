#include <vector>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    vector<Node*> arr;
    arr.push_back(root);
    if (!root) return root;
    while (arr.size() != 0) {
      for (int i = 0; i < arr.size(); i++) {
        if (i == arr.size() - 1) {
          arr[i]->next = nullptr;
        } else {
          arr[i]->next = arr[i + 1];
        }
      }
      int len = arr.size();  // store it to prevent runtime infinite condition

      for (int i = 0; i < len; i++) {
        if (arr[i]->left) arr.push_back(arr[i]->left);
        if (arr[i]->right) arr.push_back(arr[i]->right);
      }
      arr.erase(arr.begin(), arr.begin() + len);
    }
    return root;
  }
};
