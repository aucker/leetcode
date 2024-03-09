class Solution:
    def getCommon(self, arr1, arr2) -> int:
        res = -1
        i = 0
        j = 0
        while i < len(arr1) and j < len(arr2):
            if arr1[i] == arr2[j]:
                res = arr1[i]
                break
            elif arr1[i] < arr2[j]:
                i += 1
            else:
                j += 1
        return res