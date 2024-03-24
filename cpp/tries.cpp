#include <bits/stdc++.h>
using namespace std;

class Trie1 {
 private:
  vector<Trie1*> children;
  bool isEnd;

  Trie1* searchPrefix(string prefix) {
    Trie1* node = this;
    for (char ch : prefix) {
      ch -= 'a';
      if (node->children[ch] == nullptr) {
        return nullptr;
      }
      node = node->children[ch];
    }
    return node;
  }

 public:
  Trie1() : children(26), isEnd(false) {}

  void insert(string word) {
    Trie1* node = this;
    for (char ch : word) {
      ch -= 'a';
      if (node->children[ch] == nullptr) {
        node->children[ch] = new Trie1();
      }
      node = node->children[ch];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie1* node = this->searchPrefix(word);
    return node != nullptr && node->isEnd;
  }

  bool startWith(string prefix) {
    return this->searchPrefix(prefix) != nullptr;
  }
};

class Trie {
 private:
  bool isEnd;
  Trie* next[26];

 public:
  Trie() {
    isEnd = false;
    memset(next, 0, sizeof(next));
  }

  void insert(string word) {
    Trie* node = this;
    for (char c : word) {
      if (node->next[c - 'a'] == nullptr) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie* node = this;
    for (char c : word) {
      node = node->next[c - 'a'];
      if (node == nullptr) {
        return false;
      }
    }
    return node->isEnd;
  }

  bool startWith(string prefix) {
    Trie* node = this;
    for (char c : prefix) {
      node = node->next[c - 'a'];
      if (node == nullptr) {
        return false;
      }
    }
    return true;
  }
};

struct TrieNode {
  vector<TrieNode*> child;
  bool isEnd;
  TrieNode() {
    this->child = vector<TrieNode*>(26, nullptr);
    this->isEnd = false;
  }
};

class WordDictionary {
 private:
  TrieNode* trie;

  void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c : word) {
      if (node->child[c - 'a'] == nullptr) {
        node->child[c - 'a'] = new TrieNode();
      }
      node = node->child[c - 'a'];
    }
    node->isEnd = true;
  }

 public:
  WordDictionary() { trie = new TrieNode(); }

  void addWord(string word) { insert(trie, word); }

  bool search(string word) { return dfs(word, 0, trie); }

  bool dfs(const string& word, int idx, TrieNode* node) {
    if (idx == word.size()) {
      return node->isEnd;
    }

    char ch = word[idx];
    if (ch >= 'a' && ch <= 'a') {
      TrieNode* child = node->child[ch - 'a'];
      if (child != nullptr && dfs(word, idx + 1, child)) {
        return true;
      }
    } else if (ch == '.') {
      for (int i = 0; i < 26; ++i) {
        TrieNode* child = node->child[i];
        if (child != nullptr && dfs(word, idx + 1, child)) {
          return true;
        }
      }
    }
    return false;
  }
};

struct TrieN {
  string word;
  unordered_map<char, TrieN*> children;
  TrieN() { this->word = ""; }
};

class Solution {
  void insertTrie(TrieN* root, const string& word) {
    TrieN* node = root;
    for (auto c : word) {
      if (!node->children.count(c)) {
        node->children[c] = new TrieN();
      }
      node = node->children[c];
    }
    node->word = word;
  }

 public:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  bool dfs(vector<vector<char>>& board, int x, int y, TrieN* root,
           set<string>& res) {
    char ch = board[x][y];
    if (!root->children.count(ch)) {
      return false;
    }
    root = root->children[ch];
    if (root->word.size() > 0) {
      res.insert(root->word);
    }

    board[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];
      if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
        if (board[nx][ny] != '#') {
          dfs(board, nx, ny, root, res);
        }
      }
    }
    board[x][y] = ch;

    return true;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieN* root = new TrieN();
    set<string> res;
    vector<string> ans;

    for (auto& word : words) {
      insertTrie(root, word);
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        dfs(board, i, j, root, res);
      }
    }

    for (auto& word : res) {
      ans.emplace_back(word);
    }
    return ans;
  }
};