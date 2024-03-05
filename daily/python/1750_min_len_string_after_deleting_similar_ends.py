class Solution:
    def minimumLength(self, s: str) -> int:
        # this is not a good solution
        # while len(s) > 1 and s[0] == s[-1]:
        #     c = s[0]
        #     while s and s[0] == c:
        #         s = s[1:]
        #     while s and s[-1] == c:
        #         s = s[:-1]
        # return len(s)

        # better solution
        le = 0
        ri = len(s) - 1
        while le < ri and s[le] == s[ri]:
            c = s[le]
            while le <= ri and s[le] == c:
                le += 1
            while le <= ri and s[ri] == c:
                ri -= 1
        return ri - le + 1