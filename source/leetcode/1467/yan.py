class Solution(object):
    def getProbability(self, balls):
        def ways(balls):
            return factorial(sum(balls)) // prod(map(factorial, (x for x in balls if x > 1)))

        def nonZero(a):
            return sum(x > 0 for x in a)

        n = len(balls)
        a, b = [0] * n, [0] * n

        def dfs(i, n):
            if i == len(balls):
                return not n and nonZero(a) == nonZero(b) and ways(a) * ways(b)

            res = 0
            for count in range(min(balls[i] + 1, n + 1)):
                a[i] = count
                b[i] = balls[i] - count
                res += dfs(i + 1, n - count)
            return res

        same = dfs(0, sum(balls) // 2)
        total = ways(balls)
        return same / total
