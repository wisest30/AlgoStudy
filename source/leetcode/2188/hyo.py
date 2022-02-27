class Solution:
    def minimumFinishTime(self, tires: List[List[int]], changeTime: int, numLaps: int) -> int:
        inf = 10 ** 18
        cost = [inf] * 20
        for t in tires :
            s, r = 0, 1
            for i in range(1, len(cost)) :
                if r > inf :
                    break

                s += t[0] * r
                cost[i] = min(cost[i], changeTime + s)
                r *= t[1]

        @lru_cache(None)
        def recur(i, remain) :
            if remain <= 0 :
                return 0
            elif i == len(cost) :
                return inf
            else :
                return min(cost[i] + recur(i, remain - i), recur(i + 1, remain))

        return recur(1, numLaps) - changeTime
