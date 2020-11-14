class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        
        def check(m) :
            A = sorted([heights[i+1] - heights[i] for i in range(m) if heights[i+1] > heights[i]])
            b = bricks
            for i in range(len(A)) :
                if b >= A[i] :
                    b -= A[i]
                else :
                    return len(A) - i <= ladders
            return True
            
        l, r = 0, n
        while l + 1 < r :
            m = (l + r) // 2
            if check(m) :
                l = m
            else :
                r = m
        
        return l
