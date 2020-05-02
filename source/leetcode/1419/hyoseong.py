class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        str_croak = "croak"
        A = [0] * len(str_croak)
        ret = 0
        for c in croakOfFrogs :
            idx = str_croak.index(c)
            A[idx] += 1
            if idx > 0 and A[idx-1] < A[idx] :
                return -1
            
            ret = max(ret, A[0] - A[-1])
        
        if A[0] != A[-1] :
            return -1
        
        return ret
