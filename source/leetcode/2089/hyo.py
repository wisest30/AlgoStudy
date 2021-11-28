class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        return [i for i, v in enumerate(sorted(nums)) if v == target]
