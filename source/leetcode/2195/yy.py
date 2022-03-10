## TIME LIMIT SOLUTION
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        sorted_nums=sorted(nums)
        counter=k
        result_sum=k * (k + 1) // 2
        k_=k
       
        prev_num=-1
        for i in range(len(nums)):
            if sorted_nums[i]==prev_num:continue
            if sorted_nums[i] <= k:
                result_sum-=sorted_nums[i]
                k_+=1
                while k_ in sorted_nums:
                    k_+=1
                result_sum+=k_
                prev_num=sorted_nums[i]
        return result_sum
        
