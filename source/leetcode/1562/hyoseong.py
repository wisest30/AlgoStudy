class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        A = [0] * n
        B = [[i, i+1] for i in range(n)]
        
        def get_len(i) :
            return B[i][1] - B[i][0]
        def merge(i, j) :
            left = min(B[i][0], B[j][0])
            right = max(B[i][1], B[j][1])
            
            B[left][1] = right
            B[right-1][0] = left
            
            B[i][0] = B[j][0] = left
            B[i][1] = B[j][1] = right
                        
        ret = -1
        for i in range(n) :
            j = arr[i] - 1
            A[j] = 1
            if j and A[j-1] :
                if get_len(j-1) == m :
                    ret = i
                merge(j, j-1)
            if j + 1 < n and A[j+1] :
                if get_len(j+1) == m :
                    ret = i
                merge(j, j+1)
            if B[j][1] - B[j][0] == m :
                ret = i+1
        return ret
        
                
