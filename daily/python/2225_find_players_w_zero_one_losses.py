from collections import Counter
from typing import List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        players = set(x for match in matches for x in match)
        loss_count = Counter(loser for _, loser in matches)

        winners = sorted(x for x in players if x not in loss_count)
        # winners = sorted(winners)

        one_loss_players = sorted(x for x, c in loss_count.items() if c == 1)
        # one_loss_players = sorted(one_loss_players)

        return [winners, one_loss_players]
