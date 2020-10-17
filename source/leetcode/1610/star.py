class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        lx, ly = location
        cnt = 0
        thetas = []
        for x, y in points:
            if lx == x and ly == y:
                cnt += 1
                continue
            else:
                theta = math.atan2((y - ly),(x - lx))*(180/math.pi)
            thetas.append(theta)
        thetas.sort()
        m = len(thetas)
        thetas = thetas + [theta + 360 for theta in thetas]
        sp = 0
        max_points = 0
        for fp, theta in enumerate(thetas):
            if fp == m:
                 break
            while sp < m and thetas[sp] <= theta + angle:
                sp += 1
            max_points = max(sp - fp, max_points)
        return max_points + cnt