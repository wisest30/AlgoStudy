class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        n = len(plants)
        i, j = 0, n-1
        a, b = capacityA, capacityB
        ret = 0
        while i <= j :
            if i == j :
                if max(a, b) < plants[i] :
                    ret += 1
                break
            else :
                if a < plants[i] :
                    ret += 1
                    a = capacityA
                if b < plants[j] :
                    ret += 1
                    b = capacityB
                
                a -= plants[i]
                b -= plants[j]
                i += 1
                j -= 1
        return ret
