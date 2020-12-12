from heapq import heappush as hpush, heappop as hpop, heapify as hfy
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        A = []
        q = []
        for i in range(n - k + 1) :
            hpush(q, [nums[i], i])
        
        A.append(hpop(q))
        for i in range(n - k + 1, n) :
            while q and q[0][1] < A[-1][1] :
                hpop(q)
            hpush(q, [nums[i], i])
            A.append(hpop(q))
        
        ret = [a[0] for a in A]
        return ret
