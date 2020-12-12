class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        A = [0] * (2 * 10 ** 5 + 5)
        for i in range(n // 2) :
            a, b = nums[i], nums[n - 1 - i]
            if a > b :
                a, b = b, a

            left = a + 1
            right = limit + b
            A[left] -= 1
            A[a + b] -= 1
            A[a + b + 1] += 1
            A[right + 1] += 1
        
        ret = cur = n
        for i in range(2 * 10 ** 5 + 5) :
            cur += A[i]
            ret = min(ret, cur)
        return ret
            
