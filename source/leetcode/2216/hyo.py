class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        A = []
        for num in nums :
            if len(A) % 2 == 0 or A[-1] != num :
                A.append(num)
        
        return len(nums) - len(A) // 2 * 2
