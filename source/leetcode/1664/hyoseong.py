class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        odd = [0]
        even = [0]
        
        for i in range(len(nums)) :
            odd.append(odd[-1])
            even.append(even[-1])
            if i % 2 == 0 :
                even[-1] += nums[i]
            else :
                odd[-1] += nums[i]
        
        ret = 0
        for i in range(len(nums)) :
            o = odd[i] + even[-1] - even[i+1]
            e = even[i] + odd[-1] - odd[i+1]
            if o == e :
                ret += 1
        return ret
