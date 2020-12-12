class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ret = 0
        for a in accounts :
            ret = max(ret, sum(a))
        return ret
