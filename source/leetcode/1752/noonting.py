class Solution:
    def check(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        
        rotate_idx = -1
        before_val = nums[0]
        for idx, num in enumerate(nums):
            if num < before_val:
                rotate_idx = idx
                break
            before_val = num
                
        if rotate_idx == -1:
            return True
        
        result = []
        for i in range(len(nums)):
            result.append(nums[(i + rotate_idx) % len(nums)])
                
        before = result[0]
        ret = True
        for r in result:
            if before > r:
                ret = False
                break
            before = r
        return ret
