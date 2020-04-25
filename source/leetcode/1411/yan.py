class Solution:
    def numOfWays(self, n: int) -> int:
        c2, c3 = 6, 6
        for _ in range(1, n):
            c2, c3 = c2 * 2 + c3 * 2, c2 * 2 + c3 * 3
        return (c2 + c3) % (10 ** 9 + 7)           
