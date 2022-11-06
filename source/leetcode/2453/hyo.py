class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        C = Counter(num % space for num in nums)
        max_cnt = max(C.values())
        s = set()
        for p in C :
            if C[p] == max_cnt :
                s.add(p)
        
        return min(num for num in nums if num % space in s)
        
        
