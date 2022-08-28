class Solution:
    def kSum(self, nums: List[int], k: int) -> int:
        positive_sum = sum(num for num in nums if num > 0)
        nums = sorted([abs(num) for num in nums])[:k]
        
        small_sums = [0]
        for num in nums :
            n = len(small_sums)
            for i in range(n) :
                small_sums.append(small_sums[i] + num)
            
            small_sums = sorted(small_sums)[:k]
            
        return positive_sum - small_sums[k-1]
