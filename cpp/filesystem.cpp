#include <bits/stdc++.h>
using namespace std;

class FileSystem {
 private:
  string content;
  map<string, FileSystem*> dir;

  FileSystem* f(string path) {
    for (auto& c : path) {
      if (c == '/') c = ' ';
    }

    stringstream ss(path);
    auto p = this;
    while (ss >> path) {
      if (!p->dir.count(path)) {
        p->dir[path] = new FileSystem();
      }
      p = p->dir[path];
    }
    return p;
  }

 public:
  FileSystem() {}

  vector<string> ls(string path) {
    auto p = f(path);
    if (!p->content.empty()) return {path.substr(path.rfind('/') + 1)};

    vector<string> res;
    for (auto& i : p->dir) res.emplace_back(i.first);
    return res;
  }

  void mkdir(string path) { f(path); }

  void addContentToFile(string filePath, string content) {
    auto p = f(filePath);
    p->content += content;
  }

  string readContentFromFile(string filePath) {
    auto p = f(filePath);
    return p->content;
  }
};

struct TrieNode {
  // file content
  string content;
  // child
  vector<TrieNode*> child;
  unordered_map<string, int> hashString;
  bool isfile;
  TrieNode() { isfile = false; }
};

class FS {
 public:
  TrieNode* myTrie;
  FS() { myTrie = new TrieNode(); }

  vector<string> pathReader(string path) {
    vector<string> ans;
    for (int i = 0; i < path.size();) {
      if (path[i] == '/') {
        ans.emplace_back();
        i++;
        while (path[i] != '/' && i < path.size()) {
          ans.back() += path[i];
          i++;
        }
      }
    }
    return ans;
  }

  vector<string> ls(string path) {
    TrieNode* help = myTrie;
    vector<string> lists;
    vector<string> getPath = pathReader(path);

    for (int i = 0; i < getPath.size(); i++) {
      if (getPath[i].size() == 0) {
        for (auto it : help->hashString) {
          lists.push_back(it.first);
          // sort the output
          sort(lists.begin(), lists.end());
        }
        return lists;
      } else {
        if (!help->hashString.count(getPath[i])) {
          return lists;
        } else {
          help = help->child[help->hashString[getPath[i]]];
        }
      }
    }
    if (help->isfile) {
      lists.push_back(getPath[getPath.size() - 1]);
    } else {
      for (auto it : help->hashString) {
        lists.push_back(it.first);
        sort(lists.begin(), lists.end());
      }
    }
    return lists;
  }

  void mkdir(string path) {
    vector<string> getPath = pathReader(path);
    TrieNode* help = myTrie;
    for (int i = 0; i < getPath.size(); i++) {
      if (!help->hashString.count(getPath[i])) {
        help->hashString.insert({getPath[i], help->child.size()});
        help->child.push_back(new TrieNode());
      }
      help = help->child[help->hashString[getPath[i]]];
    }
  }

  void addContentToFile(string filePath, string content) {
    vector<string> getPath = pathReader(filePath);
    TrieNode* help = myTrie;
    for (int i = 0; i < getPath.size(); i++) {
      if (!help->hashString.count(getPath[i])) {
        help->hashString.insert({getPath[i], help->child.size()});
        help->child.push_back(new TrieNode());
      }
      help = help->child[help->hashString[getPath[i]]];
    }
    if (help->isfile) {
      help->content.append(content);
    } else {
      help->content = content;
      help->isfile = true;
    }
    return;
  }

  string readContentFromFile(string filePath) {
    vector<string> getPath = pathReader(filePath);
    TrieNode* help = myTrie;
    for (int i = 0; i < getPath.size(); i++) {
      if (!help->hashString.count(getPath[i])) {
        help->hashString.insert({getPath[i], help->child.size()});
        help->child.push_back(new TrieNode());
      }
      help = help->child[help->hashString[getPath[i]]];
    }
    return help->content;
  }
};