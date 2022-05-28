class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        A = sorted(capacity[i] - rocks[i] for i in range(len(capacity)))
        ret = 0
        for a in A :
            if a <= additionalRocks :
                additionalRocks -= a
                ret += 1
            else :
                break
        
        return ret
