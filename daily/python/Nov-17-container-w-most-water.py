class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        res = 0
        while (left < right):
            if height[left] <= height[right]:
                res = max(res, (right-left)*height[left])
                left = left + 1
            else:
                res = max(res, (right-left)*height[right])
                right = right - 1

        return res
