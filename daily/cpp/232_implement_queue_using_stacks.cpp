#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1, s2;
};