class Solution:
    def customSortString(self, order: str, s: str) -> str:
        char_cnt = {char: 0 for char in order}
        for char in s:
            if char in char_cnt:
                char_cnt[char] += 1
        
        result = ""
        for char in order:
            result += char * char_cnt[char]
        
        for char in s:
            if char not in order:
                result += char
        return result