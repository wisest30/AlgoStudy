class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        A = []
        for row in grid :
            cnt = 0
            for x in row[::-1] :
                if x == 0 : cnt += 1
                else : break
            A.append(cnt)
        
        ret = 0
        for i in range(len(grid)) :
            need_cnt = len(grid[i]) - (i+1)
            if A[i] >= need_cnt : continue
            
            idx = -1
            for j in range(i+1, len(A)) :
                if A[j] >= need_cnt :
                    idx = j
                    break
            else :
                return -1
            
            for j in range(idx, i, -1) :
                A[j], A[j-1] = A[j-1], A[j]
                ret += 1
        return ret
                
            
