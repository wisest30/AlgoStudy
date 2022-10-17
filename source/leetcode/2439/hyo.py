class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        def check(m) :
            cur = 0
            for num in nums[::-1] :
                cur = cur + num - m if num > m else  max(0, cur - (m - num))
            return cur == 0
            
        l, r = -1, max(nums)
        while l + 1 < r :
            m = (l + r) // 2
            if check(m) : r = m
            else : l = m
        
        return r
