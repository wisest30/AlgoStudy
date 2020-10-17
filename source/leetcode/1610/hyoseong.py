class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        lx, ly = location
        same = 0
        A = []
        for x, y in points :
            dx = x - lx
            dy = y - ly
            if dx == 0 and dy == 0 :
                same += 1
                continue
            t = math.atan2(dy, dx) * 180 / math.pi
            A.append(t)
            A.append(t + 360)
        A.sort()
        
        ret = same
        j = 0
        for i in range(len(A)) :
            while j < len(A) and A[j] - A[i] <= angle :
                j += 1
            ret = max(ret, j - i + same)
        return ret
