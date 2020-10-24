class Solution:
    def specialArray(self, nums: List[int]) -> int:
        ans = []

        for i in range(len(nums) + 1):
            cnt = 0

            for n in nums:
                if n >= i:
                    cnt += 1

            if i == cnt:
                ans.append(i)

        return ans[0] if len(ans) == 1 else -1