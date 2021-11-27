class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        ret = 0
        for i in range(2) :
            s, h = startPos[i], homePos[i]
            cost = rowCosts if i == 0 else colCosts
            ret += sum(cost[min(s, h):max(s, h)+1]) - cost[s]
        return ret
