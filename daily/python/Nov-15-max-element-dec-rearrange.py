import List
class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        res = 0
        for i in arr:
            res = min(res+1, i)

        return res

# we know that the `sort()` algorithm is O(nlogn) time complexity
# so this can be optimized