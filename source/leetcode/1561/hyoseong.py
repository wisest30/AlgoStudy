class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        dq = collections.deque(sorted(piles))
        
        ret = 0
        for i in range(len(piles) // 3) :
            dq.pop()
            ret += dq.pop()
            dq.popleft()
        
        return ret
