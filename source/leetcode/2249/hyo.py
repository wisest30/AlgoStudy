class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        def cnt(x) :
            A = sorted([[ceil(c[1] - (c[2] ** 2 - (x - c[0]) ** 2) ** 0.5),\
                         int(c[1] + (c[2] ** 2 - (x - c[0]) ** 2) ** 0.5)] for c in circles if c[0] - c[2] <= x <= c[0] + c[2]])
            
            ret, i, y = 0, 0, 0
            while i < len(A) and y <= 200 :
                if A[i][0] <= y <= A[i][1] : ret, y = ret + 1, y + 1
                elif y < A[i][0] : y += 1
                else : i += 1
            
            return ret
            
        return sum(cnt(x) for x in range(201))
