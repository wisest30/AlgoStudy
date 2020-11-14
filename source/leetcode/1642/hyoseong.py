class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        
        def check(m) :
            if m >= n :
                return False

            A = []
            for i in range(m) :
                a = heights[i+1] - heights[i]
                
                if a > 0 :
                    A.append(a)

            A.sort()
            b, l = bricks, ladders
            for a in A :
                if b - a >= 0 :
                    b -= a
                elif l - 1 >= 0 :
                    l -= 1
                else :
                    return False
            return True
            
        l, r = 0, n
        while l + 1 < r :
            m = (l + r) // 2
            if check(m) :
                l = m
            else :
                r = m
        
        return l
