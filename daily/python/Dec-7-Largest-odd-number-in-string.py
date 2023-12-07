class Solution:
    def largestOddNumber(self, num: str) -> str:
        pivot = 0
        for i in range(len(num)):
            if int(num[i]) % 2 != 0:
                pivot = i + 1

        res = num[0:pivot]
        return res
