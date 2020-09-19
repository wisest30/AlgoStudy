class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        ret = sum(cost)
        last = '?'
        max_val = 0
        for i in range(len(s)) :
            if s[i] != last :
                ret -= max_val
                last = s[i]
                max_val = cost[i]
            else :
                max_val = max(max_val, cost[i])
        ret -= max_val
        return ret
