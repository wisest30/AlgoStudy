class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        return itertools.chain(*zip([i for i in nums if i > 0], [i for i in nums if i < 0]))
        
