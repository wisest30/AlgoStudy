class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        return [sorted(enumerate(nums), key = lambda x : x[1][-q[1]:])[q[0] - 1][0] for q in queries]
            
