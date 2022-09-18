class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        A = [[] for _ in range(32)]
        n = len(nums)
        for i in range(n) :
            for j in range(32) :
                if nums[i] & (1 << j) : A[j].append(i)
        
        R, x = [], 0
        for num in nums[::-1] :
            x |= num
            R.append(x)
        R.reverse()

        ret = []
        for i in range(n) :
            x = i
            for j in range(32) :
                if R[i] & (1 << j) :
                    p = bisect.bisect_left(A[j], i)
                    x = max(x, A[j][p])
            ret.append(x + 1 - i)
        
        return ret
            