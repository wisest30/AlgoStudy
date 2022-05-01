class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        D = defaultdict(lambda : -float('inf'))
        ret = float('inf')
        for i in range(len(cards)) :
            ret = min(ret, i+1 - D[cards[i]])
            D[cards[i]] = i
        
        return -1 if ret == float('inf') else ret