class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        n, ret = len(nums), 0
        for i in range(n) :
            g = nums[i]
            if g == k :
                ret += 1
            for j in range(i + 1, n) :
                g = gcd(g, nums[j])
                if g == k :
                    ret += 1
        
        return ret
