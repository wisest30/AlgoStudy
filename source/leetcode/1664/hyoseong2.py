class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        right = sum(nums[::2]) - sum(nums[1::2])
        ret = left = 0
        
        for i, num in enumerate(nums) :
            d = num if i % 2 else -num
            right += d
            if left - right == 0 :
                ret += 1
            left -= d

        return ret
