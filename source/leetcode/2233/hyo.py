class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        mod = 10 ** 9 + 7
        nums.sort(reverse = True)
        cnt = 1
        val = nums.pop()
        while k :
            while nums and nums[-1] == val :
                cnt += 1
                nums.pop()
            if cnt <= k :
                k -= cnt
                val += 1
            else :
                break
        
        ret = 1
        for num in nums :
            ret *= num
        
        ret *= val ** (cnt - k) * (val + 1) ** k
        return ret % mod
        
