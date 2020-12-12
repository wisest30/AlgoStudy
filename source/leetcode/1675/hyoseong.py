from heapq import heappush as hpush, heappop as hpop, heapify as hfy
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        q = [-a if a % 2 == 0 else -a * 2 for a in nums]
        hfy(q)
        min_val = -max(q)
        
        ret = -q[0] - min_val
        while q[0] % 2 == 0 :
            nxt = hpop(q) // 2
            hpush(q, nxt)
            min_val = min(min_val, -nxt)
            ret = min(ret, -q[0] - min_val)

        return ret
