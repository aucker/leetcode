class Solution:
    def numberOfWays(self, corridor):
        # numSeats = 0
        # numPlants = 0
        # dividers = 1
        # mod = int(1e9 + 7)

        # for i in corridor:
        #     if i == 'S':
        #         numSeats += 1
        #     if numSeats == 2 and i == 'P':
        #         numPlants += 1
        #     if numSeats == 3:
        #         dividers *= (numPlants + 1)
        #         dividers %= mod
        #         numSeats = 1
        #         numPlants = 0

        # if numSeats < 2: return 0
        # return dividers

        seat = 0
        prev = 0
        res = 1
        for x in range(len(corridor)):
            if (corridor[x] == 'S'):
                if (seat < 2):
                    seat += 1
                else:
                    seat = 1
                    res *= (x - prev)
                prev = x
        return 0 if seat < 2 else res % int(1e9+7)
