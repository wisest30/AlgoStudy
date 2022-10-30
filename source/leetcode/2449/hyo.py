class Solution:
    def makeSimilar(self, nums: List[int], target: List[int]) -> int:
        nums.sort()
        target.sort()
        
        a0, a1 = [x for x in nums if x % 2 == 0], [x for x in nums if x % 2 == 1]
        b0, b1 = [x for x in target if x % 2 == 0], [x for x in target if x % 2 == 1]
        
        return (sum(abs(a0[i] - b0[i]) // 2 for i in range(len(a0))) + sum(abs(a1[i] - b1[i]) // 2 for i in range(len(a1)))) // 2
