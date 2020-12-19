class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()

        @lru_cache(None)
        def f(subset) :
            if subset == 0 :
                return 0
            
            A = [i for i in range(n) if subset & (1 << i)]
            ret = inf
            for C in combinations(A, n // k) :
                for i in range(len(C) - 1) :
                    if nums[C[i]] == nums[C[i+1]] :
                        break
                else :
                    nxt_subset = subset
                    for i in C :
                        nxt_subset -= 1 << i
                    
                    candi = nums[C[-1]] - nums[C[0]] + f(nxt_subset)
                    ret = min(ret, candi)
            return ret
        
        ret = f((1 << n) - 1)
        if ret == inf :
            ret = -1
        return ret
                    
