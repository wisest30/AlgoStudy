class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        n, s0, s1 = len(nums), [], []
        ret = [-1] * n
        for i in range(n) :
            while s1 and nums[s1[-1]] < nums[i] :
                ret[s1.pop()] = nums[i]
            
            add = []
            while s0 and nums[s0[-1]] < nums[i] :
                add.append(s0.pop())
            s1 += add[::-1]
        
            s0.append(i)

        return ret
