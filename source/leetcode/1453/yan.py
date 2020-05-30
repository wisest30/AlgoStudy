class Solution:
     def numPoints(self, A, r):
        res = 1
        for (x1, y1), (x2, y2) in itertools.combinations(A, 2):
            dx, dy = x1 - x2, y1 - y2
            d = math.sqrt(dx ** 2 + dy ** 2)
            if d > 2 * r:
                continue

            q = math.sqrt(r ** 2 - (d / 2) ** 2)
            x0, y0 = (x1 + x2) / 2 + q * dy / d, (y1 + y2) / 2 - q * dx / d
            res = max(res, sum((x0 - x) ** 2 + (y0 - y) ** 2 <= r * r + 0.00001 for x, y in A))
        return res
