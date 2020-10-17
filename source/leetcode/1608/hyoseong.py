import numpy as np
class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums = np.array(nums)
        for i in range(len(nums) + 1) :
            if i == sum(nums >= i) :
                return i
            
        return -1
