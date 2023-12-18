class Solution:
    def maxProductDiffs(self, nums: List[int]) -> int:
        min1 = min2 = float('inf')
        max1 = max2 = 0
        for num in nums:
            if num < min1:
                min2 = min1
                min1 = num
            elif num < min2:
                min2 = num
            if num > max1:
                max2 = max1
                max1 = num
            elif num > max2:
                max2 = num
        
        return max1 * max2 - min1 * min2