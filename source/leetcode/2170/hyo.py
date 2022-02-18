class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        if len(nums) < 2 : return 0
        l0, l1 = Counter(nums[::2]).most_common(2), Counter(nums[1::2]).most_common(2)
        return len(nums) - max([t0[1] + t1[1] if t0[0] != t1[0] else max(t0[1], t1[1]) for t0 in l0 for t1 in l1])
