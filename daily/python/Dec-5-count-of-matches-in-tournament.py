class Solution:
    def numberOfMatches(self, n: int) -> int:
        res = 0
        team = n
        while team > 1:
            res += team // 2
            team = team // 2 + team % 2
        return res
