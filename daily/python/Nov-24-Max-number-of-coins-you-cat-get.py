class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        pile_len = len(piles)
        res = 0
        piles.sort() # sort piles
        piles_slice = piles[pile_len // 3 :]
        for i in range(0, pile_len // 3 * 2, 2):
            res += piles_slice[i]

        return res
