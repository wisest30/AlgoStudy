class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        A = [0] * (n+1)
        for i in range(n) :
            A[i+1] = A[i] + nums[i]
        
        D = dict()
        s = A[-1] - x
        ret = inf
        for i in range(n+1) :
            D[A[i]] = i
            if A[i] - s in D :
                ret = min(ret, n - i + D[A[i] - s])
            
        if ret == inf :
            ret = -1
        return ret
            
