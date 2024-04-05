#include <bits/stdc++.h>
using namespace std;

/**
 * @brief  Designing Twitter
 * Twitter object will be instantiated
 * and called as such:
 *
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId, tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId, followeeId);
 * obj->unfollow(followerId, followeeId);
 *
 */

class Tweet {
 public:
  int id, time;
  Tweet* next;
  Tweet(int i, int t) : id(i), time(t), next(nullptr) {}
};

class User {
 public:
  int id;
  unordered_set<int> follows;
  Tweet* tweets;

  User() {}

  User(int i) {
    id = i;
    tweets = nullptr;
    follow(i);
  }

  void follow(int userId) { follows.insert(userId); }

  void unfollow(int userId) { follows.erase(userId); }

  void post(int tweetId, int time) {
    Tweet* cur = tweets;
    tweets = new Tweet(tweetId, time);
    tweets->next = cur;
  }
};

class Twitter {
 public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    // user not found
    if (users.find(userId) == users.end()) {
      users[userId] = User(userId);
    }
    users[userId].post(tweetId, time++);
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> feed;
    if (users.find(userId) == users.end()) {
      return feed;
    }
    unordered_set<int> userIds = users[userId].follows;
    priority_queue<Tweet*, vector<Tweet*>, compare> pq;
    for (int userId : userIds) {
      Tweet* tweets = users[userId].tweets;
      if (tweets) {
        pq.push(tweets);
      }
    }

    int i = 0;
    while (!pq.empty() && i++ < 10) {
      Tweet* tweets = pq.top();
      pq.pop();
      feed.push_back(tweets->id);
      if (tweets->next) {
        pq.push(tweets->next);
      }
    }
    return feed;
  }

  void follow(int followerId, int followeeId) {
    if (users.find(followerId) == users.end()) {
      users[followerId] = User(followerId);
    }
    if (users.find(followeeId) == users.end()) {
      users[followeeId] = User(followeeId);
    }
    users[followerId].follow(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (users.find(followerId) != users.end() && followerId != followeeId) {
      users[followerId].unfollow(followeeId);
    }
  }

 private:
  int time = 0;
  unordered_map<int, User> users;
  struct compare {
    bool operator()(const Tweet* l, const Tweet* r) {
      return l->time < r->time;
    }
  };
};