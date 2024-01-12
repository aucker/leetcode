#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        string s1 = s.substr(0, len / 2);

        int cnt1 = countVowel(s1);
        int cnt2 = countVowel(s);

        return cnt1 == cnt2 - cnt1;
    }

private:
    int countVowel(string s) {
        int cnt = 0;
        for (char c : s) {
            if (isVow(c)) {
                cnt++;
            }
        }
        return cnt;
    }

    bool isVow(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};