class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        m, n = len(pizza), len(pizza[0])
        preSum = [[0] * (n + 1) for _ in range(m + 1)]
        for x in range(m - 1, -1, -1):
            for y in range(n - 1, -1, -1):
                preSum[x][y] = preSum[x][y + 1] + preSum[x + 1][y] - preSum[x + 1][y + 1] + (pizza[x][y] == 'A')

        @lru_cache(None)
        def cut(i, j, k):
            if preSum[i][j] == 0:
                return 0

            if k == 0:
                return 1

            way = sum(cut(x, j, k - 1) for x in range(i + 1, m) if preSum[i][j] - preSum[x][j] > 0)
            way += sum(cut(i, y, k - 1) for y in range(j + 1, n) if preSum[i][j] - preSum[i][y] > 0)
            return way % (10 ** 9 + 7)

        return cut(0, 0, k - 1)
