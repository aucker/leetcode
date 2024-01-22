#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_map;
        for (int i = 0; i < matches.size(); ++i) {
            int lose = matches[i][1];
            lost_map[lose]++;
        }
        vector<int> noLost;
        vector<int> oneLost;
        for (int i = 0; i < matches.size(); ++i) {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if (lost_map.find(winner) == lost_map.end()) {
                noLost.push_back(winner);
                lost_map[winner] = 2;
            }
            if (lost_map[loser] == 1) {
                oneLost.push_back(loser);
            }
        }

        sort(noLost.begin(), noLost.end());
        sort(oneLost.begin(), oneLost.end());
        return {noLost, oneLost};
    }
};