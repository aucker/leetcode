class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        nums.append(upper + 1) # end point
        ans = []
        last = lower - 1
        for num in nums:
            # compared with last
            if num - last > 2:
                ans.append([last + 1, num - 1])
            elif num - last == 2:
                ans.append([last + 1, last + 1])
            last = num
        return ans
