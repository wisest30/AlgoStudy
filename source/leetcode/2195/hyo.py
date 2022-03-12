class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        nums = sorted(set(nums)) + [10 ** 10]
        
        ret, prev = 0, 0
        for num in nums :
            cnt = min(k, num - prev - 1)
            ret += cnt * (prev + 1 + prev + cnt) // 2
            k -= cnt
            prev = num
        
        return ret
        
