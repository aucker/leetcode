class Solution:
    def hammingWeight(self, n: int) -> int:
        # use bit manipulation
        # n & (n-1) will remove the last 1 bit
        res = 0
        while n:
            n &= n-1
            res += 1
        return res
