class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        res = 0

        i, maxq, minq = 0, deque(), deque()
        for n in nums:
            while maxq and maxq[-1] < n:
                maxq.pop()
            while minq and minq[-1] > n:
                minq.pop()

            maxq.append(n)
            minq.append(n)

            if maxq[0] - minq[0] > limit:
                if nums[i] == minq[0]:
                    minq.popleft()
                if nums[i] == maxq[0]:
                    maxq.popleft()
                i += 1

        return len(nums) - i
