class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        leng = len(arr)
        count = 0
        prev = arr[0]
        max = 0
        for i in range(leng):
            if (arr[i] == prev):
                count += 1
            else:
                count = 1
                prev = arr[i]

            if count > max:
                max = count
            if max > (leng // 4):
                return prev

        return prev
