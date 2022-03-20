class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        n = len(floor)
        @lru_cache(None)
        def f(i, r) :
            if i >= n : return 0
            elif floor[i] == '0' : return f(i + 1, r)
            elif r == 0 : return 1 + f(i + 1, r)
            else : return min(1 + f(i + 1, r), f(i + carpetLen, r - 1))
        
        return f(0, numCarpets)
