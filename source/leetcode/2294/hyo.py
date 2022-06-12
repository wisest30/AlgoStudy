class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        A = []
        ret = 1
        for num in nums :
            if not A or num - A[0] <= k : A.append(num)
            else : A, ret = [num], ret + 1
        
        return ret
        
