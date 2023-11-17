class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        l = nums.size()
        res = 0
        for i in range(l//2):
            res = max(res, nums[i] + nums[l-i-1])
        return res
