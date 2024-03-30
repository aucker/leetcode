impl Solution:
	def minOperations(self, nums: List[int], x: int) -> int:
		ret = 0
		heapify(nums)

		while nums[0] < k:
			x = heappop(nums)
			heapreplace(nums, x * 2 + nums[0])
			ret += 1
		return ret