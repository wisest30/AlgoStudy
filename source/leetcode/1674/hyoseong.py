class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        A = [0] * (2 * 10 ** 5 + 5)
        for i in range(n // 2) :
            a, b = sorted([nums[i], nums[n - 1 - i]])

            A[a + 1] -= 1
            A[a + b] -= 1
            A[a + b + 1] += 1
            A[limit + b + 1] += 1
        
        A[0] += n
        return min(list(accumulate(A)))
            
