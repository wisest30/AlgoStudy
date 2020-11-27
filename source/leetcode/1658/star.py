class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target_val = sum(nums) - x
        if target_val < 0:
            return -1

        n, lptr, rptr, seg_sum, ans = len(nums), 0, 0, 0, -1
        while lptr < n:
            while rptr < n and seg_sum < target_val:
                seg_sum += nums[rptr]
                rptr += 1
            if seg_sum == target_val:
                ans = max(ans, rptr - lptr)
            seg_sum -= nums[lptr]
            lptr += 1

        return ans if ans == -1 else n - ans
