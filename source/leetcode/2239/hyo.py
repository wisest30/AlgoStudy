class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ret = nums[0]
        for num in nums :
            if abs(num) < abs(ret) :
                ret = num
            elif abs(num) == abs(ret) and num > ret :
                ret = num
        return ret