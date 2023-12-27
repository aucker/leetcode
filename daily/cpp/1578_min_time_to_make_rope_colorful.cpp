#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return calMinCost(n-1, colors, neededTime, dp, 'A', neededTime[n-1]);
    }

private:
    int calMinCost(int i, string& colors, vector<int>& neededTime, vector<int>& memo, char prevColor, int prevTime) {
        if (i < 0) return 0; // base case: beginning of the string
        if (memo[i] != -1) return memo[i]; // memoization, calculated before
        if (colors[i] == prevColor) {
            return memo[i] = calMinCost(i-1, colors, neededTime, memo, colors[i], max(neededTime[i], prevTime)) + min(neededTime[i], prevTime);
        } else {
            return memo[i] = calMinCost(i-1, colors, neededTime, memo, colors[i], neededTime[i]);
        }
    }
};