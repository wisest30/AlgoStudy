class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        s = set()
        for i in range(len(nums)) :
            for j in range(i + 1, len(nums) + 1) :
                cnt = sum(1 for k in range(i, j) if nums[k] % p == 0)
                if cnt <= k :
                    s.add(str(nums[i:j]))
        
        return len(s)