class Solution:
    def totalMoney(self, n: int) -> int:
        res = 0
        weekn = n // 7
        day = n % 7
        money = weekn + 1
        j = 0
        while j < day:
            res += money
            money += 1
            j += 1

        if weekn > 0:
            i = 1
            while i <= weekn:
                res += self.sumSeven(i)
                i += 1

        return res

    def sumSeven(self, s: int) -> int:
        sum = 0
        i = 1
        while i <= 7:
            sum += s
            s += 1
            i += 1
        return sum
