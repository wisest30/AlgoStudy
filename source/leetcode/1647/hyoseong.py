class Solution:
    def minDeletions(self, s: str) -> int:
        A = sorted(Counter(s).values(), reverse = True)
        
        ret = 0
        for i in range(1, len(A)) :
            if A[i] >= A[i-1] :
                to = max(0, A[i-1] - 1)
                ret += A[i] - to
                A[i] = to
        
        return ret
                
                
            
        
