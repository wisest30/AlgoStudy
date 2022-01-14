class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n, k, ps = len(nums), sum(nums), [0] + list(itertools.accumulate(nums))
        return k - max([ps[i + k] - ps[i] if i + k <= n else k - ps[i] + ps[k - (n - i)] for i in range(n)])
