class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        bufs = [0] * 26
        buft = [0] * 26
        for i in range(len(s)):
            bufs[ord(s[i]) - ord('a')] += 1
            buft[ord(t[i]) - ord('a')] += 1
        
        if bufs == buft:
            return True
        return False
